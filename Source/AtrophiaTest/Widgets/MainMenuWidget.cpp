// Fill out your copyright notice in the Description page of Project Settings.


#include "AtrophiaTest/Widgets/MainMenuWidget.h"

#include "AtrophiaTest/Framework/AtrophiaGameInstance.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UMainMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	PlayButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnPressedPlayButton);
	SettingsButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnPressedSettingsButton);
	CreatorsButton->OnClicked.AddDynamic(this, &UMainMenuWidget::OnPressedCreatorsButton);
}

void UMainMenuWidget::OnPressedPlayButton()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("ThirdPersonExampleMap"));

	GetGameInstance()->GetFirstLocalPlayerController()->SetInputMode(FInputModeGameOnly());
	GetGameInstance()->GetFirstLocalPlayerController()->bShowMouseCursor = false;
}

void UMainMenuWidget::OnPressedSettingsButton()
{
	Cast<UAtrophiaGameInstance>(GetGameInstance())->ShowSettingsMenu();
}

void UMainMenuWidget::OnPressedCreatorsButton()
{
	Cast<UAtrophiaGameInstance>(GetGameInstance())->ShowCreatorsMenu();
}