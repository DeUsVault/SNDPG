// Copyright 2023 Michal Oginski.

#include "GameplayTags/SNGameplayTags.h"
#include "GameplayTagsManager.h"

FSNGameplayTags FSNGameplayTags::GameplayTags;

void FSNGameplayTags::InitializeNativeTags()
{
	UGameplayTagsManager& Manager = UGameplayTagsManager::Get();

	GameplayTags.AddAllTags(Manager);

	Manager.DoneAddingNativeTags();
}

FGameplayTag FSNGameplayTags::FindTagByString(FString TagString, bool bMatchPartialString)
{
	const UGameplayTagsManager& Manager = UGameplayTagsManager::Get();
	FGameplayTag Tag = Manager.RequestGameplayTag(FName(*TagString), false);

	if(!Tag.IsValid() && bMatchPartialString)
	{
		FGameplayTagContainer AllTags;
		Manager.RequestAllGameplayTags(AllTags, true);

		for (const FGameplayTag TestTag : AllTags)
		{
			if(TestTag.ToString().Contains(TagString))
			{
				UE_LOG(LogTemp, Display, TEXT("Could not find exact match for tag [%s] but found partialo match on tag [%s]."), *TagString, *TestTag.ToString())
				Tag = TestTag;
				break;
			}
		}
	}
	return Tag;
}

void FSNGameplayTags::AddAllTags(UGameplayTagsManager& Manager)
{
	AddTag(Input_Move, "Input.Move", "Move input.");
	AddTag(Input_Look, "Input.Look", "Look input.");
	AddTag(Ability_Input_Melee, "Ability.Input.Melee", "Melee ability input.");
}

void FSNGameplayTags::AddTag(FGameplayTag& OutTag, const ANSICHAR* TagName, const ANSICHAR* TagComment)
{
	OutTag = UGameplayTagsManager::Get().AddNativeGameplayTag(FName(TagName), FString(TEXT("(Native) ")) + FString(TagComment));
}
