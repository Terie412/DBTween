// Copyright 2021-2022, DearBing. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DBTweenActor.h"
#include "DBTweenCanvasPanelSlot.h"
#include "DBTweenColor.h"
#include "DBTweenFloat.h"
#include "DBTweenPath.h"
#include "DBTweenVector2D.h"
#include "DBTweenVector3D.h"
#include "DBTweenVector4D.h"
#include "DBTweenWidget.h"
#include "DBTweenUtil.generated.h"

/**
 * 
 */
UCLASS()
class DBTWEEN_API UDBTweenUtil : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenActor")
	static UDBTweenActor* DOLocalMoveSync(FString TweenName, float DurTime = 1.f, AActor* Actor = nullptr, FVector End = FVector(100, 100, 100), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenActor")
	static UDBTweenActor* DOLocalMoveByCurveSync(FString TweenName, float DurTime = 1.f, AActor* Actor = nullptr, FVector End = FVector(100, 100, 100), UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenActor")
	static UDBTweenActor* DOLocalRotationSync(FString TweenName, float DurTime = 1.f, AActor* Actor = nullptr, FRotator End = FRotator(0, 90, 0), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenActor")
	static UDBTweenActor* DOLocalRotationByCurveSync(FString TweenName, float DurTime = 1.f, AActor* Actor = nullptr, FRotator End = FRotator(0, 90, 0), UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenActor")
	static UDBTweenActor* DOLocalScaleSync(FString TweenName, float DurTime = 1.f, AActor* Actor = nullptr, FVector End = FVector(2, 2, 2), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenActor")
	static UDBTweenActor* DOLocalScaleByCurveSync(FString TweenName, float DurTime = 1.f, AActor* Actor = nullptr, FVector End = FVector(2, 2, 2), UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenActor")
	static UDBTweenActor* DOMoveSync(FString TweenName, float DurTime = 1.f, AActor* Actor = nullptr, FVector End = FVector(100, 100, 100), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenActor")
	static UDBTweenActor* DOMoveByCurveSync(FString TweenName, float DurTime = 1.f, AActor* Actor = nullptr, FVector End = FVector(100, 100, 100), UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenActor")
	static UDBTweenActor* DORotationSync(FString TweenName, float DurTime = 1.f, AActor* Actor = nullptr, FRotator End = FRotator(0, 90, 0), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenActor")
	static UDBTweenActor* DORotationByCurveSync(FString TweenName, float DurTime = 1.f, AActor* Actor = nullptr, FRotator End = FRotator(0, 90, 0), UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenActor")
	static UDBTweenActor* DOScaleSync(FString TweenName, float DurTime = 1.f, AActor* Actor = nullptr, FVector End = FVector(2, 2, 2), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenActor")
	static UDBTweenActor* DOScaleByCurveSync(FString TweenName, float DurTime = 1.f, AActor* Actor = nullptr, FVector End = FVector(2, 2, 2), UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenColor")
	static UDBTweenColor* DOColorSync(FString TweenName, float DurTime = 1, FLinearColor Start = FLinearColor(0, 0, 0, 1), FLinearColor End = FLinearColor(1, 1, 1, 1), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenColor")
	static UDBTweenColor* DOColorByCurveSync(FString TweenName, float DurTime = 1, FLinearColor Start = FLinearColor(0, 0, 0, 1), FLinearColor End = FLinearColor(1, 1, 1, 1), UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenFloat")
	static UDBTweenFloat* DOFloatSync(FString TweenName, float DurTime = 1, float Start = 0, float End = 1, EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenFloat")
	static UDBTweenFloat* DOFloatByCurveSync(FString TweenName, float DurTime = 1, float Start = 0, float End = 1, UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenPath")
	static UDBTweenPath* DOPathSync(FString TweenName, TArray<FVector> Path, float DurTime = 1, EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenPath")
	static UDBTweenPath* DOPathByCurveSync(FString TweenName, TArray<FVector> Path, float DurTime = 1, UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenVector2D")
	static UDBTweenVector2D* DOVector2DSync(FString TweenName, float DurTime = 1, FVector2D Start = FVector2D(0, 0), FVector2D End = FVector2D(100, 100), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenVector2D")
	static UDBTweenVector2D* DOVector2DByCurveSync(FString TweenName, float DurTime = 1, FVector2D Start = FVector2D(0, 0), FVector2D End = FVector2D(100, 100), UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenVector3D")
	static UDBTweenVector3D* DOVector3DSync(FString TweenName, float DurTime = 1.f, FVector Start = FVector(0, 0, 0), FVector End = FVector(100, 100, 100), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenVector3D")
	static UDBTweenVector3D* DOVector3DByCurveSync(FString TweenName, float DurTime = 1.f, FVector Start = FVector(0, 0, 0), FVector End = FVector(100, 100, 100), UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenVector4D")
	static UDBTweenVector4D* DOVector4DSync(FString TweenName, FVector4 Start, FVector4 End, float DurTime = 1.f, EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenVector4D")
	static UDBTweenVector4D* DOVector4DByCurveSync(FString TweenName, FVector4 Start, FVector4 End, float DurTime = 1.f, UCurveFloat* Curve = nullptr, bool IsLoop = false);
};
