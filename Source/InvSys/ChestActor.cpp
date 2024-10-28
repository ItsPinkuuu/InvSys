#include "ChestActor.h"

// Sets default values
AChestActor::AChestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);
	
}

// Called when the game starts or when spawned
void AChestActor::BeginPlay()
{
	Super::BeginPlay();
	
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
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Begin Interaction"));
}

void AChestActor::EndInteract()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("End Interaction"));
}

void AChestActor::Interact(AInvSysCharacter* PlayerCharacter)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, TEXT("Interacting"));
}

