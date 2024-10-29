#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"


class AInvSysCharacter;

UCLASS()
class INVSYS_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

public:
	
	UPROPERTY()
	AInvSysCharacter* PlayerCharacter;

	
protected:
	
	virtual void NativeOnInitialized() override;
	
	virtual void NativeConstruct() override;
	
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent,
		UDragDropOperation* InOperation) override;
	
};
