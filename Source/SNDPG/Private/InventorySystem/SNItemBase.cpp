// Copyright 2023 Michał Ogiński.


#include "InventorySystem/SNItemBase.h"

USNItemBase::USNItemBase()
	: Weight(0)
	, ItemCategory(EItemCategory::None)
	, ItemDisplayName(FText::FromString("Default Item Name"))
	, ItemDescription(FText::FromString("Default Item Description"))
	, UseActionText(FText::FromString("Default Use Action Text"))
{
}
