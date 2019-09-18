// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"

//#include "EngineMinimal.h" //p64
#include "ArenaBattle.h"
#include"GameFramework/RotatingMovementComponent.h"
#include "GameFramework/Actor.h"
#include "Fountain.generated.h"

UCLASS()//AFountain가상머신이 이 객체를 관리  UPROPERTY이 매크로가 있으면 가상머신에서 관리 없으면 직접 관리
class ARENABATTLE_API AFountain : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFountain();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	//virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
	virtual void PostInitializeComponents() override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent *Body;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent *Water;

	UPROPERTY(VisibleAnywhere)
	UPointLightComponent * Light;

	UPROPERTY(VisibleAnywhere)
	UParticleSystemComponent* Splash;

	UPROPERTY(VisibleAnywhere)
	URotatingMovementComponent* Movement;

private:
	UPROPERTY(EditAnywhere,Category=Stat,Meta=(AllowPrivateAccess=true))//가상머신에서 관리 알아서 초기화 해줌
	float RoateSpeed;
};
