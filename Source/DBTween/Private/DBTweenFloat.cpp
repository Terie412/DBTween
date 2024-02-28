// Copyright 2021-2022, DearBing. All Rights Reserved.


#include "DBTweenFloat.h"

UDBTweenFloat* UDBTweenFloat::DOFloat(FString TweenName,float DurTime, float Start, float End, EaseType easeType, bool IsLoop)
{
	UDBTweenFloat* result = NewObject<UDBTweenFloat>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartValue = Start;
	result->EndValue = End;
	result->SetLooping(IsLoop);
	result->CurEasyType = easeType;
	return result;
}

UDBTweenFloat* UDBTweenFloat::DOFloatByCurve(FString TweenName,float DurTime /*= 1*/, float Start /*= 0*/, float End /*= 1*/, UCurveFloat* Curve, bool IsLoop /*= false*/)
{
	UDBTweenFloat* result = NewObject<UDBTweenFloat>();
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

void UDBTweenFloat::UpdateFunc(float deltaTime)
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
	float CurValue = StartValue +  Evaluate() * (EndValue - StartValue);
	OnUpdate.Broadcast(CurValue);
}
