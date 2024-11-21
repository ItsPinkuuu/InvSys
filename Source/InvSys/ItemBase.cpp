#include "ItemBase.h"

#include "InventoryComponent.h"


UItemBase::UItemBase() : bIsCopy(false), bIsPickup(false)
{
	
}

void UItemBase::ResetItemFlags()
{
	bIsCopy = false;
	bIsPickup = false;
}

UItemBase* UItemBase::CreateItemCopy() const
{
	UItemBase* ItemCopy = NewObject<UItemBase>(StaticClass());

	ItemCopy->ID = this->ID;
	ItemCopy->Quantity = this->Quantity;
	ItemCopy->ItemQuality = this->ItemQuality;
	ItemCopy->ItemType = this->ItemType;
	ItemCopy->ItemTextData = this->ItemTextData;
	ItemCopy->ItemNumericData = this->ItemNumericData;
	ItemCopy->ItemStatistics = this->ItemStatistics;
	ItemCopy->ItemAssetData = this->ItemAssetData;

	return ItemCopy;
}

void UItemBase::SetQuantity( const int32 NewQuantity)
{
	if (NewQuantity != this->Quantity)
	{
		Quantity = FMath::Clamp(NewQuantity,
			0,
			this->ItemNumericData.bIsStackable ? this->ItemNumericData.MaxStackSize : 1);

		if (this->OwningInventory)
		{
			if (this->Quantity <= 0)
			{
				this->OwningInventory->RemoveSingleInstanceOfItem(this);
			}
		} else
		{
			UE_LOG(LogTemp, Error, TEXT("ItemBase OwningInventory was null!"));
		}
	}
	
}

void UItemBase::Use(AInvSysCharacter* InvSysCharacter)
{
	
}
