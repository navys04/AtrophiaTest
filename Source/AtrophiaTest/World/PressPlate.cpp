// Fill out your copyright notice in the Description page of Project Settings.


#include "AtrophiaTest/World/PressPlate.h"

#include "AtrophiaTest/AtrophiaTestCharacter.h"

// Sets default values
APressPlate::APressPlate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	PlateMesh = CreateDefaultSubobject<UStaticMeshComponent>("PlateMesh");
	PlateMesh->SetupAttachment(GetRootComponent());
	PlateMesh->OnComponentBeginOverlap.AddUniqueDynamic(this, &APressPlate::OnOverlapBegin);
}

// Called when the game starts or when spawned
void APressPlate::BeginPlay()
{
	Super::BeginPlay();
}

void APressPlate::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Purple, TextToShow.ToString());
	}
}