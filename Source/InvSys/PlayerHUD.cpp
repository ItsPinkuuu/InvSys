#include "PlayerHUD.h"

#include "ContainerInventoryPanel.h"
#include "CrosshairWidget.h"
#include "InventoryMenu.h"
#include "InteractionWidget.h"



void APlayerHUD::BeginPlay()
{
	Super::BeginPlay();

	if (CrosshairWidgetClass)
	{
		CrosshairWidget = CreateWidget<UCrosshairWidget>(GetWorld(), CrosshairWidgetClass);
		CrosshairWidget->AddToViewport(-1);
		CrosshairWidget->SetVisibility(ESlateVisibility::Visible);
	}

	if (InventoryMenuClass)
	{
		InventoryMenuWidget = CreateWidget<UInventoryMenu>(GetWorld(), InventoryMenuClass);
		InventoryMenuWidget->AddToViewport(5);
		InventoryMenuWidget->SetVisibility(ESlateVisibility::Collapsed);
	}

	if (InteractionWidgetClass)
	{
		InteractionWidget = CreateWidget<UInteractionWidget>(GetWorld(), InteractionWidgetClass);
		InteractionWidget->AddToViewport(-1);
		InteractionWidget->SetVisibility(ESlateVisibility::Collapsed);
	}

	if (ContainerInventoryPanelClass)
	{
		ContainerInventoryPanelWidget = CreateWidget<UContainerInventoryPanel>(GetWorld(), ContainerInventoryPanelClass);
		ContainerInventoryPanelWidget->AddToViewport(5);
		ContainerInventoryPanelWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
	
}



void APlayerHUD::DisplayMenu()
{
	if (InventoryMenuWidget)
	{
		bIsMenuVisible = true;
		InventoryMenuWidget->SetVisibility(ESlateVisibility::Visible);
	}
}

void APlayerHUD::HideMenu()
{
	if (InventoryMenuWidget)
	{
		bIsMenuVisible = false;
		InventoryMenuWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void APlayerHUD::DisplayInventory()
{
	if (ContainerInventoryPanelWidget)
	{
		bIsInventoryVisible = true;
		ContainerInventoryPanelWidget->SetVisibility(ESlateVisibility::Visible);
	}
}

void APlayerHUD::HideInventory()
{
	if (ContainerInventoryPanelWidget)
	{
		bIsInventoryVisible = false;
		ContainerInventoryPanelWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void APlayerHUD::ToggleMenu()
{
	if (bIsMenuVisible)
	{
		HideMenu();

		const FInputModeGameOnly InputMode;
		GetOwningPlayerController()->SetInputMode(InputMode);
		GetOwningPlayerController()->SetShowMouseCursor(false);
	} else if (!bIsMenuVisible)
	{
		DisplayMenu();

		const FInputModeGameOnly InputMode;
		GetOwningPlayerController()->SetInputMode(InputMode);
		GetOwningPlayerController()->SetShowMouseCursor(true);
	}

	// if (bIsInventoryVisible)
	// {
	// 	HideInventory();
	// }
}



void APlayerHUD::ShowInteractionWidget() const
{
	if (InteractionWidget)
	{
		InteractionWidget->SetVisibility(ESlateVisibility::Visible);
	}
}

void APlayerHUD::HideInteractionWidget() const
{
	if (InteractionWidget)
	{
		InteractionWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void APlayerHUD::UpdateInteractionWidget(const FInteractableData* InteractableData) const
{
	if (InteractionWidget)
	{
		if (InteractionWidget->GetVisibility() == ESlateVisibility::Collapsed)
		{
			InteractionWidget->SetVisibility(ESlateVisibility::Visible);
		}

		InteractionWidget->UpdateWidget(InteractableData);
	}
}
