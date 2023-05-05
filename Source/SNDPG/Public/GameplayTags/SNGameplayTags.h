// Copyright 2023 Michal Oginski.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

class UGameplayTagsManager;
/**
 * 
 */
struct SNDPG_API FSNGameplayTags
{
public:
	static const FSNGameplayTags& Get() {return GameplayTags;}
	static void InitializeNativeTags();
	static FGameplayTag FindTagByString(FString TagString, bool bMatchPartialString = false);

public:
	// Input
	FGameplayTag Input_Move;
	FGameplayTag Input_Look;

	// Abilities
	FGameplayTag Ability_Input_Melee;

protected:
	void AddAllTags(UGameplayTagsManager& Manager);
	void AddTag(FGameplayTag& OutTag, const ANSICHAR* TagName, const ANSICHAR* TagComment);
 
private:
	static FSNGameplayTags GameplayTags;
};
