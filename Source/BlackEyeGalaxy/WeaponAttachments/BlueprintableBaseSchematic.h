// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseSchematic.h"
#include "BlueprintableBaseSchematic.generated.h"

/**
 * 
 */
UCLASS()
class BLACKEYEGALAXY_API ABlueprintableBaseSchematic : public ABaseSchematic
{
	GENERATED_BODY()

public:

	virtual void OnBeginFire() override;
	virtual void OnFire() override;
	virtual void OnStopFire() override;
	virtual void OnBeginAltFire() override;
	virtual void OnAltFire() override;
	virtual void OnStopAltFire() override;
	virtual void OnEmptyClip() override;
	virtual void OnEndReload() override;
	virtual void OnStartReload() override;
	virtual void OnEquip() override;
	virtual void OnUnequip() override;

	UFUNCTION(BlueprintImplementableEvent)
	void Blueprint_OnBeginFire();
	UFUNCTION(BlueprintImplementableEvent)
	void Blueprint_OnFire();
	UFUNCTION(BlueprintImplementableEvent)
	void Blueprint_OnStopFire();
	UFUNCTION(BlueprintImplementableEvent)
	void Blueprint_OnBeginAltFire();
	UFUNCTION(BlueprintImplementableEvent)
	void Blueprint_OnAltFire();
	UFUNCTION(BlueprintImplementableEvent)
	void Blueprint_OnStopAltFire();
	UFUNCTION(BlueprintImplementableEvent)
	void Blueprint_OnEmptyClip();
	UFUNCTION(BlueprintImplementableEvent)
	void Blueprint_OnEndReload();
	UFUNCTION(BlueprintImplementableEvent)
	void Blueprint_OnStartReload();
	UFUNCTION(BlueprintImplementableEvent)
	void Blueprint_OnEquip();
	UFUNCTION(BlueprintImplementableEvent)
	void Blueprint_OnUnequip();
	
};
