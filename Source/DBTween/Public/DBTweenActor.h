// Copyright 2021-2022, DearBing. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DBTweenBase.h"
#include "DBTweenActor.generated.h"

/**
 * 
 */
enum EDBTweenActorType
{
	E_ActorRelativeLocation,
    E_ActorRelativeRotation,
    E_ActorRelativeScale,
	E_ActorLocation,
	E_ActorRotation,
	E_ActorScale
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHandleActor);

UCLASS()
class DBTWEEN_API UDBTweenActor : public UDBTweenBase
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"),Category = "DBTweenUtil | DBTweenActor")
		static UDBTweenActor* DOLocalMove(FString TweenName, float DurTime = 1.f, AActor* Actor = nullptr, FVector End = FVector(100,100,100), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"),Category = "DBTweenUtil | DBTweenActor")
        static UDBTweenActor* DOLocalMoveByCurve(FString TweenName, float DurTime = 1.f, AActor* Actor = nullptr, FVector End = FVector(100,100,100), UCurveFloat* Curve = nullptr, bool IsLoop = false);
	
	UFUNCTION(BlueprintCallable,meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenActor")
        static UDBTweenActor* DOLocalRotation(FString TweenName,float DurTime = 1.f, AActor* Actor = nullptr, FRotator End = FRotator(0,90	,0), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable,meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenActor")
        static UDBTweenActor* DOLocalRotationByCurve(FString TweenName,float DurTime = 1.f, AActor* Actor = nullptr, FRotator End = FRotator(0,90	,0), UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable,meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenActor")
        static UDBTweenActor* DOLocalScale(FString TweenName,float DurTime = 1.f, AActor* Actor = nullptr, FVector End = FVector(2,2,2), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable,meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenActor")
        static UDBTweenActor* DOLocalScaleByCurve(FString TweenName,float DurTime = 1.f, AActor* Actor = nullptr, FVector End = FVector(2,2,2),  UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"),Category = "DBTweenUtil | DBTweenActor")
        static UDBTweenActor* DOMove(FString TweenName,float DurTime = 1.f, AActor* Actor = nullptr, FVector End = FVector(100,100,100), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"),Category = "DBTweenUtil | DBTweenActor")
            static UDBTweenActor* DOMoveByCurve(FString TweenName,float DurTime = 1.f, AActor* Actor = nullptr, FVector End = FVector(100,100,100), UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable,meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenActor")
        static UDBTweenActor* DORotation(FString TweenName,float DurTime = 1.f, AActor* Actor = nullptr, FRotator End = FRotator(0,90	,0), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable,meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenActor")
        static UDBTweenActor* DORotationByCurve(FString TweenName,float DurTime = 1.f, AActor* Actor = nullptr, FRotator End = FRotator(0,90	,0), UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable,meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenActor")
        static UDBTweenActor* DOScale(FString TweenName,float DurTime = 1.f, AActor* Actor = nullptr, FVector End = FVector(2,2,2), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable,meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenActor")
        static UDBTweenActor* DOScaleByCurve(FString TweenName,float DurTime = 1.f, AActor* Actor = nullptr, FVector End = FVector(2,2,2), UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UPROPERTY(BlueprintAssignable)
		FHandleActor OnFirst;

	UPROPERTY(BlueprintAssignable)
		FHandleActor OnUpdate;

	UPROPERTY(BlueprintAssignable)
		FHandleActor OnComplete;

	FVector StartLocValue;
	FVector EndLocValue;

	FRotator StartRotValue;
	FRotator EndRotValue;

	FVector StartScaleValue;
	FVector EndScaleValue;

protected:
	virtual void UpdateFunc(float deltaTime) override;
	AActor* Actor = nullptr;
	EDBTweenActorType DBTweenActorType = EDBTweenActorType::E_ActorLocation;
};
