// Copyright 2021-2022, DearBing. All Rights Reserved.


#include "DBTweenActor.h"

#include "GameFramework/Actor.h"

UDBTweenActor* UDBTweenActor::DOLocalMove(FString TweenName, float DurTime, AActor* Actor, FVector End, EaseType easeType, bool IsLoop)
{
	if(!Actor) return nullptr;
	UDBTweenActor* result = NewObject<UDBTweenActor>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartLocValue = Actor->GetRootComponent()->GetRelativeLocation();
	result->EndLocValue = End;
	result->SetLooping(IsLoop);
	result->Actor = Actor;
	result->DBTweenActorType = EDBTweenActorType::E_ActorRelativeLocation;
	result->CurEasyType = easeType;
	return result;
}

UDBTweenActor* UDBTweenActor::DOLocalMoveByCurve(FString TweenName, float DurTime, AActor* Actor, FVector End,UCurveFloat* Curve, bool IsLoop)
{
	if(!Actor) return nullptr;
	UDBTweenActor* result = NewObject<UDBTweenActor>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartLocValue = Actor->GetRootComponent()->GetRelativeLocation();
	result->EndLocValue = End;
	result->SetLooping(IsLoop);
	result->Actor = Actor;
	result->DBTweenActorType = EDBTweenActorType::E_ActorRelativeLocation;
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

UDBTweenActor* UDBTweenActor::DOLocalRotation(FString TweenName,float DurTime, AActor* Actor, FRotator End, EaseType easeType, bool IsLoop)
{
	if(!Actor) return nullptr;
	UDBTweenActor* result = NewObject<UDBTweenActor>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartRotValue = Actor->GetRootComponent()->GetRelativeRotation();
	result->EndRotValue = End;
	result->SetLooping(IsLoop);
	result->Actor = Actor;
	result->DBTweenActorType = EDBTweenActorType::E_ActorRelativeRotation;
	result->CurEasyType = easeType;
	return result;
}

UDBTweenActor* UDBTweenActor::DOLocalRotationByCurve(FString TweenName, float DurTime, AActor* Actor, FRotator End,UCurveFloat* Curve, bool IsLoop)
{
	if(!Actor) return nullptr;
	UDBTweenActor* result = NewObject<UDBTweenActor>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartRotValue = Actor->GetRootComponent()->GetRelativeRotation();
	result->EndRotValue = End;
	result->SetLooping(IsLoop);
	result->Actor = Actor;
	result->DBTweenActorType = EDBTweenActorType::E_ActorRelativeRotation;
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

UDBTweenActor* UDBTweenActor::DOLocalScale(FString TweenName,float DurTime, AActor* Actor, FVector End, EaseType easeType, bool IsLoop)
{
	if(!Actor) return nullptr;
	UDBTweenActor* result = NewObject<UDBTweenActor>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartScaleValue = Actor->GetActorRelativeScale3D();
	result->EndScaleValue = End;
	result->SetLooping(IsLoop);
	result->Actor = Actor;
	result->DBTweenActorType = EDBTweenActorType::E_ActorRelativeScale;
	result->CurEasyType = easeType;
	return result;
}

UDBTweenActor* UDBTweenActor::DOLocalScaleByCurve(FString TweenName, float DurTime, AActor* Actor, FVector End,UCurveFloat* Curve, bool IsLoop)
{
	if(!Actor) return nullptr;
	UDBTweenActor* result = NewObject<UDBTweenActor>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartScaleValue = Actor->GetActorRelativeScale3D();
	result->EndScaleValue = End;
	result->SetLooping(IsLoop);
	result->Actor = Actor;
	result->DBTweenActorType = EDBTweenActorType::E_ActorRelativeScale;
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

UDBTweenActor* UDBTweenActor::DOMove(FString TweenName,float DurTime, AActor* Actor, FVector End, EaseType easeType, bool IsLoop)
{
	if(!Actor) return nullptr;
	UDBTweenActor* result = NewObject<UDBTweenActor>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartLocValue = Actor->GetActorLocation();
	result->EndLocValue = End;
	result->SetLooping(IsLoop);
	result->Actor = Actor;
	result->DBTweenActorType = EDBTweenActorType::E_ActorLocation;
	result->CurEasyType = easeType;
	return result;
}

UDBTweenActor* UDBTweenActor::DOMoveByCurve(FString TweenName, float DurTime, AActor* Actor, FVector End,UCurveFloat* Curve, bool IsLoop)
{
	if(!Actor) return nullptr;
	UDBTweenActor* result = NewObject<UDBTweenActor>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartLocValue = Actor->GetActorLocation();
	result->EndLocValue = End;
	result->SetLooping(IsLoop);
	result->Actor = Actor;
	result->DBTweenActorType = EDBTweenActorType::E_ActorLocation;
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

UDBTweenActor* UDBTweenActor::DORotation(FString TweenName,float DurTime, AActor* Actor, FRotator End, EaseType easeType, bool IsLoop)
{
	if(!Actor) return nullptr;
	UDBTweenActor* result = NewObject<UDBTweenActor>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartRotValue = Actor->GetActorRotation();
	result->EndRotValue = End;
	result->SetLooping(IsLoop);
	result->Actor = Actor;
	result->DBTweenActorType = EDBTweenActorType::E_ActorRotation;
	result->CurEasyType = easeType;
	return result;
}

UDBTweenActor* UDBTweenActor::DORotationByCurve(FString TweenName, float DurTime, AActor* Actor, FRotator End,UCurveFloat* Curve, bool IsLoop)
{
	if(!Actor) return nullptr;
	UDBTweenActor* result = NewObject<UDBTweenActor>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartRotValue = Actor->GetActorRotation();
	result->EndRotValue = End;
	result->SetLooping(IsLoop);
	result->Actor = Actor;
	result->DBTweenActorType = EDBTweenActorType::E_ActorRotation;
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

UDBTweenActor* UDBTweenActor::DOScale(FString TweenName,float DurTime, AActor* Actor, FVector End, EaseType easeType, bool IsLoop)
{
	if(!Actor) return nullptr;
	UDBTweenActor* result = NewObject<UDBTweenActor>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartScaleValue = Actor->GetActorScale();
	result->EndScaleValue = End;
	result->SetLooping(IsLoop);
	result->Actor = Actor;
	result->DBTweenActorType = EDBTweenActorType::E_ActorScale;
	result->CurEasyType = easeType;
	return result;
}

UDBTweenActor* UDBTweenActor::DOScaleByCurve(FString TweenName, float DurTime, AActor* Actor, FVector End,UCurveFloat* Curve, bool IsLoop)
{
	if(!Actor) return nullptr;
	UDBTweenActor* result = NewObject<UDBTweenActor>();
	result->AllocaKey(TweenName);
	result->Init(DurTime);
	result->StartScaleValue = Actor->GetActorScale();
	result->EndScaleValue = End;
	result->SetLooping(IsLoop);
	result->Actor = Actor;
	result->DBTweenActorType = EDBTweenActorType::E_ActorScale;
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

void UDBTweenActor::UpdateFunc(float deltaTime)
{
	if (Paused)return;//
	Super::UpdateFunc(deltaTime);
	if (!Actor || !IsValid(Actor)) {
		SetReadyToDestroy();
		return;
	}
	if (!isInit)
	{
		isInit = true;
		OnFirst.Broadcast();
	}
	switch (DBTweenActorType)
	{
		case E_ActorRelativeLocation:
			{
				FVector CurValue = StartLocValue +  Evaluate() * (EndLocValue - StartLocValue);
				if (Actor)
				{
					Actor->SetActorRelativeLocation(CurValue);
				}
			}
			break;

		case E_ActorLocation:
			{
				FVector CurValue = StartLocValue +  Evaluate() * (EndLocValue - StartLocValue);
				if (Actor)
				{
					Actor->SetActorLocation(CurValue);
				}
			}
			break;
		case E_ActorRelativeRotation:
			{
				FRotator CurValue = StartRotValue + Evaluate() * (EndRotValue - StartRotValue);
				if (Actor)
				{
					Actor->SetActorRelativeRotation(CurValue);
				}
			}
			break;
		case E_ActorRotation:
			{
				FRotator CurValue = StartRotValue + Evaluate() * (EndRotValue - StartRotValue);
				if (Actor)
				{
					Actor->SetActorRotation(CurValue);
				}
			}
			break;
		case E_ActorRelativeScale:
			{
				FVector CurValue = StartScaleValue +  Evaluate() * (EndScaleValue - StartScaleValue);
				if (Actor)
				{
					Actor->SetActorRelativeScale3D(CurValue);
				}
			}
			break;
		case E_ActorScale:
			{
				FVector CurValue = StartScaleValue +  Evaluate() * (EndScaleValue - StartScaleValue);
				if (Actor)
				{
					Actor->SetActorScale3D(CurValue);
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
