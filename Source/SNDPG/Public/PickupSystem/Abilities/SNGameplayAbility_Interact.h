// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GAS/SNGameplayAbility.h"
#include "SNGameplayAbility_Interact.generated.h"

class USNInteractionWidgetComponent;

/**
 * 
 */
UCLASS()
class SNDPG_API UGameplayAbility_Interact : public USNGameplayAbility
{
	GENERATED_BODY()
	
public:

	UGameplayAbility_Interact(const FObjectInitializer& ObjectInitializer);

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	UFUNCTION(BlueprintCallable)
	void UpdateInteractions(const TArray<FSNInteractionOption>& InteractiveOptions);

	UFUNCTION(BlueprintCallable)
	void TriggerInteraction();
	
public:
	

protected:
	UPROPERTY(BlueprintReadWrite)
	TArray<FSNInteractionOption> CurrentOptions;

	UPROPERTY()
	TArray<TObjectPtr<UUserWidget>> Widgets;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Ability|Settings")
	float InteractionScanRate = 0.1f;

	UPROPERTY(EditDefaultsOnly, Category = "Ability|Settings")
	float InteractionScanRange = 500;

	UPROPERTY(EditDefaultsOnly, Category = "Ability|UI")
	TSoftClassPtr<UUserWidget> DefaultInteractionWidgetClass;
};
