// Copyright 2021-2022, DearBing. All Rights Reserved.


#include "DBTweenRotator.h"

UDBTweenFRotator* UDBTweenFRotator::DORotator(FString TweenName, FRotator Start, FRotator End, float DurTime, EaseType easeType, bool IsLoop)
{
	UDBTweenFRotator* result = NewObject<UDBTweenFRotator>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartValue = Start;
	result->EndValue = End;
	result->SetLooping(IsLoop);
	result->CurEasyType = easeType;
	return result;
}

UDBTweenFRotator* UDBTweenFRotator::DORotatorByCurve(FString TweenName,  FRotator Start, FRotator End, float DurTime, UCurveFloat* Curve, bool IsLoop)
{
	UDBTweenFRotator* result = NewObject<UDBTweenFRotator>();
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

void UDBTweenFRotator::UpdateFunc(float deltaTime)
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
	FRotator CurValue = StartValue +  Evaluate() * (EndValue - StartValue);
	OnUpdate.Broadcast(CurValue);
}
