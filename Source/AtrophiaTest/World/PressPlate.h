// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PressPlate.generated.h"

UCLASS()
class ATROPHIATEST_API APressPlate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APressPlate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** When player gets on our plate this text will print in console / screen */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interactable")
	FText TextToShow;

	/** Our plates mesh */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interactable")
	UStaticMeshComponent* PlateMesh;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
