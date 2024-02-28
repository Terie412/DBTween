// Copyright 2021-2022, DearBing. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DBTweenBase.h"
#include "DBTweenPath.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FHandleFPath, FVector, curPos,FRotator,curRotator);
UCLASS(BlueprintType, Blueprintable)
class DBTWEEN_API UDBTweenPath: public UDBTweenBase
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"),Category = "DBTweenUtil | DBTweenPath")
		static UDBTweenPath* DOPath(FString TweenName,TArray<FVector> Path,float DurTime = 1,EaseType easeType = EaseType::Linear,bool IsLoop = false);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"),Category = "DBTweenUtil | DBTweenPath")
        static UDBTweenPath* DOPathByCurve(FString TweenName,TArray<FVector> Path,float DurTime = 1,UCurveFloat* Curve = nullptr,bool IsLoop = false);

	
	UPROPERTY(BlueprintAssignable)
		FHandleFPath OnFirst;

	UPROPERTY(BlueprintAssignable)
		FHandleFPath OnUpdate;

	UPROPERTY(BlueprintAssignable)
		FHandleFPath OnComplete;

	FVector StartValue;
	FVector CurValue;
	FRotator CurRotator;
	FVector EndValue;
	TArray<FVector> PathValue;

	float TotalLength;
	TArray<float> EachSegmentLength;

	void GetCurrentTimePos(FVector& Current, FRotator& Rotator);

protected:
	virtual void UpdateFunc(float deltaTime) override;
	void CalcLength();
	
};
