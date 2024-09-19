#include "../../../header/Level/Controllers/LevelController1.h"

namespace Level
{
    namespace Controller
    {
        LevelController1::LevelController1(int _numberOfEnemies, CharacterType _enemyType)
            : LevelController(_numberOfEnemies, _enemyType, LevelNumber::Level1) { }

        void LevelController1::UpgradeCharacter(Character* _character) 
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