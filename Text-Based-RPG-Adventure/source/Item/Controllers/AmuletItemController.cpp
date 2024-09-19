#include "../../../header/Item/Controllers/AmuletItemController.h"

namespace Item
{
	namespace Controller
	{
		using namespace std;

		AmuletItemController::AmuletItemController(string _itemName) : ItemController(_itemName, ItemType::Amulet) {}
	}
}