

#include "Components/ForceStrikeHealthComponent.h"

UForceStrikeHealthComponent::UForceStrikeHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;

}


void UForceStrikeHealthComponent::BeginPlay()
{
	Super::BeginPlay();
		

	Health = MaxHealth;
}