#include "DBTweenUtil3.h"

UDBTweenSceneComponent* UDBTweenUtil3::DOLocalMoveSync(FString TweenName,float DurTime /*= 1.f*/, USceneComponent* component /*= nullptr*/, FVector End /*= FVector(100, 100, 100)*/, EaseType easeType /*= EaseType::Linear*/, bool IsLoop /*= false*/)
{
	return UDBTweenSceneComponent::DOLocalMove(TweenName, DurTime, component, End, easeType,IsLoop);
}

UDBTweenSceneComponent* UDBTweenUtil3::DOLocalMoveByCurveSync(FString TweenName, float DurTime, USceneComponent* component, FVector End,UCurveFloat* Curve, bool IsLoop)
{
	return UDBTweenSceneComponent::DOLocalMoveByCurve(TweenName, DurTime, component, End, Curve,IsLoop);
}

UDBTweenSceneComponent* UDBTweenUtil3::DOLocalRotationSync(FString TweenName,float DurTime /*= 1.f*/, USceneComponent* component /*= nullptr*/, FRotator End /*= FRotator(0, 90, 0)*/, EaseType easeType /*= EaseType::Linear*/, bool IsLoop /*= false*/)
{
	return UDBTweenSceneComponent::DOLocalRotation(TweenName,DurTime, component, End, easeType, IsLoop);
}

UDBTweenSceneComponent* UDBTweenUtil3::DOLocalRotationByCurveSync(FString TweenName, float DurTime, USceneComponent* component, FRotator End,UCurveFloat* Curve, bool IsLoop)
{
	return UDBTweenSceneComponent::DOLocalRotationByCurve(TweenName,DurTime, component, End, Curve, IsLoop);
}

UDBTweenSceneComponent* UDBTweenUtil3::DOLocalScaleSync(FString TweenName,float DurTime /*= 1.f*/, USceneComponent* component /*= nullptr*/, FVector End /*= FVector(2, 2, 2)*/, EaseType easeType /*= EaseType::Linear*/, bool IsLoop /*= false*/)
{
	return UDBTweenSceneComponent::DOLocalScale(TweenName,DurTime, component, End, easeType, IsLoop);
}

UDBTweenSceneComponent* UDBTweenUtil3::DOLocalScaleByCurveSync(FString TweenName, float DurTime, USceneComponent* component, FVector End,UCurveFloat* Curve, bool IsLoop)
{
	return UDBTweenSceneComponent::DOLocalScaleByCurve(TweenName,DurTime, component, End, Curve, IsLoop);
}

UDBTweenSceneComponent* UDBTweenUtil3::DOMoveSync(FString TweenName,float DurTime /*= 1.f*/, USceneComponent* component /*= nullptr*/, FVector End /*= FVector(100, 100, 100)*/, EaseType easeType /*= EaseType::Linear*/, bool IsLoop /*= false*/)
{
	return UDBTweenSceneComponent::DOMove(TweenName,DurTime, component, End, easeType, IsLoop);
}

UDBTweenSceneComponent* UDBTweenUtil3::DOMoveByCurveSync(FString TweenName, float DurTime, USceneComponent* component, FVector End,UCurveFloat* Curve, bool IsLoop)
{
	return UDBTweenSceneComponent::DOMoveByCurve(TweenName,DurTime, component, End, Curve, IsLoop);
}

UDBTweenSceneComponent* UDBTweenUtil3::DORotationSync(FString TweenName,float DurTime /*= 1.f*/, USceneComponent* component /*= nullptr*/, FRotator End /*= FRotator(0, 90, 0)*/, EaseType easeType /*= EaseType::Linear*/, bool IsLoop /*= false*/)
{
	return UDBTweenSceneComponent::DORotation(TweenName,DurTime, component, End, easeType, IsLoop);
}

UDBTweenSceneComponent* UDBTweenUtil3::DORotationByCurveSync(FString TweenName, float DurTime, USceneComponent* component, FRotator End,UCurveFloat* Curve, bool IsLoop)
{
	return UDBTweenSceneComponent::DORotationByCurve(TweenName,DurTime, component, End, Curve, IsLoop);
}

UDBTweenSceneComponent* UDBTweenUtil3::DOScaleSync(FString TweenName,float DurTime /*= 1.f*/, USceneComponent* component /*= nullptr*/, FVector End /*= FVector(2, 2, 2)*/, EaseType easeType /*= EaseType::Linear*/, bool IsLoop /*= false*/)
{
	return UDBTweenSceneComponent::DOScale(TweenName,DurTime, component, End, easeType, IsLoop);
}

UDBTweenSceneComponent* UDBTweenUtil3::DOScaleByCurveSync(FString TweenName, float DurTime, USceneComponent* component, FVector End,UCurveFloat* Curve, bool IsLoop)
{
	return UDBTweenSceneComponent::DOScaleByCurve(TweenName,DurTime, component, End, Curve, IsLoop);
}
