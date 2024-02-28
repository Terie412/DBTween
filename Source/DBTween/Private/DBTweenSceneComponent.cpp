// Copyright Omnigames Games, Inc. All Rights Reserved.


#include "DBTweenSceneComponent.h"
#include "GameFramework/Actor.h"

UDBTweenSceneComponent* UDBTweenSceneComponent::DOLocalMove(FString TweenName, float DurTime, USceneComponent* component, FVector End, EaseType easeType, bool IsLoop)
{
	if(!component) return nullptr;
	UDBTweenSceneComponent* result = NewObject<UDBTweenSceneComponent>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartLocValue = component->GetRelativeLocation();
	result->EndLocValue = End;
	result->SetLooping(IsLoop);
	result->component = component;
	result->DBTweenSceneComponentType = E_SceneComponentRelativeLocation;
	result->CurEasyType = easeType;
	return result;
}

UDBTweenSceneComponent* UDBTweenSceneComponent::DOLocalMoveByCurve(FString TweenName, float DurTime, USceneComponent* component, FVector End,UCurveFloat* Curve, bool IsLoop)
{
	if(!component) return nullptr;
	UDBTweenSceneComponent* result = NewObject<UDBTweenSceneComponent>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartLocValue = component->GetRelativeLocation();
	result->EndLocValue = End;
	result->SetLooping(IsLoop);
	result->component = component;
	result->DBTweenSceneComponentType = E_SceneComponentRelativeLocation;
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

UDBTweenSceneComponent* UDBTweenSceneComponent::DOLocalRotation(FString TweenName,float DurTime, USceneComponent* component, FRotator End, EaseType easeType, bool IsLoop)
{
	if(!component) return nullptr;
	UDBTweenSceneComponent* result = NewObject<UDBTweenSceneComponent>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartRotValue = component->GetRelativeRotation();
	result->EndRotValue = End;
	result->SetLooping(IsLoop);
	result->component = component;
	result->DBTweenSceneComponentType = E_SceneComponentRelativeRotation;
	result->CurEasyType = easeType;
	return result;
}

UDBTweenSceneComponent* UDBTweenSceneComponent::DOLocalRotationByCurve(FString TweenName, float DurTime, USceneComponent* component, FRotator End,UCurveFloat* Curve, bool IsLoop)
{
	if(!component) return nullptr;
	UDBTweenSceneComponent* result = NewObject<UDBTweenSceneComponent>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartRotValue = component->GetRelativeRotation();
	result->EndRotValue = End;
	result->SetLooping(IsLoop);
	result->component = component;
	result->DBTweenSceneComponentType = E_SceneComponentRelativeRotation;
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

UDBTweenSceneComponent* UDBTweenSceneComponent::DOLocalScale(FString TweenName,float DurTime, USceneComponent* component, FVector End, EaseType easeType, bool IsLoop)
{
	if(!component) return nullptr;
	UDBTweenSceneComponent* result = NewObject<UDBTweenSceneComponent>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartScaleValue = component->GetRelativeScale3D();
	result->EndScaleValue = End;
	result->SetLooping(IsLoop);
	result->component = component;
	result->DBTweenSceneComponentType = E_SceneComponentRelativeScale;
	result->CurEasyType = easeType;
	return result;
}

UDBTweenSceneComponent* UDBTweenSceneComponent::DOLocalScaleByCurve(FString TweenName, float DurTime, USceneComponent* component, FVector End,UCurveFloat* Curve, bool IsLoop)
{
	if(!component) return nullptr;
	UDBTweenSceneComponent* result = NewObject<UDBTweenSceneComponent>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartScaleValue = component->GetRelativeScale3D();
	result->EndScaleValue = End;
	result->SetLooping(IsLoop);
	result->component = component;
	result->DBTweenSceneComponentType = E_SceneComponentRelativeScale;
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

UDBTweenSceneComponent* UDBTweenSceneComponent::DOMove(FString TweenName,float DurTime, USceneComponent* component, FVector End, EaseType easeType, bool IsLoop)
{
	if(!component) return nullptr;
	UDBTweenSceneComponent* result = NewObject<UDBTweenSceneComponent>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartLocValue = component->GetComponentLocation();
	result->EndLocValue = End;
	result->SetLooping(IsLoop);
	result->component = component;
	result->DBTweenSceneComponentType = E_SceneComponentLocation;
	result->CurEasyType = easeType;
	return result;
}

UDBTweenSceneComponent* UDBTweenSceneComponent::DOMoveByCurve(FString TweenName, float DurTime, USceneComponent* component, FVector End,UCurveFloat* Curve, bool IsLoop)
{
	if(!component) return nullptr;
	UDBTweenSceneComponent* result = NewObject<UDBTweenSceneComponent>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartLocValue = component->GetComponentLocation();
	result->EndLocValue = End;
	result->SetLooping(IsLoop);
	result->component = component;
	result->DBTweenSceneComponentType = E_SceneComponentLocation;
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

UDBTweenSceneComponent* UDBTweenSceneComponent::DORotation(FString TweenName,float DurTime, USceneComponent* component, FRotator End, EaseType easeType, bool IsLoop)
{
	if(!component) return nullptr;
	UDBTweenSceneComponent* result = NewObject<UDBTweenSceneComponent>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartRotValue = component->GetComponentRotation();
	result->EndRotValue = End;
	result->SetLooping(IsLoop);
	result->component = component;
	result->DBTweenSceneComponentType = E_SceneComponentRotation;
	result->CurEasyType = easeType;
	return result;
}

UDBTweenSceneComponent* UDBTweenSceneComponent::DORotationByCurve(FString TweenName, float DurTime, USceneComponent* component, FRotator End,UCurveFloat* Curve, bool IsLoop)
{
	if(!component) return nullptr;
	UDBTweenSceneComponent* result = NewObject<UDBTweenSceneComponent>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartRotValue = component->GetComponentRotation();
	result->EndRotValue = End;
	result->SetLooping(IsLoop);
	result->component = component;
	result->DBTweenSceneComponentType = E_SceneComponentRotation;
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

UDBTweenSceneComponent* UDBTweenSceneComponent::DOScale(FString TweenName,float DurTime, USceneComponent* component, FVector End, EaseType easeType, bool IsLoop)
{
	if(!component) return nullptr;
	UDBTweenSceneComponent* result = NewObject<UDBTweenSceneComponent>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartScaleValue = component->GetComponentScale();
	result->EndScaleValue = End;
	result->SetLooping(IsLoop);
	result->component = component;
	result->DBTweenSceneComponentType = E_SceneComponentScale;
	result->CurEasyType = easeType;
	return result;
}

UDBTweenSceneComponent* UDBTweenSceneComponent::DOScaleByCurve(FString TweenName, float DurTime, USceneComponent* component, FVector End,UCurveFloat* Curve, bool IsLoop)
{
	if(!component) return nullptr;
	UDBTweenSceneComponent* result = NewObject<UDBTweenSceneComponent>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartScaleValue = component->GetComponentScale();
	result->EndScaleValue = End;
	result->SetLooping(IsLoop);
	result->component = component;
	result->DBTweenSceneComponentType = E_SceneComponentScale;
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

void UDBTweenSceneComponent::UpdateFunc(float deltaTime)
{
	if (Paused)return;//
	Super::UpdateFunc(deltaTime);
	if (!component || !IsValid(component)) {
		SetReadyToDestroy();
		return;
	}
	if (!isInit)
	{
		isInit = true;
		OnFirst.Broadcast();
	}

	switch (DBTweenSceneComponentType)
	{
		case E_SceneComponentRelativeLocation:
			{
				FVector CurValue = StartLocValue +  Evaluate() * (EndLocValue - StartLocValue);
				if (component)
				{
					component->SetRelativeLocation(CurValue);
				}
			}
			break;

		case E_SceneComponentLocation:
			{
				FVector CurValue = StartLocValue +  Evaluate() * (EndLocValue - StartLocValue);
				if (component)
				{
					component->SetWorldLocation(CurValue);
				}
			}
			break;
		case E_SceneComponentRelativeRotation:
			{
				FRotator CurValue = StartRotValue + Evaluate() * (EndRotValue - StartRotValue);
				if (component)
				{
					component->SetRelativeRotation(CurValue);
				}
			}
			break;
		case E_SceneComponentRotation:
			{
				FRotator CurValue = StartRotValue + Evaluate() * (EndRotValue - StartRotValue);
				if (component)
				{
					component->SetWorldRotation(CurValue);
				}
			}
			break;
		case E_SceneComponentRelativeScale:
			{
				FVector CurValue = StartScaleValue +  Evaluate() * (EndScaleValue - StartScaleValue);
				if (component)
				{
					component->SetRelativeScale3D(CurValue);
				}
			}
			break;
		case E_SceneComponentScale:
			{
				FVector CurValue = StartScaleValue +  Evaluate() * (EndScaleValue - StartScaleValue);
				if (component)
				{
					component->SetWorldScale3D(CurValue);
				}
			}
			break;
					
	}
	OnUpdate.Broadcast();
	if (Finished)
	{
		OnComplete.Broadcast();
		return;
	}
}
