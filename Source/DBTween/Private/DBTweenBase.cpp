// Copyright 2021-2022, DearBing. All Rights Reserved.


#include "DBTweenBase.h"
#include "DBTweenUpdateManager.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"

UDBTweenBase::~UDBTweenBase()
{
	if (Finished)return;
	Finished = true;
	ADBTweenUpdateManager::RemoveUpdateCall(UpdateKey);
	if(ADBTweenUpdateManager::Instance != nullptr)
		ADBTweenUpdateManager::Instance->DBTweenDic.Remove(MyDBTweenKey);
}

bool UDBTweenBase::DBTweenStop(FString TweenName)
{
	if (ADBTweenUpdateManager::Instance == nullptr)return false;
	if(!ADBTweenUpdateManager::Instance->DBTweenDic.Contains(TweenName))
	{
		return false;
	}
	else
	{
		ADBTweenUpdateManager::Instance->DBTweenDic[TweenName]->SetReadyToDestroy();
		return true;
	}
}

void UDBTweenBase::SetOvershootOrAmplitudeAndPeriod(float OvershootOrAmplitudeParam, float PeriodParam)
{
	easePeriod = PeriodParam;
	easeOvershootOrAmplitude = OvershootOrAmplitudeParam;
}

bool UDBTweenBase::DBTweenReset(FString TweenName)
{
	if (ADBTweenUpdateManager::Instance == nullptr)return false;
	if(!ADBTweenUpdateManager::Instance->DBTweenDic.Contains(TweenName))
	{
		return false;
	}
	else
	{
		UDBTweenBase* Target = ADBTweenUpdateManager::Instance->DBTweenDic[TweenName];
		Target->CurTime = 0;
		Target->bReverse = false;
		bool bIsPaused = Target->Paused;
		Target->Paused = false;
		Target->isInit = true;
		if(Target->Finished)
		{
			Target->Finished = false;
			Target->UpdateFunc(0.f);
			Target->Finished = true;
		}
		else 
		{
			Target->UpdateFunc(0.f);
		}
		Target->Paused = bIsPaused;
		Target->isInit = false;
		return true;
	}
}

bool UDBTweenBase::DBTweenPlay(FString TweenName)
{
	if (ADBTweenUpdateManager::Instance == nullptr)return false;
	if(!ADBTweenUpdateManager::Instance->DBTweenDic.Contains(TweenName))
	{
		return false;
	}
	else
	{
		UDBTweenBase* Target = ADBTweenUpdateManager::Instance->DBTweenDic[TweenName];
		if (Target->Paused)
		{
			Target->Paused = false;
		}
		else
		{
			Target->Finished = false;
		}
		return true;
	}
}

bool UDBTweenBase::DBTweenPause(FString TweenName)
{
	if (ADBTweenUpdateManager::Instance == nullptr)return false;
	if (!ADBTweenUpdateManager::Instance->DBTweenDic.Contains(TweenName))
	{
		return false;
	}
	else
	{
		UDBTweenBase* Target = ADBTweenUpdateManager::Instance->DBTweenDic[TweenName];
		Target->Paused = true;
		return true;
	}
}

bool UDBTweenBase::ExistDBTween(FString DBTweenKey)
{
	if (ADBTweenUpdateManager::Instance == nullptr)return false;
	if (!ADBTweenUpdateManager::Instance->DBTweenDic.Contains(DBTweenKey) || DBTweenKey.IsEmpty())
	{
		return false;
	}
	return true;
}

TArray<FString> UDBTweenBase::GetAllDBTween()
{
	TArray<FString> AllKey;
	if (ADBTweenUpdateManager::Instance)
	{
		ADBTweenUpdateManager::Instance->DBTweenDic.GetKeys(AllKey);
	}
	return AllKey;
}

void UDBTweenBase::Init(float durTime)
{
	FTickHandle updateCall = FTickHandle();
	updateCall.BindUObject(this, &UDBTweenBase::UpdateFunc);
	TotalTime = durTime;
	UpdateKey = ADBTweenUpdateManager::RegisterUpdateCall(updateCall);
	if (MyDBTweenKey.IsEmpty())
	{
		MyDBTweenKey = FString::FromInt(this->GetUniqueID());
	}
	ADBTweenUpdateManager::Instance->DBTweenDic.Add(MyDBTweenKey, this);
}

void UDBTweenBase::SetReadyToDestroy()
{
	if (Finished)return;
	Finished = true;
	ADBTweenUpdateManager::RemoveUpdateCall(UpdateKey);
	ADBTweenUpdateManager::Instance->DBTweenDic.Remove(MyDBTweenKey);
	Super::SetReadyToDestroy();
}

void UDBTweenBase::UpdateFunc(float deltaTime)
{
	if (Paused)return;//
	if (Finished)return;
	if(!bLoop)
	{
		CurTime = FMath::Min(CurTime+deltaTime,TotalTime);
		if (CurTime >= TotalTime)//Finish
		{
		SetReadyToDestroy();	
		}
	}
	else
	{
		if (CurTime < TotalTime && !bReverse)
		{
			CurTime = FMath::Min(CurTime+deltaTime,TotalTime);
		}
		else
		{
			CurTime = FMath::Max(CurTime-deltaTime,0.f);
			bReverse = CurTime == 0.f ? false : true;
		}
	}
	
}

void UDBTweenBase::SetLooping(bool bIsLoop)
{
	bLoop = bIsLoop;
}

void UDBTweenBase::AllocaKey(FString TweenName)
{
	if (ADBTweenUpdateManager::Instance == nullptr || ADBTweenUpdateManager::Instance->DBTweenDic.Contains(TweenName) || TweenName.IsEmpty())
	{
		MyDBTweenKey = FString::FromInt(this->GetUniqueID());
	}
	else
	{
		MyDBTweenKey = TweenName;
	}
}

float UDBTweenBase::Evaluate()
{
	float time = CurTime;
	float duration = TotalTime;
	if (FloatCurve != nullptr)
	{
		float MinTime;
		float MaxTime;
		FloatCurve->GetTimeRange(MinTime,MaxTime);
		float CurveDurTime = MaxTime - MinTime;
		if (CurveDurTime == 0)
		{
			return 0;
		}
		float BiliCurTime = MinTime + (time / duration * CurveDurTime);
		return FloatCurve->GetFloatValue(BiliCurTime);
	}
	EaseType easeType = CurEasyType;
	float period = easePeriod;
	float overshootOrAmplitude = easeOvershootOrAmplitude;
	switch (easeType)
	{
	case EaseType::Linear:
		return (time / duration);

	case EaseType::InSine:
		return (-((float)FMath::Cos((double)((time / duration) * 1.570796f))) + 1.0);

	case EaseType::OutSine:
		return (float)FMath::Sin((double)((time / duration) * 1.570796f));

	case EaseType::InOutSine:
		return (-0.5f * (((float)FMath::Cos((double)((3.141593f * time) / duration))) - 1.0));

	case EaseType::InQuad:
	{
		time = time / duration;
		return (time * time);
	}
	case EaseType::OutQuad:
	{
		time = time / duration;
		return (-time * (time - 2.0));
	}
	case EaseType::InOutQuad:
	{
		time = time / (duration * 0.5f);
		if (time < 1.0)
		{
			return ((0.5f * time) * time);
		}
		time = time - 1.0;
		return (-0.5f * ((time * (time - 2.0)) - 1.0));
	}
	case EaseType::InCubic:
	{
		time = time / duration;
		return ((time * time) * time);
	}
	case EaseType::OutCubic:
	{
		time = (time / duration) - 1.0;
		return (((time * time) * time) + 1.0);
	}
	case EaseType::InOutCubic:
	{
		time = time / (duration * 0.5f);
		if (time < 1.0)
		{
			return (((0.5f * time) * time) * time);
		}
		time = time - 2.0;
		return (0.5f * (((time * time) * time) + 2.0));
	}
	case EaseType::InQuart:
	{
		time = time / duration;
		return (((time * time) * time) * time);
	}
	case EaseType::OutQuart:
	{
		time = (time / duration) - 1.0;
		return -((((time * time) * time) * time) - 1.0);
	}
	case EaseType::InOutQuart:
	{
		time = time / (duration * 0.5f);
		if (time < 1.0)
		{
			return ((((0.5f * time) * time) * time) * time);
		}
		time = time - 2.0;
		return (-0.5f * ((((time * time) * time) * time) - 2.0));
	}
	case EaseType::InQuint:
	{
		time = time / duration;
		return ((((time * time) * time) * time) * time);
	}
	case EaseType::OutQuint:
	{
		time = (time / duration) - 1.0;
		return (((((time * time) * time) * time) * time) + 1.0);
	}
	case EaseType::InOutQuint:
	{
		time = time / (duration * 0.5f);
		if (time < 1.0)
		{
			return (((((0.5f * time) * time) * time) * time) * time);
		}
		time = time - 2.0;
		return (0.5f * (((((time * time) * time) * time) * time) + 2.0));
	}
	case EaseType::InExpo:
		return ((time == 0.0) ? 0.0 : ((float)FMath::Pow(2.0, (double)(10.0 * ((time / duration) - 1.0)))));

	case EaseType::OutExpo:
		return ((time != duration) ? (-((float)FMath::Pow(2.0, (double)((-10.0 * time) / duration))) + 1.0) : 1.0);

	case EaseType::InOutExpo:
	{
		if (time == 0.0)
		{
			return 0.0;
		}
		if (time == duration)
		{
			return 1.0;
		}
		time = time / (duration * 0.5f);
		if (time < 1.0)
		{
			return (0.5f * ((float)FMath::Pow(2.0, (double)(10.0 * (time - 1.0)))));
		}
		time = time - 1.0;
		return (0.5f * (-((float)FMath::Pow(2.0, (double)(-10.0 * time))) + 2.0));
	}
	case EaseType::InCirc:
	{
		time = time / duration;
		return -(((float)FMath::Sqrt((double)(1.0 - (time * time)))) - 1.0);
	}
	case EaseType::OutCirc:
	{
		time = (time / duration) - 1.0;
		return (float)FMath::Sqrt((double)(1.0 - (time * time)));
	}
	case EaseType::InOutCirc:
	{
		time = time / (duration * 0.5f);
		if (time < 1.0)
		{
			return (-0.5f * (((float)FMath::Sqrt((double)(1.0 - (time * time)))) - 1.0));
		}
		time = time - 2.0;
		return (0.5f * (((float)FMath::Sqrt((double)(1.0 - (time * time)))) + 1.0));
	}
	case EaseType::InElastic:
	{
		float num;
		if (time == 0.0)
		{
			return 0.0;
		}
		time = time / duration;
		if (time == 1.0)
		{
			return 1.0;
		}
		if (period == 0.0)
		{
			period = duration * 0.3f;
		}
		if (overshootOrAmplitude >= 1.0)
		{
			num = (period / 6.283185f) * ((float)FMath::Asin((double)(1.0 / overshootOrAmplitude)));
		}
		else
		{
			overshootOrAmplitude = 1.0;
			num = period / 4.0;
		}
		time = time - 1.0;
		return -((overshootOrAmplitude * ((float)FMath::Pow(2.0, (double)(10.0 * time )))) * ((float)FMath::Sin((double)((((time * duration) - num) * 6.283185f) / period))));
	}
	case EaseType::OutElastic:
	{
		float num2;
		if (time == 0.0)
		{
			return 0.0;
		}
		time = time / duration;
		if (time == 1.0)
		{
			return 1.0;
		}
		if (period == 0.0)
		{
			period = duration * 0.3f;
		}
		if (overshootOrAmplitude >= 1.0)
		{
			num2 = (period / 6.283185f) * ((float)FMath::Asin((double)(1.0 / overshootOrAmplitude)));
		}
		else
		{
			overshootOrAmplitude = 1.0;
			num2 = period / 4.0;
		}
		return (((overshootOrAmplitude * ((float)FMath::Pow(2.0, (double)(-10.0 * time)))) * ((float)FMath::Sin((double)((((time * duration) - num2) * 6.283185f) / period)))) + 1.0);
	}
	case EaseType::InOutElastic:
	{
		float num3;
		if (time == 0.0)
		{
			return 0.0;
		}
		time = time / (duration * 0.5f);
		if (time == 2.0)
		{
			return 1.0;
		}
		if (period == 0.0)
		{
			period = duration * 0.45f;
		}
		if (overshootOrAmplitude >= 1.0)
		{
			num3 = (period / 6.283185f) * ((float)FMath::Asin((double)(1.0 / overshootOrAmplitude)));
		}
		else
		{
			overshootOrAmplitude = 1.0;
			num3 = period / 4.0;
		}
		if (time < 1.0)
		{
			time = time - 1.0;
			return (-0.5f * ((overshootOrAmplitude * ((float)FMath::Pow(2.0, (double)(10.0 * time)))) * ((float)FMath::Sin((double)((((time * duration) - num3) * 6.283185f) / period)))));
		}
		time = time - 1.0;
		return ((((overshootOrAmplitude * ((float)FMath::Pow(2.0, (double)(-10.0 * time)))) * ((float)FMath::Sin((double)((((time * duration) - num3) * 6.283185f) / period)))) * 0.5f) + 1.0);
	}
	case EaseType::InBack:
	{
		time = time / duration;
		return ((time * time) * (((overshootOrAmplitude + 1.0) * time) - overshootOrAmplitude));
	}
	case EaseType::OutBack:
	{
		time = (time / duration) - 1.0;
		return (((time * time) * (((overshootOrAmplitude + 1.0) * time) + overshootOrAmplitude)) + 1.0);
	}
	case EaseType::InOutBack:
	{
		time = time / (duration * 0.5f);
		if (time < 1.0)
		{
			overshootOrAmplitude = overshootOrAmplitude * 1.525f;
			return (0.5f * ((time * time) * (((overshootOrAmplitude + 1.0) * time) - overshootOrAmplitude)));
		}
		time = time - 2.0;
		overshootOrAmplitude = overshootOrAmplitude * 1.525f;
		return (0.5f * (((time * time) * (((overshootOrAmplitude + 1.0) * time) + overshootOrAmplitude)) + 2.0));
	}
	case EaseType::InBounce:
		return BounceEaseIn(time, duration, overshootOrAmplitude, period);

	case EaseType::OutBounce:
		return BounceEaseOut(time, duration, overshootOrAmplitude, period);

	case EaseType::InOutBounce:
		return BounceEaseInOut(time, duration, overshootOrAmplitude, period);
	}
	time = time / duration;
	return (-time * (time - 2.0));
}

float UDBTweenBase::BounceEaseIn(float time, float duration, float unusedOvershootOrAmplitude, float unusedPeriod)
{
	return 1.0 - BounceEaseOut(duration - time, duration, -1.0, -1.0);
}

float UDBTweenBase::BounceEaseInOut(float time, float duration, float unusedOvershootOrAmplitude, float unusedPeriod)
{
	return  (time >= (duration * 0.5f)) ? ((BounceEaseOut((time * 2.0) - duration, duration, -1.0, -1.0) * 0.5f) + 0.5f) : (BounceEaseIn(time * 2.0, duration, -1.0, -1.0) * 0.5f);
}

float UDBTweenBase::BounceEaseOut(float time, float duration, float unusedOvershootOrAmplitude, float unusedPeriod)
{
	time = time / duration;
	if (time < 0.3636364f)
	{
		return ((7.5625f * time) * time);
	}
	if (time < 0.7272727f)
	{
		time = time - 0.5454546f;
		return (((7.5625f * time) * time) + 0.75f);
	}
	if (time < 0.9090909f)
	{
		time = time - 0.8181818f;
		return (((7.5625f * time) * time) + 0.9375f);
	}
	time = time - 0.9545454f;
	return (((7.5625f * time) * time) + 0.984375f);

}
