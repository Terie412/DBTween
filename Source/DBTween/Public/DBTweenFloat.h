// Copyright 2021-2022, DearBing. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DBTweenBase.h"
#include "DBTweenFloat.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHandleFloat, float, curValue);
UCLASS()
class DBTWEEN_API UDBTweenFloat : public UDBTweenBase
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"),Category = "DBTweenUtil | DBTweenFloat")
		static UDBTweenFloat* DOFloat(FString TweenName,float DurTime = 1, float Start = 0, float End = 1, EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenFloat")
		static UDBTweenFloat* DOFloatByCurve(FString TweenName,float DurTime = 1, float Start = 0, float End = 1, UCurveFloat* Curve = nullptr,bool IsLoop = false);

	UPROPERTY(BlueprintAssignable)
		FHandleFloat OnFirst;

	UPROPERTY(BlueprintAssignable)
		FHandleFloat OnUpdate;

	UPROPERTY(BlueprintAssignable)
		FHandleFloat OnComplete;

	float StartValue;
	float EndValue;
protected:
	virtual void UpdateFunc(float deltaTime) override;
};
