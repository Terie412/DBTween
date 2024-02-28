// Copyright 2021-2022, DearBing. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DBTweenBase.h"
#include "Components/Widget.h"
#include "DBTweenWidget.generated.h"

/**
 * 
 */

enum EDBTweenWidgetType
{
    E_WidgetTranslation,
    E_WidgetAngle,
    E_WidgetScale,
	E_WidgetFade
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHandleWidget);

UCLASS()
class DBTWEEN_API UDBTweenWidget : public UDBTweenBase
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenWidget")
        static UDBTweenWidget* DOLocalMove(FString TweenName,float DurTime = 1, UWidget* UI = nullptr, FVector2D End = FVector2D(100,100), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenWidget")
        static UDBTweenWidget* DOLocalMoveByCurve(FString TweenName,float DurTime = 1, UWidget* UI = nullptr, FVector2D End = FVector2D(100,100), UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"),Category = "DBTweenUtil | DBTweenWidget")
		static UDBTweenWidget* DOLocalAngle(FString TweenName,float DurTime = 1, UWidget* UI = nullptr, float End = 90, EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"),Category = "DBTweenUtil | DBTweenWidget")
        static UDBTweenWidget* DOLocalAngleByCurve(FString TweenName,float DurTime = 1, UWidget* UI = nullptr, float End = 90,  UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable,meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenWidget")
        static UDBTweenWidget* DOLocalScale(FString TweenName,float DurTime = 1, UWidget* UI = nullptr, FVector2D End = FVector2D(2,2), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable,meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenWidget")
        static UDBTweenWidget* DOLocalScaleByCurve(FString TweenName,float DurTime = 1, UWidget* UI = nullptr, FVector2D End = FVector2D(2,2),  UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UFUNCTION(BlueprintCallable,meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenWidget")
        static UDBTweenWidget* DOFade(FString TweenName,float DurTime = 1, UWidget* UI = nullptr, float End = 1, EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable,meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenWidget")
        static UDBTweenWidget* DOFadeByCurve(FString TweenName,float DurTime = 1, UWidget* UI = nullptr, float End = 1,  UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UPROPERTY(BlueprintAssignable)
		FHandleWidget OnFirst;

	UPROPERTY(BlueprintAssignable)
		FHandleWidget OnUpdate;

	UPROPERTY(BlueprintAssignable)
	FHandleWidget OnComplete;

	FVector2D StartTranslationValue;
	FVector2D EndTranslationValue;

	float StartAngleValue;
	float EndAngleValue;

	FVector2D StartScaleValue;
	FVector2D EndScaleValue;

	float StartOpacityValue;
	float EndOpacityValue;

protected:
	virtual void UpdateFunc(float deltaTime) override;
	UWidget* Widget = nullptr;
	EDBTweenWidgetType DBTweenWidgetType = EDBTweenWidgetType::E_WidgetTranslation;
};
