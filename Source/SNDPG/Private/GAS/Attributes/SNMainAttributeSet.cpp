// Fill out your copyright notice in the Description page of Project Settings.


#include "GAS/Attributes/SNMainAttributeSet.h"
#include "GAS/SNAbilitySystemComponent.h"

USNMainAttributeSet::USNMainAttributeSet()
{
}

UWorld* USNMainAttributeSet::GetWorld() const
{
	const UObject* Outer = GetOuter();
	check(Outer);

	return Outer->GetWorld();
}

USNAbilitySystemComponent* USNMainAttributeSet::GetSNAbilitySystemComponent() const
{
	return Cast<USNAbilitySystemComponent>(GetOwningAbilitySystemComponent());
}
