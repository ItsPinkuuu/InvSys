#include "InventoryMenu.h"
#include "InvSysCharacter.h"



void UInventoryMenu::NativeOnInitialized()
{
	Super::NativeOnInitialized();
}

void UInventoryMenu::NativeConstruct()
{
	Super::NativeConstruct();

	PlayerCharacter = Cast<AInvSysCharacter>(GetOwningPlayerPawn());
}

bool UInventoryMenu::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent,
	UDragDropOperation* InOperation)
{
	return Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);

	// cast operation to item drag drop, ensure player is valid, call drop item on player
	
}
