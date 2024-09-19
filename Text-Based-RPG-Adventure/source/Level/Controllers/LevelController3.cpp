#include "../../../header/Level/Controllers/LevelController3.h"

namespace Level
{
    namespace Controller
    {
        LevelController3::LevelController3(int _numberOfEnemies, CharacterType _enemyType)
            : LevelController(_numberOfEnemies, _enemyType, LevelNumber::Level3) { }

        void LevelController3::UpgradeCharacter(Character* _character)
        {
            if (_character->GetCharacterType() == CharacterType::Player) 
            {
                _character->AddItem(GetItem(ItemType::Shield));
                _character->AddSpecialAbility(GetSpecialAbility(SpecialAbilityType::Blocker));
                _character->IncreaseMaxHealth(20);
                _character->IncreaseMeleeDamage(20);
                _character->IncreaseDefence(20);
            }
        }
    }
}