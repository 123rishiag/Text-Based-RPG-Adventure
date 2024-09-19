#include "../../../header/Item/Controllers/ArmourItemController.h"

namespace Item
{
	namespace Controller
	{
		using namespace std;

		ArmourItemController::ArmourItemController(string _itemName) : ItemController(_itemName, ItemType::Armour) {}
	}
}