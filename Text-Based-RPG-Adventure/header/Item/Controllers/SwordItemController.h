#pragma once
#include "../../../header/Item/ItemController.h"

namespace Item
{
	namespace Controller
	{
		class SwordItemController : public ItemController
		{
		public:
			SwordItemController(std::string _itemName);
		};
	}
}