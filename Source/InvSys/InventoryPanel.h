#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventoryPanel.generated.h"

class UWrapBox;
class UTextBlock;
class UInventoryItemSlot;
class UInventoryComponent;
class AInvSysCharacter;



UCLASS()
class INVSYS_API UInventoryPanel : public UUserWidget
{
	GENERATED_BODY()


public:

	UFUNCTION()
	void RefreshInventory();

	UFUNCTION()
	void SortByID();

	UPROPERTY(meta=(BindWidget))
	UWrapBox* InventoryPanel;

	UPROPERTY(meta=(BindWidget))
	UTextBlock* WeightInfo;

	UPROPERTY(meta=(BindWidget))
	UTextBlock* CapacityInfo;

	UPROPERTY()
	AInvSysCharacter* PlayerCharacter;

	UPROPERTY()
	UInventoryComponent* InventoryReference;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UInventoryItemSlot> InventorySlotClass;


protected:

	void SetInfoText() const;
	
	virtual void NativeOnInitialized() override;
	
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent,
		UDragDropOperation* InOperation) override;
};
