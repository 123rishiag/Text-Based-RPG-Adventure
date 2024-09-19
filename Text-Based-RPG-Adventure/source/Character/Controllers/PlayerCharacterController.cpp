#include "../../../header/Character/Controllers/PlayerCharacterController.h"

namespace Character
{
    namespace Controller
    {
        using namespace std;

        PlayerCharacterController::PlayerCharacterController(std::string _characterName, int _health, int _healPercentage, int _meleeDamage,
            int _meleeDamagePercentage, int _rangedDamage, int _rangedDamagePercentage, int _defence, int _defencePercentage)
            : CharacterController(_characterName, _health, _healPercentage, _meleeDamage, _meleeDamagePercentage, _rangedDamage,
                _rangedDamagePercentage, _defence, _defencePercentage, CharacterType::Player) { }
    }
}