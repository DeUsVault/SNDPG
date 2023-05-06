// Copyright 2023 Michal Oginski.

#pragma once

#include "CoreMinimal.h"
#include "GAS/Attributes/SNMainAttributeSet.h"
#include "SNBasicAttributes.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class SNDPG_API USNBasicAttributes : public USNMainAttributeSet
{
	GENERATED_BODY()

public:
	USNBasicAttributes();
	
	ATTRIBUTE_ACCESSORS(USNBasicAttributes, Health);
	ATTRIBUTE_ACCESSORS(USNBasicAttributes, MaxHealth);
	ATTRIBUTE_ACCESSORS(USNBasicAttributes, Resource);
	ATTRIBUTE_ACCESSORS(USNBasicAttributes, MaxResource);

protected:
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldValue);
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldValue);
	
	UFUNCTION()
	void OnRep_Resource(const FGameplayAttributeData& OldValue);
	UFUNCTION()
	void OnRep_MaxResource(const FGameplayAttributeData& OldValue);
	
	virtual bool PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;

	void ClampAttribute(const FGameplayAttribute& Attribute, float& NewValue) const;

private:
	bool bOutOfHealth = false;
	
private:
	// The current health attribute.  The health will be capped by the max health attribute.  Health is hidden from modifiers so only executions can modify it.
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "SN|Health", Meta = (HideFromModifiers, AllowPrivateAccess = true))
	FGameplayAttributeData Health;

	// The current max health attribute.  Max health is an attribute since gameplay effects can modify it.
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "SN|Health", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxHealth;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Resource, Category = "SN|Resource", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Resource;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxResource, Category = "SN|Resource", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxResource;
};
