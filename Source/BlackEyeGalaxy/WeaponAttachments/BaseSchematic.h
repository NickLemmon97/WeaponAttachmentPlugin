// Black Eye Galaxy Mission - C++ by Nick

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "WeaponSchematicData.h"
#include "BaseSchematic.generated.h"

UCLASS()
class BLACKEYEGALAXY_API ABaseSchematic : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseSchematic();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UWeaponAttachmentComponent* OwningWeapon = nullptr;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess))
		ESchematicWeaponType SchematicWeaponType;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess))
		ESchematicAttachmentLocation SchematicAttachmentLocation;

	UPROPERTY(meta = (AllowPrivateAccess))
		bool bIsEquipped = false;

	//The following functions are triggered by their counterpart function below
	//These functions are the functions that are going to be overridden

	virtual void OnBeginFire();
	virtual void OnFire();
	virtual void OnStopFire();
	virtual void OnBeginAltFire();
	virtual void OnAltFire();
	virtual void OnStopAltFire();
	virtual void OnEmptyClip();
	virtual void OnEndReload();
	virtual void OnStartReload();

	//Used to change stats of the gun when the Schematic gets equipped
	virtual void OnEquip();
	//Used to revert the stats when the Schematic gets equipped
	virtual void OnUnequip();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


	//The function to be called from BP or C++ when the schematic is equipped
	UFUNCTION(BlueprintCallable)
		void EquipSchematic();

	//The function to be called from BP or C++ when the schematic is equipped
	UFUNCTION(BlueprintCallable)
		void UnequipSchematic();

	//Called from BP or C++ when the player starts firing
	UFUNCTION(BlueprintCallable)
		void BeginFire();

	//Called from BP or C++ when the player stops firing
	UFUNCTION(BlueprintCallable)
		void StopFire();

	//called from BP or C++ when the clip has been emptied
	UFUNCTION(BlueprintCallable)
		void EmptiedClip();

	//Called frin BP or C++ when the reload starts
	UFUNCTION(BlueprintCallable)
		void StartReload();

	//Called from BP or c++ when the reload ends
	UFUNCTION(BlueprintCallable)
		void EndReload();

	//Called once per shot
	UFUNCTION(BlueprintCallable)
		void Fire();

	//Called on the AltFire start
	UFUNCTION(BlueprintCallable)
		void StartAltFire();

	//Called on AltFire end
	UFUNCTION(BlueprintCallable)
		void EndAltFire();

	//Called while Alt firing
	UFUNCTION(BlueprintCallable)
		void AltFire();


	//Getter functions located below
	//Used to get the variables values in C++ and BP
	UFUNCTION(BlueprintPure)
		bool GetIsEquipped();

	UFUNCTION(BlueprintPure)
		ESchematicWeaponType GetSchematicWeaponType();

	UFUNCTION(BlueprintPure)
		ESchematicAttachmentLocation GetSchematicAttachmentLocation();
};
