// Copyright 2021-2022, DearBing. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "Runtime/Engine/Classes/Curves/CurveFloat.h"
#include "DBTweenBase.generated.h"

UENUM(BlueprintType)
enum class EaseType : uint8
{
	Linear = 0,
	InSine = 1,
	InQuad = 2,
	InCubic = 3,
	InQuart = 4,
	InQuint = 5,
	InExpo = 6,
	InCirc = 7,
	InElastic = 8,
	InBack = 9,
	InBounce = 10,
	OutQuad = 31,
	OutSine = 32,
	OutCubic = 33,
	OutQuart = 34,
	OutQuint = 35,
	OutExpo = 36,
	OutCirc = 37,
	OutElastic = 38,
	OutBack = 39,
	OutBounce = 40,
	InOutQuad = 61,
	InOutSine = 62,
	InOutCubic = 63,
	InOutQuart = 64,
	InOutQuint = 65,
	InOutExpo = 66,
	InOutCirc = 67,
	InOutElastic = 68,
	InOutBack = 69,
	InOutBounce = 70
};

UCLASS()
class DBTWEEN_API UDBTweenBase : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()
public:
	~UDBTweenBase();
	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | UDBTweenBase")
		static bool DBTweenStop(FString TweenName);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | UDBTweenBase")
		static bool DBTweenReset(FString TweenName);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | UDBTweenBase")
		static bool DBTweenPlay(FString TweenName);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | UDBTweenBase")
		static bool DBTweenPause(FString TweenName);

	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | UDBTweenBase")
		static bool ExistDBTween(FString DBTweenKey);
	
	UFUNCTION(BlueprintCallable, Category = "DBTweenUtil | UDBTweenBase")
		static TArray<FString> GetAllDBTween();

	bool Paused = false;
	void SetOvershootOrAmplitudeAndPeriod(float OvershootOrAmplitudeParam = 1.70158f, float PeriodParam = 0);

	float easePeriod;
	float easeOvershootOrAmplitude = 1.70158f;

	FString MyDBTweenKey;
	
protected:

	void Init(float durTime);
	virtual void UpdateFunc(float deltaTime);
	void SetLooping(bool bIsLoop);
	void AllocaKey(FString TweenName);

	virtual void SetReadyToDestroy() override;
	float TotalTime;
	float CurTime;
	int UpdateKey;
	bool Finished;
	bool bLoop = false;
	bool bReverse = false;
	bool isInit = false;
	UCurveFloat* FloatCurve;
	EaseType CurEasyType = EaseType::Linear;
	float Evaluate();
	float BounceEaseIn(float time, float duration, float unusedOvershootOrAmplitude, float unusedPeriod);
	float BounceEaseInOut(float time, float duration, float unusedOvershootOrAmplitude, float unusedPeriod);
	float BounceEaseOut(float time, float duration, float unusedOvershootOrAmplitude, float unusedPeriod);
};
