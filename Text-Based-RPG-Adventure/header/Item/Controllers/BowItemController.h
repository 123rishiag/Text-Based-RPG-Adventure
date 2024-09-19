#pragma once
#include "../../../header/Item/ItemController.h"

namespace Item
{
	namespace Controller
	{
		class BowItemController : public ItemController
		{
		public:
			BowItemController(std::string _itemName);
		};
	}
}