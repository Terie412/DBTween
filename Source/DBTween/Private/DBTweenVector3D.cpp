// Copyright 2021-2022, DearBing. All Rights Reserved.


#include "DBTweenVector3D.h"

UDBTweenVector3D* UDBTweenVector3D::DOVector3D(FString TweenName,float DurTime, FVector Start, FVector End, EaseType easeType, bool IsLoop)
{
	UDBTweenVector3D* result = NewObject<UDBTweenVector3D>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartValue = Start;
	result->EndValue = End;
	result->SetLooping(IsLoop);
	result->CurEasyType = easeType;
	return result;
}

UDBTweenVector3D* UDBTweenVector3D::DOVector3DByCurve(FString TweenName, float DurTime, FVector Start, FVector End,UCurveFloat* Curve, bool IsLoop)
{
	UDBTweenVector3D* result = NewObject<UDBTweenVector3D>();
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

void UDBTweenVector3D::UpdateFunc(float deltaTime)
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
	FVector CurValue = StartValue +  Evaluate() * (EndValue - StartValue);
	OnUpdate.Broadcast(CurValue);
}
