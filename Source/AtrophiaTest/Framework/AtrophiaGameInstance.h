// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "AtrophiaGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ATROPHIATEST_API UAtrophiaGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	/** Creates and shows main menu */
	UFUNCTION(BlueprintCallable, Category = "Game Control")
	void ShowMainMenu();

	/** Creates and shows setting menu */
	UFUNCTION(BlueprintCallable, Category = "Game Control")
	void ShowSettingsMenu();

	/** Creates and shows creators menu */
	UFUNCTION(BlueprintCallable, Category = "Game Control")
	void ShowCreatorsMenu();
	
protected:
	/** Our blueprint class for main menu widget */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets|Classes")
	TSubclassOf<class UUserWidget> MainMenuWidgetClass;

	/** Our blueprint class for settings widget */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets|Classes")
	TSubclassOf<class UUserWidget> SettingsWidgetClass;

	/** Our blueprint class for creators widget */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widgets|Classes")
	TSubclassOf<class UUserWidget> CreatorsWidgetClass;

	/** Main menu widget instance */
	UPROPERTY(BlueprintReadOnly, Category = "Widgets")
	class UMainMenuWidget* MainMenuWidget;

	/** Settings widget instance */
	UPROPERTY(BlueprintReadOnly, Category = "Widgets")
	class USettingsWidget* SettingsWidget;

	/** Creators widget instance */
	UPROPERTY(BlueprintReadOnly, Category = "Widgets")
	class UCreatorsWidget* CreatorsWidget;

private:
	void SetInputModeUIOnly(class UUserWidget* InWidget);
};
