#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InteractionWidget.generated.h"


class UProgressBar;
class UTextBlock;
struct FInteractableData;
class AInvSysCharacter;

UCLASS()
class INVSYS_API UInteractionWidget : public UUserWidget
{
	GENERATED_BODY()

	
public:

	UPROPERTY(VisibleAnywhere, Category = "InteractionWidget | Player Reference" )
	AInvSysCharacter* PlayerReference;

	void UpdateWidget( const FInteractableData* InteractableData ) const;

	
protected:

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "InteractionWidget | InteractableData")
	UTextBlock* NameText;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "InteractionWidget | InteractableData")
	UTextBlock* ActionText;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "InteractionWidget | InteractableData")
	UTextBlock* QuantityText;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "InteractionWidget | InteractableData")
	UTextBlock* KeyPressText;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "InteractionWidget | InteractableData")
	UProgressBar* InteractionProgressBar;

	UPROPERTY(VisibleAnywhere, meta = (BindWidget), Category = "InteractionWidget | InteractableData")
	float CurrentInteractionDuration;


	UFUNCTION(Category = "InteractionWidget | InteractableData")
	float UpdateInteractionProgress();
	
	virtual void NativeOnInitialized() override;
	
	virtual void NativeConstruct() override;
};
