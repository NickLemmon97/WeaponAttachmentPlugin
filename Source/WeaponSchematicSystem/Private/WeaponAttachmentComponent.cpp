// Black Eye Galaxy Mission - C++ by Nick

#include "WeaponAttachmentComponent.h"
#include "BaseSchematic.h"

// Sets default values for this component's properties
UWeaponAttachmentComponent::UWeaponAttachmentComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}


// Called when the game starts
void UWeaponAttachmentComponent::BeginPlay()
{
	Super::BeginPlay();

	SpawnAndAttachInitialAttachments();
}

void UWeaponAttachmentComponent::SpawnAndAttachInitialAttachments()
{
	/**
	 * Loop through our InitialAttachments array
	 * Spawn the schematic and send it to be equipped
	 */

	for (TSubclassOf<ABaseSchematic> schematicTemplate : InitialAttachments)
	{
		ABaseSchematic* schematic = GetWorld()->SpawnActor<ABaseSchematic>(schematicTemplate);
		if (schematic != nullptr)
		{
			ESchematicAttachmentResult Result = EquipSchematic(schematic);

			if (Result != ESchematicAttachmentResult::SAR_SUCCESS)
			{
				UE_LOG(LogWeaponSchematic, Warning, TEXT("Schematic Equip Failed and attachment result was not SUCCESS"));
			}
		}
		else 
		{
			UE_LOG(LogWeaponSchematic, Warning, TEXT("Trying to spawn a schematic but it was null. func = SpawnAndAttachInitialAttachments in WeaponAttachmentComponent."));
			UE_LOG(LogWeaponSchematic, Warning, TEXT("If you are reading this then the Weapon Component was not able to spawn one of the attachments that was added to the InitialAttachementsArray"));
		}
	}
}

ESchematicAttachmentResult UWeaponAttachmentComponent::EquipSchematic(ABaseSchematic* equippedSchematic)
{
	if(equippedSchematic->GetIsEquipped())
	{
		//The schematic was already equipped and will not be equipped again
		UE_LOG(LogWeaponSchematic, Log, TEXT("Weapon Schematic was already equipped while trying to equip"));
		return ESchematicAttachmentResult::SAR_ALREADYEQUIPPED; 
	}


	ESchematicWeaponType equippedSchematicWeaponType = equippedSchematic->GetSchematicWeaponType();

	if (WeaponType != equippedSchematicWeaponType && //AND
		equippedSchematicWeaponType != ESchematicWeaponType::SWT_UNIVERSAL)
	{
		//The schematic isn't the correct type
		UE_LOG(LogWeaponSchematic, Log, TEXT("Weapon Schematic was not a compatible gun type to be able to equip"));
		return ESchematicAttachmentResult::SAR_INCOMPATIBLEGUNTYPE; 
	}

	/*If we don't want infinite attachments then we do the following:
	 *	Check if there is a spot to attach the weapon
	 *	If we don't find a location we don't equip
	 *	If we find a location we remove the location from the list of available attachments
	 *	We add the location to the list of used locations so when we unequip we have get the location back
	 */
	if (bAllowInfiniteAttachments == false)
	{
		ESchematicAttachmentLocation equippedSchematicAttachmentLocation = equippedSchematic->GetSchematicAttachmentLocation();
		bool bFoundSuitableLocation = false;

		//Look for a suitable location
		for (ESchematicAttachmentLocation location : AvailableAttachmentLocations)
		{
			if (location == equippedSchematicAttachmentLocation)
			{
				UE_LOG(LogWeaponSchematic, Log, TEXT("Location to attch schematic was found"));
				bFoundSuitableLocation = true;
				break;
			}
		}

		//We didn't find a suitable location
		if (bFoundSuitableLocation == false)
		{
			UE_LOG(LogWeaponSchematic, Log, TEXT("Could not attach schematic due to no location available to attach to"));
			return ESchematicAttachmentResult::SAR_NOATTACHMENTLOCATIONAVAILABLE;
		}

		//Remove the attachment location now that it is being taken and no longer available
		AvailableAttachmentLocations.RemoveSingle(equippedSchematicAttachmentLocation);
		//Add it to our used locations so we can un equip it later and get the location back
		UsedAttachmentLocations.Add(equippedSchematicAttachmentLocation);
	}

	equippedSchematic->EquipSchematic();
	equippedSchematic->OwningWeapon = this;

	AttachedSchematics.Add(equippedSchematic);

	return ESchematicAttachmentResult::SAR_SUCCESS; //The schematic was successfully equipped
}

bool UWeaponAttachmentComponent::UnequipSchematic(ABaseSchematic* unequippedSchematic)
{
	if (!unequippedSchematic->GetIsEquipped())
	{
		//The schematic wasn't equipped and will not be unequipped
		UE_LOG(LogWeaponSchematic, Log, TEXT("Weapon schematic was not equipped while trying to unequip it"));
		return false; 
	}

	if (bAllowInfiniteAttachments == false)
	{
		UsedAttachmentLocations.RemoveSingle(unequippedSchematic->GetSchematicAttachmentLocation());
		AvailableAttachmentLocations.Add(unequippedSchematic->GetSchematicAttachmentLocation());
	}
	
	unequippedSchematic->UnequipSchematic();
	unequippedSchematic->OwningWeapon = nullptr;

	AttachedSchematics.Remove(unequippedSchematic);

	UE_LOG(LogWeaponSchematic, Log, TEXT("Successfully unequipped the schematic"));
	return true; //The schematic was successfully unequipped
}

void UWeaponAttachmentComponent::BeginFire()
{
	for (ABaseSchematic* schematic : AttachedSchematics)
	{
		if (IsValid(schematic))
		{
			schematic->BeginFire();
		}
	}
}

void UWeaponAttachmentComponent::Fire()
{
	for (ABaseSchematic* schematic : AttachedSchematics)
	{
		if (IsValid(schematic))
		{
			schematic->Fire();
		}
	}
}

void UWeaponAttachmentComponent::EndFire()
{
	for (ABaseSchematic* schematic : AttachedSchematics)
	{
		if (IsValid(schematic))
		{
			schematic->StopFire();
		}
	}
}

void UWeaponAttachmentComponent::EmptiedClip()
{
	for (ABaseSchematic* schematic : AttachedSchematics)
	{
		if (IsValid(schematic))
		{
			schematic->EmptiedClip();
		}
	}
}

void UWeaponAttachmentComponent::StartReload()
{
	for (ABaseSchematic* schematic : AttachedSchematics)
	{
		if (IsValid(schematic))
		{
			schematic->StartReload();
		}
	}
}

void UWeaponAttachmentComponent::EndedReload()
{
	for (ABaseSchematic* schematic : AttachedSchematics)
	{
		if (IsValid(schematic))
		{
			schematic->EndReload();
		}
	}
}

void UWeaponAttachmentComponent::BeginAltFire()
{
	for (ABaseSchematic* schematic : AttachedSchematics)
	{
		if (IsValid(schematic))
		{
			schematic->StartAltFire();
		}
	}
}

void UWeaponAttachmentComponent::AltFire()
{
	for (ABaseSchematic* schematic : AttachedSchematics)
	{
		if (IsValid(schematic))
		{
			schematic->AltFire();
		}
	}
}

void UWeaponAttachmentComponent::StopAltFire()
{
	for (ABaseSchematic* schematic : AttachedSchematics)
	{
		if (IsValid(schematic))
		{
			schematic->EndAltFire();
		}
	}
}

