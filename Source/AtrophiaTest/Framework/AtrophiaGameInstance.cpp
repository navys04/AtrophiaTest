// Fill out your copyright notice in the Description page of Project Settings.


#include "AtrophiaTest/Framework/AtrophiaGameInstance.h"

#include "AtrophiaTest/Widgets/CreatorsWidget.h"
#include "AtrophiaTest/Widgets/MainMenuWidget.h"
#include "AtrophiaTest/Widgets/SettingsWidget.h"

void UAtrophiaGameInstance::ShowMainMenu()
{
	if (SettingsWidget && SettingsWidget->IsInViewport()) SettingsWidget->RemoveFromViewport();
	if (CreatorsWidget && CreatorsWidget->IsInViewport()) CreatorsWidget->RemoveFromViewport();
	
	if (!MainMenuWidget) MainMenuWidget = CreateWidget<UMainMenuWidget>(GetWorld(), MainMenuWidgetClass);
	if (!MainMenuWidget->IsInViewport()) MainMenuWidget->AddToViewport();

	SetInputModeUIOnly(MainMenuWidget);
}

void UAtrophiaGameInstance::ShowSettingsMenu()
{
	if (MainMenuWidget && MainMenuWidget->IsInViewport()) MainMenuWidget->RemoveFromViewport();
	if (CreatorsWidget && CreatorsWidget->IsInViewport()) CreatorsWidget->RemoveFromViewport();

	if (!SettingsWidget) SettingsWidget = CreateWidget<USettingsWidget>(GetWorld(), SettingsWidgetClass);
	if (!SettingsWidget->IsInViewport()) SettingsWidget->AddToViewport();

	SetInputModeUIOnly(SettingsWidget);
}

void UAtrophiaGameInstance::ShowCreatorsMenu()
{
	if (MainMenuWidget && MainMenuWidget->IsInViewport()) MainMenuWidget->RemoveFromViewport();
	if (SettingsWidget && SettingsWidget->IsInViewport()) SettingsWidget->RemoveFromViewport();

	if (!CreatorsWidget) CreatorsWidget = CreateWidget<UCreatorsWidget>(GetWorld(), CreatorsWidgetClass);
	if (!CreatorsWidget->IsInViewport()) CreatorsWidget->AddToViewport();

	SetInputModeUIOnly(CreatorsWidget);
}

void UAtrophiaGameInstance::SetInputModeUIOnly(UUserWidget* InWidget)
{
	GetFirstLocalPlayerController()->bShowMouseCursor = true;
	
	FInputModeUIOnly InputModeUIOnly;
	InputModeUIOnly.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeUIOnly.SetWidgetToFocus(InWidget->TakeWidget());
	GetFirstLocalPlayerController()->SetInputMode(InputModeUIOnly);
}
