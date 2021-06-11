// Black Eye Galaxy Mission - C++ by Nick

#include "WorldSchematic.h"
#include "BaseSchematic.h"
#include "SchematicInventoryComponent.h"
#include "WeaponAttachmentComponent.h"

#include "GameFramework/Character.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AWorldSchematic::AWorldSchematic()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;


	//Create our box component for collision
	CollisionComponent = CreateDefaultSubobject<UBoxComponent>(FName("Schematic Collision Box"));
	//Set up the default collision
	CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	CollisionComponent->SetCollisionProfileName("OverlapAll");
	CollisionComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
	//Set the box as the root component
	SetRootComponent(CollisionComponent);

	//Create our static mesh component
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName("Schematic Mesh"));
	//Set the default collisions to no collisions
	StaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	StaticMeshComponent->SetCollisionProfileName("NoCollision");
	//Attach the mesh to the box
	StaticMeshComponent->SetupAttachment(RootComponent);

}

void AWorldSchematic::InteractWithObject_Implementation(ACharacter* PickingUpCharacter)
{
	if (PickingUpCharacter == nullptr)
	{
		UE_LOG(LogWeaponSchematic, Warning, TEXT("AWorldSchematic - PickupSchematic - PickingUpCharacter was null and cannot pickup the schematic"));
		return;
	}

	if (SchematicInfoTemplate == nullptr)
	{
		UE_LOG(LogWeaponSchematic, Error, TEXT("AWorldSchematic - PickupSchematic - SchematicInfoTemplate was null and cannot be spawned for the player to pickup"));
		return;
	}

	//Get all child actors in the Character that is picking this up
	TArray<AActor*> pcChildActors;
	PickingUpCharacter->GetAllChildActors(pcChildActors);

	//Loop through and try to find the Weapon Attachment component on the gun
	for (AActor* possibleGun : pcChildActors)
	{
		//Check if the actor has the weapon component
		if (UActorComponent* getComponent = possibleGun->GetComponentByClass(UWeaponAttachmentComponent::StaticClass()))
		{
			//Cast it to a weapon so we can use its functionality
			if (UWeaponAttachmentComponent* weaponComponent = Cast<UWeaponAttachmentComponent>(getComponent)) 
			{
				//Spawn our template Schematic
				ABaseSchematic* SpawnedSchematic = GetWorld()->SpawnActor<ABaseSchematic>(SchematicInfoTemplate);

				if (SpawnedSchematic == nullptr)
				{
					UE_LOG(LogWeaponSchematic, Error, TEXT("AWorldSchematic - PickupObject - After trying to spawn the schematic, it was a nullptr and cannot be equipped"));
					return;
				}
				weaponComponent->EquipSchematic(SpawnedSchematic);
				
				if(Destroy())
				{
					UE_LOG(LogWeaponSchematic, Log, TEXT("The world schematic has been picked up and will be destroyed.  AWorldSchematic"));
				}
			}
			else
			{
				UE_LOG(LogWeaponSchematic, Warning, TEXT("After getting a component of type WeaponAttachmentComponent through get component by class, it was a nullptr after casting.  AWorldSchematic - Pickuip Object"));
			}
		}
	}
}