// Copyright Omnigames Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DBTweenBase.h"
#include "DBTweenSceneComponent.generated.h"

enum EDBTweenSceneComponentType
{
	E_SceneComponentRelativeLocation,
	E_SceneComponentRelativeRotation,
	E_SceneComponentRelativeScale,
	E_SceneComponentLocation,
	E_SceneComponentRotation,
	E_SceneComponentScale
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHandleSceneComponent);

UCLASS()
class DBTWEEN_API UDBTweenSceneComponent : public UDBTweenBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenSceneComponent")
	static UDBTweenSceneComponent* DOLocalMove(FString TweenName, float DurTime = 1.f, USceneComponent* component = nullptr, FVector End = FVector(100, 100, 100), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenSceneComponent")
	static UDBTweenSceneComponent* DOLocalMoveByCurve(FString TweenName, float DurTime = 1.f, USceneComponent* component = nullptr, FVector End = FVector(100, 100, 100), UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenSceneComponent")
	static UDBTweenSceneComponent* DOLocalRotation(FString TweenName, float DurTime = 1.f, USceneComponent* component = nullptr, FRotator End = FRotator(0, 90, 0), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenSceneComponent")
	static UDBTweenSceneComponent* DOLocalRotationByCurve(FString TweenName, float DurTime = 1.f, USceneComponent* component = nullptr, FRotator End = FRotator(0, 90, 0), UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenSceneComponent")
	static UDBTweenSceneComponent* DOLocalScale(FString TweenName, float DurTime = 1.f, USceneComponent* component = nullptr, FVector End = FVector(2, 2, 2), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenSceneComponent")
	static UDBTweenSceneComponent* DOLocalScaleByCurve(FString TweenName, float DurTime = 1.f, USceneComponent* component = nullptr, FVector End = FVector(2, 2, 2), UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenSceneComponent")
	static UDBTweenSceneComponent* DOMove(FString TweenName, float DurTime = 1.f, USceneComponent* component = nullptr, FVector End = FVector(100, 100, 100), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenSceneComponent")
	static UDBTweenSceneComponent* DOMoveByCurve(FString TweenName, float DurTime = 1.f, USceneComponent* component = nullptr, FVector End = FVector(100, 100, 100), UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenSceneComponent")
	static UDBTweenSceneComponent* DORotation(FString TweenName, float DurTime = 1.f, USceneComponent* component = nullptr, FRotator End = FRotator(0, 90, 0), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenSceneComponent")
	static UDBTweenSceneComponent* DORotationByCurve(FString TweenName, float DurTime = 1.f, USceneComponent* component = nullptr, FRotator End = FRotator(0, 90, 0), UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenSceneComponent")
	static UDBTweenSceneComponent* DOScale(FString TweenName, float DurTime = 1.f, USceneComponent* component = nullptr, FVector End = FVector(2, 2, 2), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenSceneComponent")
	static UDBTweenSceneComponent* DOScaleByCurve(FString TweenName, float DurTime = 1.f, USceneComponent* component = nullptr, FVector End = FVector(2, 2, 2), UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UPROPERTY(BlueprintAssignable)
	FHandleSceneComponent OnFirst;

	UPROPERTY(BlueprintAssignable)
	FHandleSceneComponent OnUpdate;

	UPROPERTY(BlueprintAssignable)
	FHandleSceneComponent OnComplete;

	FVector StartLocValue;
	FVector EndLocValue;

	FRotator StartRotValue;
	FRotator EndRotValue;

	FVector StartScaleValue;
	FVector EndScaleValue;

protected:
	virtual void UpdateFunc(float deltaTime) override;
	USceneComponent* component = nullptr;
	EDBTweenSceneComponentType DBTweenSceneComponentType = E_SceneComponentLocation;
};
