// Copyright 2021-2022, DearBing. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DBTweenBase.h"
#include "Components/CanvasPanelSlot.h"
#include "DBTweenCanvasPanelSlot.generated.h"

/**
 * 
 */
enum EDBTweenCanvasSlotType
{
    E_CanvasSlotPos,
    E_CanvasSlotSize
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHandleCanvasPanel);

UCLASS()
class DBTWEEN_API UDBTweenCanvasPanelSlot : public UDBTweenBase
{
	GENERATED_BODY()
	
	public:

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenCanvasPanelSlot")
        static UDBTweenCanvasPanelSlot* DOMove(FString TweenName,float DurTime = 1, UCanvasPanelSlot* CanvasPanelSlot = nullptr, FVector2D End = FVector2D(100,100), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenCanvasPanelSlot")
            static UDBTweenCanvasPanelSlot* DOMoveByCurve(FString TweenName,float DurTime = 1, UCanvasPanelSlot* CanvasPanelSlot = nullptr, FVector2D End = FVector2D(100,100), UCurveFloat* Curve = nullptr, bool IsLoop = false);
	
	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenCanvasPanelSlot")
        static UDBTweenCanvasPanelSlot* DOSize(FString TweenName,float DurTime = 1, UCanvasPanelSlot* CanvasPanelSlot = nullptr, FVector2D End = FVector2D(100,100), EaseType easeType = EaseType::Linear, bool IsLoop = false);

	UFUNCTION(BlueprintCallable, meta = (BlueprintInternalUseOnly = "true"), Category = "DBTweenUtil | DBTweenCanvasPanelSlot")
        static UDBTweenCanvasPanelSlot* DOSizeByCurve(FString TweenName,float DurTime = 1, UCanvasPanelSlot* CanvasPanelSlot = nullptr, FVector2D End = FVector2D(100,100), UCurveFloat* Curve = nullptr, bool IsLoop = false);

	UPROPERTY(BlueprintAssignable)
	FHandleCanvasPanel OnFirst;

	UPROPERTY(BlueprintAssignable)
	FHandleCanvasPanel OnUpdate;

	UPROPERTY(BlueprintAssignable)
	FHandleCanvasPanel OnComplete;

	FVector2D StartValue;
	FVector2D EndValue;
	
protected:
	virtual void UpdateFunc(float deltaTime) override;
	UCanvasPanelSlot* Slot = nullptr;
	EDBTweenCanvasSlotType DBTweenCanvasSlotType = EDBTweenCanvasSlotType::E_CanvasSlotPos;
};
