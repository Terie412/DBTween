// Copyright 2021-2022, DearBing. All Rights Reserved.


#include "DBTweenWidget.h"

#include "Kismet/KismetMathLibrary.h"


UDBTweenWidget* UDBTweenWidget::DOLocalMove(FString TweenName,float DurTime, UWidget* UI, FVector2D End, EaseType easeType, bool IsLoop)
{
	if(!UI) return nullptr;
	UDBTweenWidget* result = NewObject<UDBTweenWidget>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartTranslationValue = UI->RenderTransform.Translation;
	result->EndTranslationValue = End;
	result->SetLooping(IsLoop);
	result->Widget = UI;
	result->DBTweenWidgetType = EDBTweenWidgetType::E_WidgetTranslation;
	result->CurEasyType = easeType;
	return result;
}

UDBTweenWidget* UDBTweenWidget::DOLocalMoveByCurve(FString TweenName, float DurTime, UWidget* UI, FVector2D End,UCurveFloat* Curve, bool IsLoop)
{
	if(!UI) return nullptr;
	UDBTweenWidget* result = NewObject<UDBTweenWidget>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartTranslationValue = UI->RenderTransform.Translation;
	result->EndTranslationValue = End;
	result->SetLooping(IsLoop);
	result->Widget = UI;
	result->DBTweenWidgetType = EDBTweenWidgetType::E_WidgetTranslation;
	if (Curve == nullptr)
	{
		result->CurEasyType = EaseType::Linear;
	}
	else
	{
		result->FloatCurve = Curve;
	}
	return result;
}

UDBTweenWidget* UDBTweenWidget::DOLocalAngle(FString TweenName,float DurTime, UWidget* UI, float End, EaseType easeType, bool IsLoop)
{
	if(!UI) return nullptr;
	UDBTweenWidget* result = NewObject<UDBTweenWidget>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartAngleValue = UI->GetRenderTransformAngle();
	result->EndAngleValue = End;
	result->SetLooping(IsLoop);
	result->Widget = UI;
	result->DBTweenWidgetType = EDBTweenWidgetType::E_WidgetAngle;
	result->CurEasyType = easeType;
	return result;
}

UDBTweenWidget* UDBTweenWidget::DOLocalAngleByCurve(FString TweenName, float DurTime, UWidget* UI, float End,UCurveFloat* Curve, bool IsLoop)
{
	if(!UI) return nullptr;
	UDBTweenWidget* result = NewObject<UDBTweenWidget>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartAngleValue = UI->GetRenderTransformAngle();
	result->EndAngleValue = End;
	result->SetLooping(IsLoop);
	result->Widget = UI;
	result->DBTweenWidgetType = EDBTweenWidgetType::E_WidgetAngle;
	if (Curve == nullptr)
	{
		result->CurEasyType = EaseType::Linear;
	}
	else
	{
		result->FloatCurve = Curve;
	}
	return result;
}

UDBTweenWidget* UDBTweenWidget::DOLocalScale(FString TweenName,float DurTime, UWidget* UI, FVector2D End, EaseType easeType, bool IsLoop)
{
	if(!UI) return nullptr;
	UDBTweenWidget* result = NewObject<UDBTweenWidget>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartScaleValue = UI->RenderTransform.Scale;
	result->EndScaleValue = End;
	result->SetLooping(IsLoop);
	result->Widget = UI;
	result->DBTweenWidgetType = EDBTweenWidgetType::E_WidgetScale;
	result->CurEasyType = easeType;
	return result;
}

UDBTweenWidget* UDBTweenWidget::DOLocalScaleByCurve(FString TweenName, float DurTime, UWidget* UI, FVector2D End,UCurveFloat* Curve, bool IsLoop)
{
	if(!UI) return nullptr;
	UDBTweenWidget* result = NewObject<UDBTweenWidget>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartScaleValue = UI->RenderTransform.Scale;
	result->EndScaleValue = End;
	result->SetLooping(IsLoop);
	result->Widget = UI;
	result->DBTweenWidgetType = EDBTweenWidgetType::E_WidgetScale;
	if (Curve == nullptr)
	{
		result->CurEasyType = EaseType::Linear;
	}
	else
	{
		result->FloatCurve = Curve;
	}
	return result;
}

UDBTweenWidget* UDBTweenWidget::DOFade(FString TweenName,float DurTime, UWidget* UI, float End, EaseType easeType, bool IsLoop)
{
	if(!UI) return nullptr;
	UDBTweenWidget* result = NewObject<UDBTweenWidget>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartOpacityValue = UI->GetRenderOpacity();
	result->EndOpacityValue = End;
	result->SetLooping(IsLoop);
	result->Widget = UI;
	result->DBTweenWidgetType = EDBTweenWidgetType::E_WidgetFade;
	result->CurEasyType = easeType;
	return result;
}

UDBTweenWidget* UDBTweenWidget::DOFadeByCurve(FString TweenName, float DurTime, UWidget* UI, float End, UCurveFloat* Curve,bool IsLoop)
{
	if(!UI) return nullptr;
	UDBTweenWidget* result = NewObject<UDBTweenWidget>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartOpacityValue = UI->GetRenderOpacity();
	result->EndOpacityValue = End;
	result->SetLooping(IsLoop);
	result->Widget = UI;
	result->DBTweenWidgetType = EDBTweenWidgetType::E_WidgetFade;
	if (Curve == nullptr)
	{
		result->CurEasyType = EaseType::Linear;
	}
	else
	{
		result->FloatCurve = Curve;
	}
	return result;
}

void UDBTweenWidget::UpdateFunc(float deltaTime)
{
	if (Paused)return;
	Super::UpdateFunc(deltaTime);
	if (!Widget || Widget->GetParent()== nullptr) {
		SetReadyToDestroy();
		return;
	}
	if (!isInit)
	{
		isInit = true;
		OnFirst.Broadcast();
	}
	switch (DBTweenWidgetType)
	{
		case E_WidgetTranslation:
			{
				FVector2D CurValue = StartTranslationValue +  Evaluate() * (EndTranslationValue - StartTranslationValue);
				Widget->SetRenderTranslation(CurValue);
			}
			break;
		case E_WidgetAngle:
			{
				float CurValue = StartAngleValue +  Evaluate() * (EndAngleValue - StartAngleValue);
				Widget->SetRenderTransformAngle(CurValue);
			}
			break;
		case E_WidgetScale:
			{
				FVector2D CurValue = StartScaleValue +  Evaluate() * (EndScaleValue - StartScaleValue);
				Widget->SetRenderScale(CurValue);
			}
			break;
		case E_WidgetFade:
			{
				float CurValue = StartOpacityValue +  Evaluate() * (EndOpacityValue - StartOpacityValue);
				Widget->SetRenderOpacity(CurValue);
			}
			break;
	}
	
	OnUpdate.Broadcast();
	if (Finished)
	{
		OnComplete.Broadcast();
	}

}

