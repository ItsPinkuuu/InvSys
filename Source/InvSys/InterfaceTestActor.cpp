// Fill out your copyright notice in the Description page of Project Settings.


#include "InterfaceTestActor.h"

// Sets default values
AInterfaceTestActor::AInterfaceTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	SetRootComponent(Mesh);

}

// Called when the game starts or when spawned
void AInterfaceTestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInterfaceTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



void AInterfaceTestActor::BeginFocus()
{
	if (Mesh)
	{
		Mesh->SetRenderCustomDepth(true);
	}
}

void AInterfaceTestActor::EndFocus()
{
	if (Mesh)
	{
		Mesh->SetRenderCustomDepth(false);
	}
}

void AInterfaceTestActor::BeginInteract()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Green, TEXT("Begin Interaction"));
}

void AInterfaceTestActor::Interact(AInvSysCharacter* PlayerCharacter)
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Cyan, TEXT("Interacting"));
}

void AInterfaceTestActor::EndInteract()
{
	GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, TEXT("End Interaction"));
}

