// Black Eye Galaxy Mission - C++ by Nick

#include "../SchematicInventoryComponent.h"

// Sets default values for this component's properties
USchematicInventoryComponent::USchematicInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}


// Called when the game starts
void USchematicInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

}


// Called every frame
void USchematicInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

