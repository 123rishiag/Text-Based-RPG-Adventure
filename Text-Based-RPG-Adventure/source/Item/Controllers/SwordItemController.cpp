#include "../../../header/Item/Controllers/SwordItemController.h"

namespace Item
{
	namespace Controller
	{
		using namespace std;

		SwordItemController::SwordItemController(string _itemName) : ItemController(_itemName, ItemType::Sword) {}
	}
}