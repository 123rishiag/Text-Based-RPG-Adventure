#include "../../../header/Item/Controllers/BowItemController.h"

namespace Item
{
	namespace Controller
	{
		using namespace std;

		BowItemController::BowItemController(string _itemName) : ItemController(_itemName, ItemType::Bow) {}
	}
}