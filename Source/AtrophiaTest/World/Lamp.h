// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Lamp.generated.h"

UCLASS()
class ATROPHIATEST_API ALamp : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALamp();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Distance to player when this lamp will enable */
	UPROPERTY(EditAnywhere, Category = "Lamp")
	float DistanceToPlayer;

	/** Light that will enable when the player is near */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Lamp")
	class UPointLightComponent* PointLight;

	UPROPERTY()
	AActor* PlayerCharacter;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
