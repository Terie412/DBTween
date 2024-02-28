// Copyright 2021-2022, DearBing. All Rights Reserved.


#include "DBTweenCanvasPanelSlot.h"

UDBTweenCanvasPanelSlot* UDBTweenCanvasPanelSlot::DOMove(FString TweenName,float DurTime, UCanvasPanelSlot* CanvasPanelSlot, FVector2D End,EaseType easeType, bool IsLoop)
{
	if(!CanvasPanelSlot) return nullptr;
	UDBTweenCanvasPanelSlot* result = NewObject<UDBTweenCanvasPanelSlot>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartValue = CanvasPanelSlot->GetPosition();
	result->EndValue = End;
	result->SetLooping(IsLoop);
	result->Slot = CanvasPanelSlot;
	result->DBTweenCanvasSlotType = EDBTweenCanvasSlotType::E_CanvasSlotPos;
	result->CurEasyType = easeType;
	return result;
}

UDBTweenCanvasPanelSlot* UDBTweenCanvasPanelSlot::DOMoveByCurve(FString TweenName, float DurTime,UCanvasPanelSlot* CanvasPanelSlot, FVector2D End, UCurveFloat* Curve, bool IsLoop)
{
	if(!CanvasPanelSlot) return nullptr;
	UDBTweenCanvasPanelSlot* result = NewObject<UDBTweenCanvasPanelSlot>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartValue = CanvasPanelSlot->GetPosition();
	result->EndValue = End;
	result->SetLooping(IsLoop);
	result->Slot = CanvasPanelSlot;
	result->DBTweenCanvasSlotType = EDBTweenCanvasSlotType::E_CanvasSlotPos;
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

UDBTweenCanvasPanelSlot* UDBTweenCanvasPanelSlot::DOSize(FString TweenName,float DurTime, UCanvasPanelSlot* CanvasPanelSlot, FVector2D End,EaseType easeType, bool IsLoop)
{
	if(!CanvasPanelSlot) return nullptr;
	UDBTweenCanvasPanelSlot* result = NewObject<UDBTweenCanvasPanelSlot>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartValue = CanvasPanelSlot->GetSize();
	result->EndValue = End;
	result->SetLooping(IsLoop);
	result->Slot = CanvasPanelSlot;
	result->DBTweenCanvasSlotType = EDBTweenCanvasSlotType::E_CanvasSlotSize;
	result->CurEasyType = easeType;
	return result;
}

UDBTweenCanvasPanelSlot* UDBTweenCanvasPanelSlot::DOSizeByCurve(FString TweenName, float DurTime,UCanvasPanelSlot* CanvasPanelSlot, FVector2D End, UCurveFloat* Curve, bool IsLoop)
{
	if(!CanvasPanelSlot) return nullptr;
	UDBTweenCanvasPanelSlot* result = NewObject<UDBTweenCanvasPanelSlot>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartValue = CanvasPanelSlot->GetSize();
	result->EndValue = End;
	result->SetLooping(IsLoop);
	result->Slot = CanvasPanelSlot;
	result->DBTweenCanvasSlotType = EDBTweenCanvasSlotType::E_CanvasSlotSize;
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

void UDBTweenCanvasPanelSlot::UpdateFunc(float deltaTime)
{
	if (Paused)return;//
	Super::UpdateFunc(deltaTime);
	if (!Slot || Slot->Parent == nullptr) {
		SetReadyToDestroy();
		return;
	}

	switch (DBTweenCanvasSlotType)
	{
	case E_CanvasSlotPos:
		{
			FVector2D CurValue = StartValue +  Evaluate() * (EndValue - StartValue);
			Slot->SetPosition(CurValue);
		}
		break;
	case E_CanvasSlotSize:
		{
			FVector2D CurValue = StartValue +  Evaluate() * (EndValue - StartValue);
			Slot->SetSize(CurValue);
		}
		break;
	}
	if (!isInit)
	{
		isInit = true;
		OnFirst.Broadcast();
	}
	OnUpdate.Broadcast();
	if (Finished)
	{
		OnComplete.Broadcast();
	}
}
