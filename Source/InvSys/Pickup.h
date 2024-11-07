#pragma once

#include "CoreMinimal.h"
#include "InteractionInterface.h"
#include "InvSysCharacter.h"
#include "GameFramework/Actor.h"
#include "Pickup.generated.h"

class UDataTable;
class UItemBase;

UCLASS()
class INVSYS_API APickup : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:
	
	APickup();

	void InitializePickup(const TSubclassOf<UItemBase> BaseClass, const int32 InQuantity);

	void InitializeDrop(UItemBase* ItemToDrop, const int32 InQuantity);

	FORCEINLINE UItemBase* GetItemData() { return ItemReference; }

	
	virtual void BeginFocus() override;
	virtual void EndFocus() override;
	
protected:

	UPROPERTY(VisibleAnywhere, Category = "Pickup | Components")
	UStaticMeshComponent* PickupMesh;

	UPROPERTY(EditInstanceOnly, Category = "Pickup | Item Database")
	UDataTable* ItemDataTable;

	UPROPERTY(EditInstanceOnly, Category = "Pickup | Item Database")
	FName DesiredItemID;

	UPROPERTY(VisibleAnywhere, Category = "Pickup | Item Reference")
	UItemBase* ItemReference;

	UPROPERTY(EditInstanceOnly, Category = "Pickup | Item Database")
	int32 ItemQuantity;

	UPROPERTY(VisibleInstanceOnly, Category = "Pickup | Interaction")
	FInteractableData InstanceInteractableData;
	
	virtual void BeginPlay() override;
	
	virtual void Interact(AInvSysCharacter* PlayerCharacter) override;
	void UpdateInteractableData();
	
	void TakePickup(const AInvSysCharacter* Taker);

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
};
