#pragma once
#include <string>   // For String Operations

namespace Item
{
	// Create enum for All types of Items
	enum class ItemType 
	{
		Map,
		Sword,
		Shield,
		Armour,
		Bow,
		Gauntlet,
		Boot,
		Amulet,
		None
	};

	// the string representation of Item Type
	std::string ItemTypeToString(ItemType itemType) 
	{
		switch (itemType) 
		{
		case ItemType::Map:
			return "Map";
		case ItemType::Sword:
			return "Sword";
		case ItemType::Shield:
			return "Shield";
		case ItemType::Armour:
			return "Armour";
		case ItemType::Bow:
			return "Bow";
		case ItemType::Gauntlet:
			return "Gauntlets";
		case ItemType::Boot:
			return "Boots";
		case ItemType::Amulet:
			return "Amulet";
		default:
			return "Unknown";
		}
	}
}