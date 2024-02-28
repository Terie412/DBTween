// Copyright 2021-2022, DearBing. All Rights Reserved.


#include "DBTweenVector4D.h"

UDBTweenVector4D* UDBTweenVector4D::DOVector4D(FString TweenName,FVector4 Start, FVector4 End,float DurTime, EaseType easeType, bool IsLoop)
{
	UDBTweenVector4D* result = NewObject<UDBTweenVector4D>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartValue = Start;
	result->EndValue = End;
	result->SetLooping(IsLoop);
	result->CurEasyType = easeType;
	return result;
}

UDBTweenVector4D* UDBTweenVector4D::DOVector4DByCurve(FString TweenName, FVector4 Start, FVector4 End, float DurTime,UCurveFloat* Curve, bool IsLoop)
{
	UDBTweenVector4D* result = NewObject<UDBTweenVector4D>();
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


void UDBTweenVector4D::UpdateFunc(float deltaTime)
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
	FVector4 CurValue = StartValue +  Evaluate() * (EndValue - StartValue);
	OnUpdate.Broadcast(CurValue);
}
