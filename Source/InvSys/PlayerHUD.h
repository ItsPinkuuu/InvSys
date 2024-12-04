#pragma once

#include "CoreMinimal.h"
#include "InteractionInterface.h"
#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"


class UContainerInventoryPanel;
class UCrosshairWidget;
class UInteractionWidget;
class UInventoryMenu;

UCLASS()
class INVSYS_API APlayerHUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UCrosshairWidget> CrosshairWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UInventoryMenu> InventoryMenuClass;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UInteractionWidget> InteractionWidgetClass;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UContainerInventoryPanel> ContainerInventoryPanelClass;

	bool bIsMenuVisible;

	bool bIsInventoryVisible;



	void DisplayMenu();
	void HideMenu();
	void ToggleMenu();

	
	void DisplayInventory();
	void HideInventory();


	
	void ShowInteractionWidget() const;

	void HideInteractionWidget() const;

	void UpdateInteractionWidget( const FInteractableData* InteractableData ) const;

	
protected:

	UPROPERTY()
	UCrosshairWidget* CrosshairWidget;

	UPROPERTY()
	UInventoryMenu* InventoryMenuWidget;

	UPROPERTY()
	UInteractionWidget* InteractionWidget;

	UPROPERTY()
	UContainerInventoryPanel* ContainerInventoryPanelWidget;
	
	
	
	virtual void BeginPlay() override;
	
};
