#include "../../../header/Item/Controllers/ShieldItemController.h"

namespace Item
{
	namespace Controller
	{
		using namespace std;

		ShieldItemController::ShieldItemController(string _itemName) : ItemController(_itemName, ItemType::Shield) {}
	}
}