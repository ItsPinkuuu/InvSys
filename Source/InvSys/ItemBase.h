#pragma once

#include "CoreMinimal.h"
#include "InvSysCharacter.h"
#include "Data/ItemDataStructs.h"
#include "ItemBase.generated.h"

class UInventoryComponent;

UCLASS()
class INVSYS_API UItemBase : public UObject
{
	GENERATED_BODY()

	
public:

	//=================================================================
	/** PROPERTIES & VARIABLES */
	//=================================================================

	
	// class ItemDataStruct* itemDataStruct;

	UPROPERTY()
	UInventoryComponent* OwningInventory;
	
	UPROPERTY(VisibleAnywhere, Category = "Item")
	FName ID;
	
	UPROPERTY(VisibleAnywhere, Category = "Item")
	int32 Quantity;

	UPROPERTY(VisibleAnywhere, Category = "Item")
	EItemType ItemType;

	UPROPERTY(VisibleAnywhere, Category = "Item")
	EItemQuality ItemQuality;

	UPROPERTY(VisibleAnywhere, Category = "Item")
	FItemStatistics ItemStatistics;

	UPROPERTY(VisibleAnywhere, Category = "Item")
	FItemTextData ItemTextData;

	UPROPERTY(VisibleAnywhere, Category = "Item")
	FItemNumericData ItemNumericData;

	UPROPERTY(VisibleAnywhere, Category = "Item")
	FItemAssetData ItemAssetData;

	bool bIsCopy;

	bool bIsPickup;


	//=================================================================
	/** FUNCTIONS */
	//=================================================================
	
	UItemBase();


	
	void ResetItemFlags(); 

	UFUNCTION(Category = "Item")
	UItemBase* CreateItemCopy() const;

	UFUNCTION(Category = "Item")
	FORCEINLINE float GetItemStackWeight() const { return Quantity * ItemNumericData.Weight; }

	UFUNCTION(Category = "Item")
	FORCEINLINE float GetItemSingleWeight() const { return ItemNumericData.Weight; }

	UFUNCTION(Category = "Item")
	FORCEINLINE bool IsFullItemStack() const { return Quantity == ItemNumericData.MaxStackSize; }

	UFUNCTION(Category = "Item")
	void SetQuantity(int32 NewQuantity);

	UFUNCTION(Category = "Item")
	virtual void Use(AInvSysCharacter* InvSysCharacter);
	

protected:

	bool operator==(const FName& OtherID) const
	{
		return this->ID == OtherID;
	}
		
};
