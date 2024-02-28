// Copyright 2021-2022, DearBing. All Rights Reserved.


#include "DBTweenUtil2.h"

UDBTweenCanvasPanelSlot* UDBTweenUtil2::DOMoveSync(FString TweenName,float DurTime /*= 1*/, UCanvasPanelSlot* CanvasPanelSlot /*= nullptr*/, FVector2D End /*= FVector2D(100, 100)*/, EaseType easeType /*= EaseType::Linear*/, bool IsLoop /*= false*/)
{
	return UDBTweenCanvasPanelSlot::DOMove(TweenName,DurTime, CanvasPanelSlot, End, easeType, IsLoop);
}

UDBTweenCanvasPanelSlot* UDBTweenUtil2::DOMoveByCurveSync(FString TweenName, float DurTime,UCanvasPanelSlot* CanvasPanelSlot, FVector2D End, UCurveFloat* Curve, bool IsLoop)
{
	return UDBTweenCanvasPanelSlot::DOMoveByCurve(TweenName,DurTime, CanvasPanelSlot, End, Curve, IsLoop);
}

UDBTweenCanvasPanelSlot* UDBTweenUtil2::DOSizeSync(FString TweenName,float DurTime /*= 1*/, UCanvasPanelSlot* CanvasPanelSlot /*= nullptr*/, FVector2D End /*= FVector2D(100, 100)*/, EaseType easeType /*= EaseType::Linear*/, bool IsLoop /*= false*/)
{
	return UDBTweenCanvasPanelSlot::DOSize(TweenName,DurTime, CanvasPanelSlot, End, easeType, IsLoop);
}

UDBTweenCanvasPanelSlot* UDBTweenUtil2::DOSizeByCurveSync(FString TweenName, float DurTime,UCanvasPanelSlot* CanvasPanelSlot, FVector2D End, UCurveFloat* Curve, bool IsLoop)
{
	return UDBTweenCanvasPanelSlot::DOSizeByCurve(TweenName,DurTime, CanvasPanelSlot, End, Curve, IsLoop);
}

UDBTweenWidget* UDBTweenUtil2::DOLocalMoveSync(FString TweenName,float DurTime /*= 1*/, UWidget* UI /*= nullptr*/, FVector2D End /*= FVector2D(100, 100)*/, EaseType easeType /*= EaseType::Linear*/, bool IsLoop /*= false*/)
{
	return UDBTweenWidget::DOLocalMove(TweenName,DurTime, UI, End, easeType, IsLoop);
}

UDBTweenWidget* UDBTweenUtil2::DOLocalMoveByCurveSync(FString TweenName, float DurTime, UWidget* UI, FVector2D End,UCurveFloat* Curve, bool IsLoop)
{
	return UDBTweenWidget::DOLocalMoveByCurve(TweenName,DurTime, UI, End, Curve, IsLoop);
}

UDBTweenWidget* UDBTweenUtil2::DOLocalAngleSync(FString TweenName,float DurTime /*= 1*/, UWidget* UI /*= nullptr*/, float End /*= 90*/, EaseType easeType /*= EaseType::Linear*/, bool IsLoop /*= false*/)
{
	return UDBTweenWidget::DOLocalAngle(TweenName,DurTime, UI, End, easeType, IsLoop);
}

UDBTweenWidget* UDBTweenUtil2::DOLocalAngleByCurveSync(FString TweenName, float DurTime, UWidget* UI, float End,UCurveFloat* Curve, bool IsLoop)
{
	return UDBTweenWidget::DOLocalAngleByCurve(TweenName,DurTime, UI, End, Curve, IsLoop);
}

UDBTweenWidget* UDBTweenUtil2::DOLocalScaleSync(FString TweenName,float DurTime /*= 1*/, UWidget* UI /*= nullptr*/, FVector2D End /*= FVector2D(2, 2)*/, EaseType easeType /*= EaseType::Linear*/, bool IsLoop /*= false*/)
{
	return UDBTweenWidget::DOLocalScale(TweenName,DurTime, UI, End, easeType, IsLoop);
}

UDBTweenWidget* UDBTweenUtil2::DOLocalScaleByCurveSync(FString TweenName, float DurTime, UWidget* UI, FVector2D End,UCurveFloat* Curve, bool IsLoop)
{
	return UDBTweenWidget::DOLocalScaleByCurve(TweenName,DurTime, UI, End, Curve, IsLoop);
}

UDBTweenWidget* UDBTweenUtil2::DOFadeSync(FString TweenName,float DurTime /*= 1*/, UWidget* UI /*= nullptr*/, float End /*= 1*/, EaseType easeType /*= EaseType::Linear*/, bool IsLoop /*= false*/)
{
	return UDBTweenWidget::DOFade(TweenName,DurTime, UI, End, easeType, IsLoop);
}

UDBTweenWidget* UDBTweenUtil2::DOFadeByCurveSync(FString TweenName, float DurTime, UWidget* UI, float End,UCurveFloat* Curve, bool IsLoop)
{
	return UDBTweenWidget::DOFadeByCurve(TweenName,DurTime, UI, End, Curve, IsLoop);
}
