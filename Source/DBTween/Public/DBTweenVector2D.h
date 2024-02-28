// Copyright 2021-2022, DearBing. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DBTweenBase.h"
#include "DBTweenVector2D.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHandleVector2D, FVector2D, curValue);

UCLASS()
class DBTWEEN_API UDBTweenVector2D : public UDBTweenBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable,meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenVector2D")
        static UDBTweenVector2D* DOVector2D(FString TweenName,float DurTime = 1, FVector2D Start = FVector2D(0,0), FVector2D End = FVector2D(100,100),EaseType easeType = EaseType::Linear,bool IsLoop = false);

	UFUNCTION(BlueprintCallable,meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenVector2D")
        static UDBTweenVector2D* DOVector2DByCurve(FString TweenName,float DurTime = 1, FVector2D Start = FVector2D(0,0), FVector2D End = FVector2D(100,100),UCurveFloat* Curve = nullptr,bool IsLoop = false);

	UPROPERTY(BlueprintAssignable)
		FHandleVector2D OnFirst;
	
	UPROPERTY(BlueprintAssignable)
	FHandleVector2D OnUpdate;

	UPROPERTY(BlueprintAssignable)
		FHandleVector2D OnComplete;

	FVector2D StartValue;
	FVector2D EndValue;
protected:
	virtual void UpdateFunc(float deltaTime) override;
};
