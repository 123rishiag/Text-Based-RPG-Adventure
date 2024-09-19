#include "../../header/Item/ItemController.h"

namespace Item
{
	using namespace std;

	ItemController::ItemController(string _itemName, ItemType _itemType) : itemName(_itemName), itemType(_itemType) {}

	ItemController::~ItemController() = default;

	string ItemController::GetItemName() const
	{
		return itemName + " (" + ItemTypeToString(GetItemType()) + ")";
	}

	ItemType ItemController::GetItemType() const
	{
		return itemType;
	}
}