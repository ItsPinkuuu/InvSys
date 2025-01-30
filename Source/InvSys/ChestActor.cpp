#include "ChestActor.h"

#include "ContainerInventoryPanel.h"
#include "InventoryComponent.h"
#include "PlayerHUD.h"
#include "Components/SlateWrapperTypes.h"

// Sets default values
AChestActor::AChestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);


	/** INVENTORY */

	Inventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("Inventory"));
	Inventory->SetSlotsCapacity(40);
	Inventory->SetWeightCapacity(100.0f);
	
}



// Called when the game starts or when spawned
void AChestActor::BeginPlay()
{
	Super::BeginPlay();

	HUD = Cast<APlayerHUD>(GetWorld()->GetFirstPlayerController()->GetHUD());

	InteractableData = InstanceInteractableData;
	
}

// Called every frame
void AChestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void AChestActor::BeginFocus()
{
	if (Mesh)
	{
		Mesh->SetRenderCustomDepth(true);
	}
}

void AChestActor::EndFocus()
{
	if (Mesh)
	{
		Mesh->SetRenderCustomDepth(false);
	}
}

void AChestActor::BeginInteract()
{
	return;
}

void AChestActor::Interact(AInvSysCharacter* PlayerCharacter)
{
	if (!HUD->bIsMenuVisible)
	{
		HUD->ToggleMenu();
	}
	
	// if (!HUD->bIsInventoryVisible)
	// {
	// 	HUD->DisplayInventory();
	// }
}

void AChestActor::EndInteract()
{
	// GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("End Interaction"));
	return;
}
