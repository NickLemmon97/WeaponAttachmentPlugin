// Fill out your copyright notice in the Description page of Project Settings.

#include "../BlueprintableBaseSchematic.h"

void ABlueprintableBaseSchematic::OnBeginFire()
{
	Super::OnBeginFire();

	Blueprint_OnBeginFire();
}

void ABlueprintableBaseSchematic::OnFire()
{
	Super::OnFire();

	Blueprint_OnFire();
}

void ABlueprintableBaseSchematic::OnStopFire()
{
	Super::OnStopFire();

	Blueprint_OnStopFire();
}

void ABlueprintableBaseSchematic::OnBeginAltFire()
{
	Super::OnBeginAltFire();

	Blueprint_OnBeginAltFire();
}

void ABlueprintableBaseSchematic::OnAltFire()
{
	Super::OnAltFire();

	Blueprint_OnAltFire();
}

void ABlueprintableBaseSchematic::OnStopAltFire()
{
	Super::OnStopAltFire();

	Blueprint_OnStopAltFire();
}

void ABlueprintableBaseSchematic::OnEmptyClip()
{
	Super::OnEmptyClip();
	Blueprint_OnEmptyClip();
}

void ABlueprintableBaseSchematic::OnEndReload()
{
	Super::OnEndReload();

	Blueprint_OnEndReload();
}

void ABlueprintableBaseSchematic::OnStartReload()
{
	Super::OnStartReload();

	Blueprint_OnStartReload();
}

void ABlueprintableBaseSchematic::OnEquip()
{
	Super::OnEquip();

	Blueprint_OnEquip();
}

void ABlueprintableBaseSchematic::OnUnequip()
{
	Super::OnUnequip();

	Blueprint_OnUnequip();
}
