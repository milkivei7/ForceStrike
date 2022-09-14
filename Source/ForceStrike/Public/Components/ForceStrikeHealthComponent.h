

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ForceStrikeHealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FORCESTRIKE_API UForceStrikeHealthComponent : public UActorComponent
{
    GENERATED_BODY()

  public:
    UForceStrikeHealthComponent();

    float GetHealth() const { return Health; }

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    float MaxHealth = 100.0f;

	virtual void BeginPlay() override;

	private:
    float Health = 0.0f;

};
