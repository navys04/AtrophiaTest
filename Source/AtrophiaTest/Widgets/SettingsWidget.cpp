// Fill out your copyright notice in the Description page of Project Settings.


#include "AtrophiaTest/Widgets/SettingsWidget.h"

#include "AtrophiaTest/Framework/AtrophiaGameInstance.h"
#include "Components/Button.h"

void USettingsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	MainMenuButton->OnClicked.AddDynamic(this, &USettingsWidget::ShowMainMenu);
}

void USettingsWidget::ShowMainMenu()
{
	Cast<UAtrophiaGameInstance>(GetGameInstance())->ShowMainMenu();
}
