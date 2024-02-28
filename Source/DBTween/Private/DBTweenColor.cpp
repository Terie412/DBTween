// Copyright 2021-2022, DearBing. All Rights Reserved.


#include "DBTweenColor.h"

UDBTweenColor* UDBTweenColor::DOColor(FString TweenName,float DurTime, FLinearColor Start, FLinearColor End, EaseType easeType, bool IsLoop)
{
	UDBTweenColor* result = NewObject<UDBTweenColor>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartValue = Start;
	result->EndValue = End;
	result->SetLooping(IsLoop);
	result->CurEasyType = easeType;
	return result;
}

UDBTweenColor* UDBTweenColor::DOColorByCurve(FString TweenName, float DurTime, FLinearColor Start, FLinearColor End,UCurveFloat* Curve, bool IsLoop)
{
	
	UDBTweenColor* result = NewObject<UDBTweenColor>();
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

void UDBTweenColor::UpdateFunc(float deltaTime)
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
	FLinearColor CurValue = StartValue +  Evaluate() * (EndValue - StartValue);
	OnUpdate.Broadcast(CurValue);
}
