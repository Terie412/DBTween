// Copyright 2021-2022, DearBing. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DBTweenBase.h"
#include "DBTweenRotator.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHandleFRotator, FRotator, curValue);

UCLASS()
class DBTWEEN_API UDBTweenFRotator : public UDBTweenBase
{
	GENERATED_BODY()


public:

	UFUNCTION(BlueprintCallable,meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenRotator")
        static UDBTweenFRotator* DORotator(FString TweenName,FRotator Start, FRotator End, float DurTime = 1.f,EaseType easeType = EaseType::Linear,bool IsLoop = false);

	UFUNCTION(BlueprintCallable,meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenRotator")
        static UDBTweenFRotator* DORotatorByCurve(FString TweenName,FRotator Start, FRotator End, float DurTime = 1.f,UCurveFloat* Curve = nullptr,bool IsLoop = false);
	
	UPROPERTY(BlueprintAssignable)
		FHandleFRotator OnFirst;

	UPROPERTY(BlueprintAssignable)
		FHandleFRotator OnUpdate;

	UPROPERTY(BlueprintAssignable)
		FHandleFRotator OnComplete;

	FRotator StartValue;
	FRotator EndValue;
protected:
	virtual void UpdateFunc(float deltaTime) override;

	
};
