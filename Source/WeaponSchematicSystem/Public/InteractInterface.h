// Black Eye Galaxy Mission - C++ by Nick
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractInterface.generated.h"


UINTERFACE(Blueprintable)
class WEAPONSCHEMATICSYSTEM_API UInteractInterface : public UInterface
{
	GENERATED_BODY()
};


class IInteractInterface
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void InteractWithObject(class ACharacter* PickingUpCharacter);
};