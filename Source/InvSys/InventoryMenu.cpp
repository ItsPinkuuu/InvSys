#include "InventoryMenu.h"
#include "InvSysCharacter.h"
#include "ItemBase.h"
#include "ItemDragDropOperation.h"



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

	// cast operation to item drag drop, ensure player is valid, call drop item on player
	const UItemDragDropOperation* ItemDragDrop = Cast<UItemDragDropOperation>(InOperation);

	if (PlayerCharacter && ItemDragDrop->SourceItem)
	{
		PlayerCharacter->DropItem(ItemDragDrop->SourceItem, ItemDragDrop->SourceItem->Quantity);
		return true;
	}

	return false;
}
