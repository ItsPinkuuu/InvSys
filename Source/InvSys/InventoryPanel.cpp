#include "InventoryPanel.h"

#include "InventoryComponent.h"
#include "InventoryItemSlot.h"
#include "InvSysCharacter.h"
#include "Components/TextBlock.h"
#include "Components/WrapBox.h"


void UInventoryPanel::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	PlayerCharacter = Cast<AInvSysCharacter>(GetOwningPlayerPawn());

	if (PlayerCharacter)
	{
		InventoryReference = PlayerCharacter->GetInventory();
		if (InventoryReference)
		{
			InventoryReference->OnInventoryUpdated.AddUObject(this, &UInventoryPanel::RefreshInventory);
			SetInfoText();
		}
		
	}
}

void UInventoryPanel::SetInfoText() const
{
	const FString WeightInfoValue {
		FString::SanitizeFloat(InventoryReference->GetInventoryTotalWeight()) + "/"
		+ FString::SanitizeFloat(InventoryReference->GetWeightCapacity())
	};
	
	const FString CapacityInfoValue {
		FString::FromInt(InventoryReference->GetInventoryContents().Num()) + "/"
		+ FString::FromInt(InventoryReference->GetSlotsCapacity())
	};
	
	WeightInfo->SetText(FText::FromString(WeightInfoValue));
	CapacityInfo->SetText(FText::FromString(CapacityInfoValue));
}

void UInventoryPanel::RefreshInventory()
{
	if (InventoryReference && InventorySlotClass)
	{
		InventoryPanel->ClearChildren();

		for (UItemBase* const& InventoryItem : InventoryReference->GetInventoryContents())
		{
			UInventoryItemSlot* ItemSlot = CreateWidget<UInventoryItemSlot>(this, InventorySlotClass);
			ItemSlot->SetItemReference(InventoryItem);

			InventoryPanel->AddChildToWrapBox(ItemSlot);
		}

		SetInfoText();
	}
}

bool UInventoryPanel::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent,
	UDragDropOperation* InOperation)
{
	return Super::NativeOnDrop(InGeometry, InDragDropEvent, InOperation);
}
