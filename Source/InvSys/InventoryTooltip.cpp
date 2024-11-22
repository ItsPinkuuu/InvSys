#include "InventoryTooltip.h"

#include "InventoryItemSlot.h"
#include "ItemBase.h"
#include "Components/TextBlock.h"


void UInventoryTooltip::NativeConstruct()
{
	Super::NativeConstruct();

	const UItemBase* ItemBeingHovered = InventorySlotBeingHovered->GetItemReference();

	switch (ItemBeingHovered->ItemType)
	{
	case EItemType::Armor:
		ItemType->SetText(FText::FromString("Armor"));
		UsageText->SetVisibility(ESlateVisibility::Collapsed);
		break;
	case EItemType::Weapon:
		ItemType->SetText(FText::FromString("Weapon"));
		UsageText->SetVisibility(ESlateVisibility::Collapsed);
		break;
	case EItemType::Shield:
		ItemType->SetText(FText::FromString("Shield"));
		UsageText->SetVisibility(ESlateVisibility::Collapsed);
		break;
	case EItemType::Consumable:
		ItemType->SetText(FText::FromString("Consumable"));
		DamageValue->SetVisibility(ESlateVisibility::Collapsed);
		ArmorRating->SetVisibility(ESlateVisibility::Collapsed);
		break;
	case EItemType::Quest:
		ItemType->SetText(FText::FromString("Quest Item"));
		break;
	case EItemType::Mundane:
		ItemType->SetText(FText::FromString("Mundane Item"));
		DamageValue->SetVisibility(ESlateVisibility::Collapsed);
		ArmorRating->SetVisibility(ESlateVisibility::Collapsed);
		UsageText->SetVisibility(ESlateVisibility::Collapsed);
		break;

	default: ;
	}

	ItemName->SetText(ItemBeingHovered->ItemTextData.Name);
	DamageValue->SetText(FText::AsNumber(ItemBeingHovered->ItemStatistics.DamageValue));
	ArmorRating->SetText(FText::AsNumber(ItemBeingHovered->ItemStatistics.ArmorRating));
	UsageText->SetText(ItemBeingHovered->ItemTextData.UsageText);
	ItemDescription->SetText(ItemBeingHovered->ItemTextData.Description);

	const FString WeightInfo =
		{ "Weight: " + FString::SanitizeFloat(ItemBeingHovered->GetItemStackWeight()) };
	
	StackWeight->SetText(FText::FromString(WeightInfo));

	if (ItemBeingHovered->ItemNumericData.bIsStackable)
	{
		const FString StackInfo =
			{ "Max stack size: " + FString::FromInt(ItemBeingHovered->ItemNumericData.MaxStackSize) };
		
		MaxStackSize->SetText(FText::FromString(StackInfo));
	} else
	{
		MaxStackSize->SetVisibility(ESlateVisibility::Collapsed);
	}

	if (ItemBeingHovered->ItemStatistics.DamageValue > 0)
	{
		const FString DamageInfo =
			{ "Damage: " + FString::FromInt(ItemBeingHovered->ItemStatistics.DamageValue) };
		
		DamageValue->SetText(FText::FromString(DamageInfo));
	} else
	{
		DamageValue->SetVisibility(ESlateVisibility::Collapsed);
	}

	if (ItemBeingHovered->ItemStatistics.ArmorRating > 0)
	{
		const FString ArmorRatingInfo =
			{ "Rating: " + FString::FromInt(ItemBeingHovered->ItemStatistics.ArmorRating) };

		ArmorRating->SetText(FText::FromString(ArmorRatingInfo));
	} else
	{
		ArmorRating->SetVisibility(ESlateVisibility::Collapsed);
	}
}
