#include "../../../header/Item/Controllers/GauntletItemController.h"

namespace Item
{
	namespace Controller
	{
		using namespace std;

		GauntletItemController::GauntletItemController(string _itemName) : ItemController(_itemName, ItemType::Gauntlet) {}
	}
}