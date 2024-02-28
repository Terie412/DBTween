// Copyright 2021-2022, DearBing. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DBTweenSceneComponent.h"
#include "DBTweenCanvasPanelSlot.h"
#include "DBTweenUtil3.generated.h"

UCLASS()
class DBTWEEN_API UDBTweenUtil3 : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenSceneComponent")
	static UDBTweenSceneComponent* DOLocalMoveSync(FString TweenName, float DurTime = 1.f, USceneComponent* component = nullptr, FVector End = FVector(100, 100, 100), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenSceneComponent")
	static UDBTweenSceneComponent* DOLocalMoveByCurveSync(FString TweenName, float DurTime = 1.f, USceneComponent* component = nullptr, FVector End = FVector(100, 100, 100), UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenSceneComponent")
	static UDBTweenSceneComponent* DOLocalRotationSync(FString TweenName, float DurTime = 1.f, USceneComponent* component = nullptr, FRotator End = FRotator(0, 90, 0), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenSceneComponent")
	static UDBTweenSceneComponent* DOLocalRotationByCurveSync(FString TweenName, float DurTime = 1.f, USceneComponent* component = nullptr, FRotator End = FRotator(0, 90, 0), UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenSceneComponent")
	static UDBTweenSceneComponent* DOLocalScaleSync(FString TweenName, float DurTime = 1.f, USceneComponent* component = nullptr, FVector End = FVector(2, 2, 2), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenSceneComponent")
	static UDBTweenSceneComponent* DOLocalScaleByCurveSync(FString TweenName, float DurTime = 1.f, USceneComponent* component = nullptr, FVector End = FVector(2, 2, 2), UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenSceneComponent")
	static UDBTweenSceneComponent* DOMoveSync(FString TweenName, float DurTime = 1.f, USceneComponent* component = nullptr, FVector End = FVector(100, 100, 100), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenSceneComponent")
	static UDBTweenSceneComponent* DOMoveByCurveSync(FString TweenName, float DurTime = 1.f, USceneComponent* component = nullptr, FVector End = FVector(100, 100, 100), UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenSceneComponent")
	static UDBTweenSceneComponent* DORotationSync(FString TweenName, float DurTime = 1.f, USceneComponent* component = nullptr, FRotator End = FRotator(0, 90, 0), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenSceneComponent")
	static UDBTweenSceneComponent* DORotationByCurveSync(FString TweenName, float DurTime = 1.f, USceneComponent* component = nullptr, FRotator End = FRotator(0, 90, 0), UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenSceneComponent")
	static UDBTweenSceneComponent* DOScaleSync(FString TweenName, float DurTime = 1.f, USceneComponent* component = nullptr, FVector End = FVector(2, 2, 2), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenSceneComponent")
	static UDBTweenSceneComponent* DOScaleByCurveSync(FString TweenName, float DurTime = 1.f, USceneComponent* component = nullptr, FVector End = FVector(2, 2, 2), UCurveFloat* Curve = nullptr, bool IsLoop = false);
};
