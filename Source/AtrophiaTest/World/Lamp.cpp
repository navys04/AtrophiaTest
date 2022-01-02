// Fill out your copyright notice in the Description page of Project Settings.


#include "AtrophiaTest/World/Lamp.h"

#include "Components/PointLightComponent.h"

// Sets default values
ALamp::ALamp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));
}

// Called when the game starts or when spawned
void ALamp::BeginPlay()
{
	Super::BeginPlay();

	PointLight->SetVisibility(false);
	PlayerCharacter = GetGameInstance()->GetFirstLocalPlayerController()->GetPawn();
}

// Called every frame
void ALamp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (PlayerCharacter)
	{
		const float Distance = FVector::Distance(GetActorLocation(), PlayerCharacter->GetActorLocation());

		if (Distance <= DistanceToPlayer && !PointLight->IsVisible())
		{
			PointLight->SetVisibility(true);
		}
	}
}

