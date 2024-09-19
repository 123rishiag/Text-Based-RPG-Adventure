#include "../../../header/Item/Controllers/MapItemController.h"

namespace Item
{
	namespace Controller
	{
		using namespace std;

		MapItemController::MapItemController(string _itemName) : ItemController(_itemName, ItemType::Map) {}
	}
}