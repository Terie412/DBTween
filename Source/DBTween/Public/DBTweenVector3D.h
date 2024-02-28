// Copyright 2021-2022, DearBing. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DBTweenBase.h"
#include "DBTweenVector3D.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FHandleVector3D, FVector, curValue);

UCLASS()
class DBTWEEN_API UDBTweenVector3D : public UDBTweenBase
{
	GENERATED_BODY()

	public:
	
	UFUNCTION(BlueprintCallable,meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenVector3D")
	static UDBTweenVector3D* DOVector3D(FString TweenName,float DurTime = 1.f, FVector Start = FVector(0,0,0), FVector End = FVector(100,100,100), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable,meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenVector3D")
    static UDBTweenVector3D* DOVector3DByCurve(FString TweenName,float DurTime = 1.f, FVector Start = FVector(0,0,0), FVector End = FVector(100,100,100), UCurveFloat* Curve = nullptr, bool IsLoop = false);
	
	UPROPERTY(BlueprintAssignable)
		FHandleVector3D OnFirst;

	UPROPERTY(BlueprintAssignable)
	FHandleVector3D OnUpdate;

	UPROPERTY(BlueprintAssignable)
		FHandleVector3D OnComplete;

	FVector StartValue;
	FVector EndValue;
	protected:
	virtual void UpdateFunc(float deltaTime) override;
	
};
