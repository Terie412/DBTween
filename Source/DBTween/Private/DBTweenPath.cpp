// Copyright 2021-2022, DearBing. All Rights Reserved.


#include "DBTweenPath.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"

UDBTweenPath* UDBTweenPath::DOPath(FString TweenName,TArray<FVector> Path, float DurTime,EaseType easeType, bool IsLoop)
{
	if (Path.Num() == 0) return nullptr;
	
	UDBTweenPath* result = NewObject<UDBTweenPath>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->PathValue = Path;
	result->SetLooping(IsLoop);
	result->CalcLength();
	result->EndValue = Path[Path.Num() - 1];
	result->StartValue = Path[0];
	result->CurEasyType = easeType;
	return result;
	
}

UDBTweenPath* UDBTweenPath::DOPathByCurve(FString TweenName, TArray<FVector> Path, float DurTime, UCurveFloat* Curve,bool IsLoop)
{
	if (Path.Num() == 0) return nullptr;
	
	UDBTweenPath* result = NewObject<UDBTweenPath>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->PathValue = Path;
	result->SetLooping(IsLoop);
	result->CalcLength();
	result->EndValue = Path[Path.Num() - 1];
	result->StartValue = Path[0];
	if (Curve == nullptr)
	{
		result->CurEasyType = EaseType::Linear;
	}
	else
	{
		result->FloatCurve = Curve;
	}
	return result;
}

void UDBTweenPath::GetCurrentTimePos(FVector& Current, FRotator& Rotator)
{
	if (PathValue.Num() == 1)
	{
		Current = PathValue[0];
		Rotator = FRotator(0,0,0);
		return;
	}
	if (CurTime >= TotalTime)
	{
		Current = PathValue[PathValue.Num() - 1];
		Rotator = UKismetMathLibrary::FindLookAtRotation(Current, Current + (Current - PathValue[PathValue.Num() - 2]));
		return;
	}
	float CurLength = FMath::Clamp(Evaluate(), 0.f, 1.f)  * TotalLength;
	float PreSegmentLength = 0;
	for (int i = 0; i < EachSegmentLength.Num(); i++)
	{
		if (CurLength < EachSegmentLength[i])
		{
			Current = PathValue[i] + (CurLength - PreSegmentLength) / (EachSegmentLength[i] - PreSegmentLength) *  (PathValue[i + 1] - PathValue[i]);
			Rotator = UKismetMathLibrary::FindLookAtRotation(Current, PathValue[i + 1]);
			return;
		}
		PreSegmentLength = EachSegmentLength[i];
	}
}

void UDBTweenPath::UpdateFunc(float deltaTime)
{
	if (Paused)return;
	Super::UpdateFunc(deltaTime);
	if (Finished)
	{
		GetCurrentTimePos(CurValue, CurRotator);
		OnUpdate.Broadcast(CurValue, CurRotator);
		OnComplete.Broadcast(CurValue, CurRotator);
		return;
	}
	if (!isInit)
	{
		isInit = true;
		GetCurrentTimePos(CurValue, CurRotator);
		OnFirst.Broadcast(CurValue, CurRotator);
	}

	GetCurrentTimePos(CurValue, CurRotator);
	OnUpdate.Broadcast(CurValue, CurRotator);
}

void UDBTweenPath::CalcLength()
{
	for (int32 i=1;i<PathValue.Num();i++)
	{
		TotalLength += FVector::Distance(PathValue[i], PathValue[i - 1]);
		EachSegmentLength.Add(TotalLength);
	}
}

