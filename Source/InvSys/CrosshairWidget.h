#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CrosshairWidget.generated.h"


class AInvSysCharacter;

UCLASS()
class INVSYS_API UCrosshairWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	
	UPROPERTY()
	AInvSysCharacter* PlayerCharacter;

	
protected:
	
	virtual void NativeOnInitialized() override;
	
	virtual void NativeConstruct() override;
	
};
