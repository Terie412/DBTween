// Copyright 2021-2022, DearBing. All Rights Reserved.


#include "DBTweenUtil.h"

UDBTweenActor* UDBTweenUtil::DOLocalMoveSync(FString TweenName,float DurTime /*= 1.f*/, AActor* Actor /*= nullptr*/, FVector End /*= FVector(100, 100, 100)*/, EaseType easeType /*= EaseType::Linear*/, bool IsLoop /*= false*/)
{
	return UDBTweenActor::DOLocalMove(TweenName, DurTime, Actor, End, easeType,IsLoop);
}

UDBTweenActor* UDBTweenUtil::DOLocalMoveByCurveSync(FString TweenName, float DurTime, AActor* Actor, FVector End,UCurveFloat* Curve, bool IsLoop)
{
	return UDBTweenActor::DOLocalMoveByCurve(TweenName, DurTime, Actor, End, Curve,IsLoop);
}

UDBTweenActor* UDBTweenUtil::DOLocalRotationSync(FString TweenName,float DurTime /*= 1.f*/, AActor* Actor /*= nullptr*/, FRotator End /*= FRotator(0, 90, 0)*/, EaseType easeType /*= EaseType::Linear*/, bool IsLoop /*= false*/)
{
	return UDBTweenActor::DOLocalRotation(TweenName,DurTime, Actor, End, easeType, IsLoop);
}

UDBTweenActor* UDBTweenUtil::DOLocalRotationByCurveSync(FString TweenName, float DurTime, AActor* Actor, FRotator End,UCurveFloat* Curve, bool IsLoop)
{
	return UDBTweenActor::DOLocalRotationByCurve(TweenName,DurTime, Actor, End, Curve, IsLoop);
}

UDBTweenActor* UDBTweenUtil::DOLocalScaleSync(FString TweenName,float DurTime /*= 1.f*/, AActor* Actor /*= nullptr*/, FVector End /*= FVector(2, 2, 2)*/, EaseType easeType /*= EaseType::Linear*/, bool IsLoop /*= false*/)
{
	return UDBTweenActor::DOLocalScale(TweenName,DurTime, Actor, End, easeType, IsLoop);
}

UDBTweenActor* UDBTweenUtil::DOLocalScaleByCurveSync(FString TweenName, float DurTime, AActor* Actor, FVector End,UCurveFloat* Curve, bool IsLoop)
{
	return UDBTweenActor::DOLocalScaleByCurve(TweenName,DurTime, Actor, End, Curve, IsLoop);
}

UDBTweenActor* UDBTweenUtil::DOMoveSync(FString TweenName,float DurTime /*= 1.f*/, AActor* Actor /*= nullptr*/, FVector End /*= FVector(100, 100, 100)*/, EaseType easeType /*= EaseType::Linear*/, bool IsLoop /*= false*/)
{
	return UDBTweenActor::DOMove(TweenName,DurTime, Actor, End, easeType, IsLoop);
}

UDBTweenActor* UDBTweenUtil::DOMoveByCurveSync(FString TweenName, float DurTime, AActor* Actor, FVector End,UCurveFloat* Curve, bool IsLoop)
{
	return UDBTweenActor::DOMoveByCurve(TweenName,DurTime, Actor, End, Curve, IsLoop);
}

UDBTweenActor* UDBTweenUtil::DORotationSync(FString TweenName,float DurTime /*= 1.f*/, AActor* Actor /*= nullptr*/, FRotator End /*= FRotator(0, 90, 0)*/, EaseType easeType /*= EaseType::Linear*/, bool IsLoop /*= false*/)
{
	return UDBTweenActor::DORotation(TweenName,DurTime, Actor, End, easeType, IsLoop);
}

UDBTweenActor* UDBTweenUtil::DORotationByCurveSync(FString TweenName, float DurTime, AActor* Actor, FRotator End,UCurveFloat* Curve, bool IsLoop)
{
	return UDBTweenActor::DORotationByCurve(TweenName,DurTime, Actor, End, Curve, IsLoop);
}

UDBTweenActor* UDBTweenUtil::DOScaleSync(FString TweenName,float DurTime /*= 1.f*/, AActor* Actor /*= nullptr*/, FVector End /*= FVector(2, 2, 2)*/, EaseType easeType /*= EaseType::Linear*/, bool IsLoop /*= false*/)
{
	return UDBTweenActor::DOScale(TweenName,DurTime, Actor, End, easeType, IsLoop);
}

UDBTweenActor* UDBTweenUtil::DOScaleByCurveSync(FString TweenName, float DurTime, AActor* Actor, FVector End,UCurveFloat* Curve, bool IsLoop)
{
	return UDBTweenActor::DOScaleByCurve(TweenName,DurTime, Actor, End, Curve, IsLoop);
}

UDBTweenColor* UDBTweenUtil::DOColorSync(FString TweenName,float DurTime /*= 1*/, FLinearColor Start /*= FLinearColor(0, 0, 0, 1)*/, FLinearColor End /*= FLinearColor(1, 1, 1, 1)*/, EaseType easeType /*= EaseType::Linear*/, bool IsLoop /*= false*/)
{
	return UDBTweenColor::DOColor(TweenName,DurTime, Start, End, easeType, IsLoop);
}

UDBTweenColor* UDBTweenUtil::DOColorByCurveSync(FString TweenName, float DurTime, FLinearColor Start, FLinearColor End,UCurveFloat* Curve, bool IsLoop)
{
	return UDBTweenColor::DOColorByCurve(TweenName,DurTime, Start, End, Curve, IsLoop);
}

UDBTweenFloat* UDBTweenUtil::DOFloatSync(FString TweenName,float DurTime /*= 1*/, float Start /*= 0*/, float End /*= 1*/, EaseType easeType /*= EaseType::Linear*/, bool IsLoop /*= false*/)
{
	return UDBTweenFloat::DOFloat(TweenName,DurTime, Start, End, easeType, IsLoop);
}

UDBTweenFloat* UDBTweenUtil::DOFloatByCurveSync(FString TweenName, float DurTime, float Start, float End,UCurveFloat* Curve, bool IsLoop)
{
	return UDBTweenFloat::DOFloatByCurve(TweenName,DurTime, Start, End, Curve, IsLoop);
}

UDBTweenPath* UDBTweenUtil::DOPathSync(FString TweenName,TArray<FVector> Path, float DurTime /*= 1*/, EaseType easeType /*= EaseType::Linear*/, bool IsLoop /*= false*/)
{
	return UDBTweenPath::DOPath(TweenName,Path, DurTime, easeType, IsLoop);
}

UDBTweenPath* UDBTweenUtil::DOPathByCurveSync(FString TweenName, TArray<FVector> Path, float DurTime, UCurveFloat* Curve,bool IsLoop)
{
	return UDBTweenPath::DOPathByCurve(TweenName,Path, DurTime, Curve, IsLoop);
}

UDBTweenVector2D* UDBTweenUtil::DOVector2DSync(FString TweenName,float DurTime /*= 1*/, FVector2D Start /*= FVector2D(0, 0)*/, FVector2D End /*= FVector2D(100, 100)*/, EaseType easeType /*= EaseType::Linear*/, bool IsLoop /*= false*/)
{
	return UDBTweenVector2D::DOVector2D(TweenName,DurTime, Start, End, easeType, IsLoop);
}

UDBTweenVector2D* UDBTweenUtil::DOVector2DByCurveSync(FString TweenName, float DurTime, FVector2D Start, FVector2D End,UCurveFloat* Curve, bool IsLoop)
{
	return UDBTweenVector2D::DOVector2DByCurve(TweenName,DurTime, Start, End, Curve, IsLoop);
}

UDBTweenVector3D* UDBTweenUtil::DOVector3DSync(FString TweenName,float DurTime /*= 1.f*/, FVector Start /*= FVector(0, 0, 0)*/, FVector End /*= FVector(100, 100, 100)*/, EaseType easeType /*= EaseType::Linear*/, bool IsLoop /*= false*/)
{
	return UDBTweenVector3D::DOVector3D(TweenName,DurTime, Start, End, easeType, IsLoop);
}

UDBTweenVector3D* UDBTweenUtil::DOVector3DByCurveSync(FString TweenName, float DurTime, FVector Start, FVector End,UCurveFloat* Curve, bool IsLoop)
{
	return UDBTweenVector3D::DOVector3DByCurve(TweenName,DurTime, Start, End, Curve, IsLoop);
}

UDBTweenVector4D* UDBTweenUtil::DOVector4DSync(FString TweenName,FVector4 Start, FVector4 End, float DurTime /*= 1.f*/, EaseType easeType /*= EaseType::Linear*/, bool IsLoop /*= false*/)
{
	return UDBTweenVector4D::DOVector4D( TweenName,Start, End, DurTime, easeType, IsLoop);
}

UDBTweenVector4D* UDBTweenUtil::DOVector4DByCurveSync(FString TweenName, FVector4 Start, FVector4 End, float DurTime,UCurveFloat* Curve, bool IsLoop)
{
	return UDBTweenVector4D::DOVector4DByCurve( TweenName,Start, End, DurTime, Curve, IsLoop);
}
