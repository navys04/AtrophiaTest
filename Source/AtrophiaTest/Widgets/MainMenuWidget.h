// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class ATROPHIATEST_API UMainMenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

	/** Play button, when pressed we loading the level */
	UPROPERTY(meta = (BindWidget))
	class UButton* PlayButton;

	/** Settings button, when pressed we show settings widget */
	UPROPERTY(meta = (BindWidget))
	class UButton* SettingsButton;

	/** Creators button, when pressed we show creators widget */
	UPROPERTY(meta = (BindWidget))
	class UButton* CreatorsButton;

	UFUNCTION()
	void OnPressedPlayButton();

	UFUNCTION()
	void OnPressedSettingsButton();

	UFUNCTION()
	void OnPressedCreatorsButton();
};
