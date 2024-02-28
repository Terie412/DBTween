// Copyright 2021-2022, DearBing. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "DBTweenUpdateManager.generated.h"

class UDBTweenBase;

DECLARE_DELEGATE_OneParam(FTickHandle,float);

UCLASS()
class DBTWEEN_API ADBTweenUpdateManager : public AActor
{
	GENERATED_BODY()
public:
	friend class UDBTweenBase;

	UPROPERTY(VisibleAnywhere, Category = "DBTweenUpdateManager")
	TMap<FString, UDBTweenBase*> DBTweenDic;

	// Sets default values for this actor's properties
	ADBTweenUpdateManager();
	static int RegisterUpdateCall(FTickHandle call);


	static void RemoveUpdateCall(int key);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason);
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	static ADBTweenUpdateManager* Instance;

private:
	static TMap<int, FTickHandle> CallMap;
	static TMap<int, FTickHandle> EnterMap;
	static TArray<int> QuitKeys;
	static int KeyCount;
};
