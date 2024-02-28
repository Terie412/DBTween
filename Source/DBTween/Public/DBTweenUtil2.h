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
#include "DBTweenUtil2.generated.h"

/**
 * 
 */
UCLASS()
class DBTWEEN_API UDBTweenUtil2 : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenCanvasPanelSlot")
		static UDBTweenCanvasPanelSlot* DOMoveSync(FString TweenName,float DurTime = 1, UCanvasPanelSlot* CanvasPanelSlot = nullptr, FVector2D End = FVector2D(100, 100), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenCanvasPanelSlot")
        static UDBTweenCanvasPanelSlot* DOMoveByCurveSync(FString TweenName,float DurTime = 1, UCanvasPanelSlot* CanvasPanelSlot = nullptr, FVector2D End = FVector2D(100, 100),  UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenCanvasPanelSlot")
		static UDBTweenCanvasPanelSlot* DOSizeSync(FString TweenName,float DurTime = 1, UCanvasPanelSlot* CanvasPanelSlot = nullptr, FVector2D End = FVector2D(100, 100), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenCanvasPanelSlot")
        static UDBTweenCanvasPanelSlot* DOSizeByCurveSync(FString TweenName,float DurTime = 1, UCanvasPanelSlot* CanvasPanelSlot = nullptr, FVector2D End = FVector2D(100, 100),  UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenWidget")
		static UDBTweenWidget* DOLocalMoveSync(FString TweenName,float DurTime = 1, UWidget* UI = nullptr, FVector2D End = FVector2D(100, 100), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenWidget")
		static UDBTweenWidget* DOLocalMoveByCurveSync(FString TweenName,float DurTime = 1, UWidget* UI = nullptr, FVector2D End = FVector2D(100, 100),  UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenWidget")
		static UDBTweenWidget* DOLocalAngleSync(FString TweenName,float DurTime = 1, UWidget* UI = nullptr, float End = 90, EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenWidget")
        static UDBTweenWidget* DOLocalAngleByCurveSync(FString TweenName,float DurTime = 1, UWidget* UI = nullptr, float End = 90,  UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenWidget")
		static UDBTweenWidget* DOLocalScaleSync(FString TweenName,float DurTime = 1, UWidget* UI = nullptr, FVector2D End = FVector2D(2, 2), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenWidget")
        static UDBTweenWidget* DOLocalScaleByCurveSync(FString TweenName,float DurTime = 1, UWidget* UI = nullptr, FVector2D End = FVector2D(2, 2),  UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenWidget")
		static UDBTweenWidget* DOFadeSync(FString TweenName,float DurTime = 1, UWidget* UI = nullptr, float End = 1, EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | DBTweenWidget")
        static UDBTweenWidget* DOFadeByCurveSync(FString TweenName,float DurTime = 1, UWidget* UI = nullptr, float End = 1, UCurveFloat* Curve = nullptr, bool IsLoop = false);
};
