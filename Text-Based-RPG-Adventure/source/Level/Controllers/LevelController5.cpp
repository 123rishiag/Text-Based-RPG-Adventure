#include "../../../header/Level/Controllers/LevelController5.h"

namespace Level
{
    namespace Controller
    {
        LevelController5::LevelController5(int _numberOfEnemies, CharacterType _enemyType)
            : LevelController(_numberOfEnemies, _enemyType, LevelNumber::Level5) { }

        void LevelController5::UpgradeCharacter(Character* _character)
        {
            if (_character->GetCharacterType() == CharacterType::Player) 
            {
                _character->AddItem(GetItem(ItemType::Bow));
                _character->AddSpecialAbility(GetSpecialAbility(SpecialAbilityType::RangedAttack));
                _character->IncreaseMaxHealth(20);
                _character->IncreaseMeleeDamage(20);
                _character->IncreaseDefence(20);
            }
        }
    }
}