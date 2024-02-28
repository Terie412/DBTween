// Copyright 2021-2022, DearBing. All Rights Reserved.


#include "DBTweenUpdateManager.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "DBTweenBase.h"

ADBTweenUpdateManager* ADBTweenUpdateManager::Instance = nullptr;

TMap<int, FTickHandle> ADBTweenUpdateManager::CallMap;

TMap<int, FTickHandle> ADBTweenUpdateManager::EnterMap;

TArray<int> ADBTweenUpdateManager::QuitKeys;

int ADBTweenUpdateManager::KeyCount = 0;
// Sets default values
ADBTweenUpdateManager::ADBTweenUpdateManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SetTickableWhenPaused(true);
}

int ADBTweenUpdateManager::RegisterUpdateCall(FTickHandle call)
{
	UWorld* w = GWorld->GetWorld();
	if (w == nullptr)return 0;
	if (w->WorldType == EWorldType::Game || w->WorldType == EWorldType::PIE)
	{
		if (Instance == nullptr)
		{
			//DBTweenDic.Empty();//Clear All TweenBase
			Instance = GWorld->GetWorld()->SpawnActor<ADBTweenUpdateManager>(FVector::ZeroVector, FRotator(0, 0, 0));
		}
	}
	if (Instance != nullptr)
	{
		KeyCount++;
		EnterMap.Add(KeyCount, call);
		return KeyCount;
	}
	return 0;
}

void ADBTweenUpdateManager::RemoveUpdateCall(int key)
{
	Instance->QuitKeys.Add(key);
}

// Called when the game starts or when spawned
void ADBTweenUpdateManager::BeginPlay()
{
	Super::BeginPlay();
	Instance = this;//避免多个产生的 冲突
	CallMap.Empty();
	QuitKeys.Empty();
	EnterMap.Empty();
	KeyCount = 0;
}

void ADBTweenUpdateManager::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Instance = nullptr;
}

// Called every frame
void ADBTweenUpdateManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	for (TPair<int32, FTickHandle>& element : EnterMap)
	{
		CallMap.Add(element.Key, element.Value);
	}
	EnterMap.Empty();
	for (int i = 0; i < QuitKeys.Num(); i++)
	{
		CallMap.Remove(QuitKeys[i]);
	}
	QuitKeys.Empty();
	for (TPair<int32, FTickHandle>& element : CallMap)
	{
		element.Value.ExecuteIfBound(DeltaTime);
	}
}

