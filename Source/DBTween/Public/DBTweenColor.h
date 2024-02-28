// Copyright 2021-2022, DearBing. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DBTweenBase.h"
#include "DBTweenColor.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHandleColor, FLinearColor, curValue);

UCLASS()
class DBTWEEN_API UDBTweenColor : public UDBTweenBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"),Category = "DBTweenUtil | DBTweenColor")
        static UDBTweenColor* DOColor(FString TweenName,float DurTime = 1, FLinearColor Start = FLinearColor(0,0,0,1), FLinearColor End = FLinearColor(1,1,1,1),EaseType easeType = EaseType::Linear,bool IsLoop = false);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"),Category = "DBTweenUtil | DBTweenColor")
        static UDBTweenColor* DOColorByCurve(FString TweenName,float DurTime = 1, FLinearColor Start = FLinearColor(0,0,0,1), FLinearColor End = FLinearColor(1,1,1,1),UCurveFloat* Curve = nullptr,bool IsLoop = false);

	UPROPERTY(BlueprintAssignable)
		FHandleColor OnFirst;

	UPROPERTY(BlueprintAssignable)
		FHandleColor OnUpdate;

	UPROPERTY(BlueprintAssignable)
	FHandleColor OnComplete;

	FLinearColor StartValue;
	FLinearColor EndValue;
protected:
	virtual void UpdateFunc(float deltaTime) override;
};
