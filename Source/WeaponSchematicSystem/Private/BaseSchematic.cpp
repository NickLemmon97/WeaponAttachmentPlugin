// Black Eye Galaxy Mission - C++ by Nick

#include "BaseSchematic.h"
#include "WeaponAttachmentComponent.h"

#include "Components/StaticMeshComponent.h"

// Sets default values
ABaseSchematic::ABaseSchematic()
{
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void ABaseSchematic::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseSchematic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseSchematic::EquipSchematic()
{
	OnEquip();
}

void ABaseSchematic::OnEquip()
{
	//Trigger on EquipEvent
	GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Emerald, "Equipped a schematic");

	bIsEquipped = true;
}

void ABaseSchematic::UnequipSchematic()
{
	OnUnequip();
}

void ABaseSchematic::OnUnequip()
{
	//Trigger on Unequip event
	GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Emerald, "Equipped a schematic");

	bIsEquipped = false;
}

void ABaseSchematic::BeginFire()
{
	OnBeginFire();
}

void ABaseSchematic::OnBeginFire()
{
	GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Emerald, "Begining Firing");
}

void ABaseSchematic::OnFire()
{
	GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Emerald, "Firing");
}

void ABaseSchematic::StopFire()
{
	OnStopFire();
}

void ABaseSchematic::OnStopFire()
{
	GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Emerald, "Stopped Firing");
}

void ABaseSchematic::OnBeginAltFire()
{
	GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Emerald, "Begining alt Firing");
}

void ABaseSchematic::OnAltFire()
{
	GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Emerald, "Alt Firing");
}

void ABaseSchematic::OnStopAltFire()
{
	GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Emerald, "stopping alt Firing");
}

void ABaseSchematic::EmptiedClip()
{
	OnEmptyClip();
}

void ABaseSchematic::OnEmptyClip()
{
	GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Emerald, "Out of ammo");
}

void ABaseSchematic::StartReload()
{
	OnStartReload();
}

void ABaseSchematic::OnStartReload()
{
	GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Emerald, "Starting Reload");
}

void ABaseSchematic::EndReload()
{
	OnEndReload();
}

void ABaseSchematic::Fire()
{
	OnFire();
}

void ABaseSchematic::StartAltFire()
{
	OnBeginAltFire();
}

void ABaseSchematic::EndAltFire()
{
	OnStopAltFire();
}

void ABaseSchematic::AltFire()
{
	OnAltFire();
}

void ABaseSchematic::OnEndReload()
{
	GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Emerald, "Ending Reload");
}

bool ABaseSchematic::GetIsEquipped()
{
	return bIsEquipped;
}

ESchematicWeaponType ABaseSchematic::GetSchematicWeaponType()
{
	return SchematicWeaponType;
}

ESchematicAttachmentLocation ABaseSchematic::GetSchematicAttachmentLocation()
{
	return SchematicAttachmentLocation;
}

