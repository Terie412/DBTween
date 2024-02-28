// Copyright 2021-2022, DearBing. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DBTweenBase.h"
#include "DBTweenVector4D.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHandleVector4D, FVector4, curValue);

UCLASS()
class DBTWEEN_API UDBTweenVector4D : public UDBTweenBase
{
	GENERATED_BODY()


public:

	UFUNCTION(BlueprintCallable,meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenVector4D")
        static UDBTweenVector4D* DOVector4D(FString TweenName,FVector4 Start, FVector4 End, float DurTime = 1.f,EaseType easeType = EaseType::Linear,bool IsLoop = false);

	UFUNCTION(BlueprintCallable,meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenVector4D")
        static UDBTweenVector4D* DOVector4DByCurve(FString TweenName,FVector4 Start, FVector4 End, float DurTime = 1.f,UCurveFloat* Curve = nullptr,bool IsLoop = false);
	
	UPROPERTY(BlueprintAssignable)
		FHandleVector4D OnFirst;

	UPROPERTY(BlueprintAssignable)
	FHandleVector4D OnUpdate;

	UPROPERTY(BlueprintAssignable)
		FHandleVector4D OnComplete;

	FVector4 StartValue;
	FVector4 EndValue;
protected:
	virtual void UpdateFunc(float deltaTime) override;

	
};
