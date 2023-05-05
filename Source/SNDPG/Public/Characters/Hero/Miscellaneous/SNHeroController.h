// Copyright 2023 Michal Oginski.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SNHeroController.generated.h"

class ASNHeroState;
class USNAbilitySystemComponent;
/**
 * 
 */
UCLASS()
class SNDPG_API ASNHeroController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ASNHeroController();

	UFUNCTION(BlueprintCallable, Category = "SN|PlayerController")
	ASNHeroState* GetSNPlayerState() const;
	
	UFUNCTION(BlueprintCallable, Category = "SN|PlayerController")
	USNAbilitySystemComponent* GetSNAbilitySystemComponent() const; 

protected:
	virtual void PreProcessInput(const float DeltaTime, const bool bGamePaused) override;
	virtual void PostProcessInput(const float DeltaTime, const bool bGamePaused) override;
	
};
