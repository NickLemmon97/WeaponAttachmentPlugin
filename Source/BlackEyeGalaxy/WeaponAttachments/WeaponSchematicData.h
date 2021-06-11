// Black Eye Galaxy Mission - C++ by Nick

#pragma once

#include "CoreMinimal.h"

/**
 * Here contiains information that will be a part of the weapon schematics
 * Things such as where it can attach
 */

//A Custom log category for outputting log messages
DECLARE_LOG_CATEGORY_EXTERN(LogWeaponSchematic, Log, Log);


//The type of weapon we are or type of schematic we are attaching
UENUM(BlueprintType)
enum class ESchematicWeaponType : uint8
{
	SWT_NONE        UMETA(DisplayName = "None"),
	//Primary Weapons	  		    
	SWT_SHOTGUN     UMETA(DisplayName = "Shotgun"),
	SWT_RIFLE       UMETA(DisplayName = "Rifle"),

	//Secondary Weapons
	SWT_PISTOL      UMETA(DisplayName = "Pistol"),

	//Special Weapons
	SWT_LASERRIFLE  UMETA(DisplayName = "Laser Rifle"),
	SWT_ENERGYSABER UMETA(DisplayName = "Energy Saber"),

	//Toolbelt
	SWT_FRAGGRENADE UMETA(DisplayName = "Frag Grenade"),
	SWT_STUNGRENADE UMETA(DisplayName = "Stun Grenade"),

	SWT_UNIVERSAL   UMETA(DisplayName = "Any Weapon"),
	SWT_MAX         UMETA(DisplayName = "Max"),
};


//The type of location attaching
UENUM(BlueprintType)
enum class ESchematicAttachmentLocation : uint8
{
	SAL_NONE      UMETA(DisplayName = "None"),
				  
	SAL_BARREL    UMETA(DisplayName = "Barrel"),
	SAL_MAGAZINE  UMETA(DisplayName = "Magazine"),
	SAL_SCOPE     UMETA(DisplayName = "Scope"),
	SAL_GRIP	  UMETA(DisplayName = "Grip"),

	SAL_MAX       UMETA(DisplayName = "Max"),
};


//The result of our attempt to attach a schematic
UENUM(BlueprintType)
enum class ESchematicAttachmentResult : uint8
{
	SAR_SUCCESS							UMETA(DisplayName = "Success"),

	SAR_ALREADYEQUIPPED					UMETA(DisplayName = "Already Equipped"),
	SAR_INCOMPATIBLEGUNTYPE				UMETA(DisplayName = "Incompatible Gun Types"),
	SAR_NOATTACHMENTLOCATIONAVAILABLE	UMETA(DisplayName = "No Attachment Location"),

	SAR_MAX								UMETA(DisplayName = "Max"),
};