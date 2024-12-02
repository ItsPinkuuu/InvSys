#include "ContainerInventoryPanel.h"

#include "ChestActor.h"
#include "InventoryComponent.h"
#include "InventoryItemSlot.h"
#include "ItemDragDropOperation.h"
#include "Components/TextBlock.h"
#include "Components/WrapBox.h"


void UContainerInventoryPanel::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	Container = Cast<AChestActor>(GetOwningPlayerPawn());

	if (Container)
	{
		InventoryReference = Container->GetInventory();
		
		if (InventoryReference)
		{
			InventoryReference->OnInventoryUpdated.AddUObject(this, &UContainerInventoryPanel::RefreshInventory);
			SetInfoText();
		}
		
	}
}

void UContainerInventoryPanel::SetInfoText() const
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

void UContainerInventoryPanel::RefreshInventory()
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

bool UContainerInventoryPanel::NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent,
	UDragDropOperation* InOperation)
{
	const UItemDragDropOperation* ItemDragDrop = Cast<UItemDragDropOperation>(InOperation);

	if (ItemDragDrop->SourceItem && InventoryReference)
	{
		UE_LOG(LogTemp, Warning, TEXT("Detected an item drop in Container Inventory Panel."))

		// return true will stop the drop operation at this widget
		return true;
	}
	// returning false will cause the drop operation to fall through to underlying widgets (if any)
	return false;
}
