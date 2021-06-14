// Black Eye Galaxy Mission - C++ by Nick

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WeaponSchematicData.h"
#include "WeaponAttachmentComponent.generated.h"

/*
* This component will be attached to the various guns in the game
* It will be used to handle attaching, removing and calling the various effects of the schematics
*/

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WEAPONSCHEMATICSYSTEM_API UWeaponAttachmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWeaponAttachmentComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void SpawnAndAttachInitialAttachments();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
		TArray<TSubclassOf<ABaseSchematic>> InitialAttachments;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
		TArray<class ABaseSchematic*> AttachedSchematics;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
		bool bAllowInfiniteAttachments = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
		TArray<ESchematicAttachmentLocation> AvailableAttachmentLocations;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess))
		TArray<ESchematicAttachmentLocation> UsedAttachmentLocations;

public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ESchematicWeaponType WeaponType;
		
	UFUNCTION(BlueprintCallable)
		ESchematicAttachmentResult EquipSchematic(class ABaseSchematic* equippedSchematic);

	UFUNCTION(BlueprintCallable)
		bool UnequipSchematic(class ABaseSchematic* unequippedSchematic);

	/**
	 * The following functions can be called from blueprints
	 * They will trigger the attached schematics functions when they are called
	 */
	UFUNCTION(BlueprintCallable)
		void BeginFire();
	UFUNCTION(BlueprintCallable)
		void Fire();
	UFUNCTION(BlueprintCallable)
		void EndFire();
	UFUNCTION(BlueprintCallable)
		void EmptiedClip();
	UFUNCTION(BlueprintCallable)
		void StartReload();
	UFUNCTION(BlueprintCallable)
		void EndedReload();
	UFUNCTION(BlueprintCallable)
		void BeginAltFire();
	UFUNCTION(BlueprintCallable)
		void AltFire();
	UFUNCTION(BlueprintCallable)
		void StopAltFire();

};
