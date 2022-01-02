// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InteractionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnBeginFocus);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnEndFocus);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInteract);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class INTERACTABLEPLUGIN_API UInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInteractionComponent();

	/** Called when player begin focus on this item */
	UPROPERTY(BlueprintAssignable, Category = "Interactable")
	FOnBeginFocus OnBeginFocus;

	/** Called when player end focus on this item */
	UPROPERTY(BlueprintAssignable, Category = "Interactable")
	FOnEndFocus OnEndFocus;

	/** Called when player is interacting with this item */
	UPROPERTY(BlueprintAssignable, Category = "Interactable")
	FOnInteract OnInteract;

	UFUNCTION(BlueprintCallable, Category = "Interactable")
	void BeginFocus();

	UFUNCTION(BlueprintCallable, Category = "Interactable")
	void EndFocus();

	UFUNCTION(BlueprintCallable, Category = "Interactable")
	void Interact();
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

};
