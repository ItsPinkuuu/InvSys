#pragma once

#include "CoreMinimal.h"
#include "InteractionInterface.h"
#include "GameFramework/Actor.h"
#include "ChestActor.generated.h"

class APlayerHUD;
class UInventoryComponent;

UCLASS()
class INVSYS_API AChestActor : public AActor, public IInteractionInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChestActor();

	FORCEINLINE UInventoryComponent* GetInventory() const { return Inventory; }

protected:
	
	UPROPERTY(EditAnywhere, Category = "Chest Actor")
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditInstanceOnly, Category = "Chest Actor")
	FInteractableData InstanceInteractableData;

	UPROPERTY(VisibleAnywhere, Category = "Character | Inventory")
	UInventoryComponent* Inventory;

	UPROPERTY()
	APlayerHUD* HUD;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	virtual void BeginFocus() override;

	virtual void EndFocus() override;

	virtual void BeginInteract() override;

	virtual void EndInteract() override;

	virtual void Interact(AInvSysCharacter* PlayerCharacter) override;
};
