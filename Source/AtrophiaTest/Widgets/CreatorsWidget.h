// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CreatorsWidget.generated.h"

/**
 * 
 */
UCLASS()
class ATROPHIATEST_API UCreatorsWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	class UButton* MainMenuButton;

	UFUNCTION()
	void ShowMainMenu();
};
