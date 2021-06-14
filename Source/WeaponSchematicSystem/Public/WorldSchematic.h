// Black Eye Galaxy Mission - C++ by Nick

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractInterface.h"
#include "WeaponSchematicData.h"
#include "WorldSchematic.generated.h"


/**
 *  This is the pickup class that will be spawned in the world for the player to pickup
 *  It contains a Pickup Function and the schematic
 */
UCLASS()
class WEAPONSCHEMATICSYSTEM_API AWorldSchematic : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWorldSchematic();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		class UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		class UBoxComponent* CollisionComponent;

	//This is the type of schematic that we want to create
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TSubclassOf<class ABaseSchematic> SchematicInfoTemplate;

	//Our implementation of the PickupSchematic function from the pickup interface
	void InteractWithObject_Implementation(class ACharacter* PickingUpCharacter);

};
