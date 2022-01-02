// Fill out your copyright notice in the Description page of Project Settings.


#include "AtrophiaTest/Widgets/CreatorsWidget.h"

#include "AtrophiaTest/Framework/AtrophiaGameInstance.h"
#include "Components/Button.h"

void UCreatorsWidget::NativeConstruct()
{
	Super::NativeConstruct();

	MainMenuButton->OnClicked.AddDynamic(this, &UCreatorsWidget::ShowMainMenu);
}

void UCreatorsWidget::ShowMainMenu()
{
	Cast<UAtrophiaGameInstance>(GetGameInstance())->ShowMainMenu();
}