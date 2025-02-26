#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractionInterface.generated.h"

class AInvSysCharacter;

UENUM()
enum class EInteractableType : uint8
{
	Pickup UMETA(DisplayName = "Pickup"),
	NonePlayerCharacter UMETA(DisplayName = "NonePlayerCharacter"),
	Device UMETA(DisplayName = "Device"),
	Toggle UMETA(DisplayName = "Toggle"),
	Container UMETA(DisplayName = "Container")
};


USTRUCT()
struct FInteractableData
{
	GENERATED_USTRUCT_BODY()

	FInteractableData() : InteractableType(EInteractableType::Pickup),
	Name(FText::GetEmpty()),
	Action(FText::GetEmpty()),
	Quantity(0),
	InteractionDuration(0.0f)
	{
		
	}

	UPROPERTY(EditInstanceOnly)
	EInteractableType InteractableType;

	UPROPERTY(EditInstanceOnly)
	FText Name;
	
	UPROPERTY(EditInstanceOnly)
	FText Action;

	// Used only for pickups
	UPROPERTY(EditInstanceOnly)
	int8 Quantity;

	// Used for things like chests, doors, etc. That require a timer
	UPROPERTY(EditInstanceOnly)
	float InteractionDuration;
	
};


// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInteractionInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class INVSYS_API IInteractionInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void BeginFocus();

	virtual void EndFocus();

	virtual void BeginInteract();

	virtual void EndInteract();

	virtual void Interact(AInvSysCharacter* PlayerCharacter);


	FInteractableData InteractableData;
	
};
