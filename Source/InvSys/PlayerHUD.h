#pragma once

#include "CoreMinimal.h"
#include "InteractionInterface.h"
#include "GameFramework/HUD.h"
#include "PlayerHUD.generated.h"


class UInteractionWidget;
class UMainMenu;

UCLASS()
class INVSYS_API APlayerHUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UMainMenu> MainMenuClass;

	UPROPERTY(EditDefaultsOnly, Category = "Widgets")
	TSubclassOf<UInteractionWidget> InteractionWidgetClass;

	bool bIsMenuVisible;



	void DisplayMenu();

	void HideMenu();

	
	void ShowInteractionWidget();

	void HideInteractionWidget();

	void UpdateInteractionWidget( const FInteractableData* InteractableData );

protected:

	UPROPERTY()
	UMainMenu* MainMenuWidget;

	UPROPERTY()
	UInteractionWidget* InteractionWidget;
	
	
	
	virtual void BeginPlay() override;
	
};
