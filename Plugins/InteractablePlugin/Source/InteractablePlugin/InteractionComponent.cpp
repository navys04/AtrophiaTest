// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionComponent.h"

// Sets default values for this component's properties
UInteractionComponent::UInteractionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UInteractionComponent::BeginFocus()
{
	for (auto& VisualComp : GetOwner()->GetComponentsByClass(UPrimitiveComponent::StaticClass()))
	{
		if (UPrimitiveComponent* Primitive = Cast<UPrimitiveComponent>(VisualComp))
		{
			Primitive->SetRenderCustomDepth(true);
		}
	}

	OnBeginFocus.Broadcast();
}

void UInteractionComponent::EndFocus()
{
	for (auto& VisualComp : GetOwner()->GetComponentsByClass(UPrimitiveComponent::StaticClass()))
	{
		if (UPrimitiveComponent* Primitive = Cast<UPrimitiveComponent>(VisualComp))
		{
			Primitive->SetRenderCustomDepth(false);
		}
	}

	OnEndFocus.Broadcast();
}

void UInteractionComponent::Interact()
{
	OnInteract.Broadcast();
}

// Called when the game starts
void UInteractionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}