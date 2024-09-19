#pragma once
#include "../../header/Item/ItemType.h"

namespace Item
{
	class ItemController
	{
	private:
		std::string itemName; // Name of Item
		ItemType itemType;

	public:
		ItemController(std::string _itemName, ItemType _itemType);
		virtual ~ItemController();

		// Getters
		std::string GetItemName() const;
		ItemType GetItemType() const;
	};
}