#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DragItemVisual.generated.h"


class UItemBase;
class UTextBlock;
class UImage;
class UBorder;

UCLASS()
class INVSYS_API UDragItemVisual : public UUserWidget
{
	GENERATED_BODY()


public:

	FORCEINLINE void SetItemReference(UItemBase* ItemIn) { ItemReference = ItemIn; }
	FORCEINLINE UItemBase* GetItemReference() const { return ItemReference; }

	
	UPROPERTY(VisibleAnywhere, Category = "Drag Item Visual", meta=(BindWidget))
	UBorder* ItemBorder;

	UPROPERTY(VisibleAnywhere, Category = "Drag Item Visual", meta=(BindWidget))
	UImage* ItemIcon;

	UPROPERTY(VisibleAnywhere, Category = "Drag Item Visual", meta=(BindWidget))
	UTextBlock* ItemQuantity;

protected:
	
	UPROPERTY()
	UItemBase* ItemReference;

	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
};
