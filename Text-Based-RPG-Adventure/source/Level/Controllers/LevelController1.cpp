#include "../../../header/Level/Controllers/LevelController1.h"
#include "../../../header/Character/CharacterController.h"

namespace Level
{
    namespace Controller
    {
        using namespace Character;
        using namespace Item;
        using namespace Ability;

        LevelController1::LevelController1(int _numberOfEnemies, CharacterType _enemyType)
            : LevelController(_numberOfEnemies, _enemyType, LevelNumber::Level1) { }

        void LevelController1::UpgradeCharacter(CharacterController* _character)
        {
            if (_character->GetCharacterType() == CharacterType::Player)
            {
                _character->AddItem(GetItem(ItemType::Map));
                _character->IncreaseMaxHealth(20);
                _character->IncreaseMeleeDamage(20);
                _character->IncreaseDefence(20);
            }
        }
    }
}