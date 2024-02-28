// Copyright 2021-2022, DearBing. All Rights Reserved.


#include "DBTweenVector2D.h"

UDBTweenVector2D* UDBTweenVector2D::DOVector2D(FString TweenName,float DurTime, FVector2D Start, FVector2D End, EaseType easeType,bool IsLoop)
{
	UDBTweenVector2D* result = NewObject<UDBTweenVector2D>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartValue = Start;
	result->EndValue = End;
	result->SetLooping(IsLoop);
	result->CurEasyType = easeType;
	return result;
}

UDBTweenVector2D* UDBTweenVector2D::DOVector2DByCurve(FString TweenName, float DurTime, FVector2D Start, FVector2D End,UCurveFloat* Curve, bool IsLoop)
{
	UDBTweenVector2D* result = NewObject<UDBTweenVector2D>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartValue = Start;
	result->EndValue = End;
	result->SetLooping(IsLoop);
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

void UDBTweenVector2D::UpdateFunc(float deltaTime)
{
	if (Paused)return;
	Super::UpdateFunc(deltaTime);
	if (Finished)
	{
		OnUpdate.Broadcast(EndValue);
		OnComplete.Broadcast(EndValue);
		return;
	}
	if (!isInit)
	{
		isInit = true;
		OnFirst.Broadcast(StartValue);
	}
	FVector2D CurValue = StartValue +  Evaluate() * (EndValue - StartValue);
	OnUpdate.Broadcast(CurValue);
}
