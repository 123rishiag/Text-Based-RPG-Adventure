#include "../../../header/Item/Controllers/BootItemController.h"

namespace Item
{
	namespace Controller
	{
		using namespace std;

		BootItemController::BootItemController(string _itemName) : ItemController(_itemName, ItemType::Boot) {}
	}
}