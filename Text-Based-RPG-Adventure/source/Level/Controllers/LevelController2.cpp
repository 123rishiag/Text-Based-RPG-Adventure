#include "../../../header/Level/Controllers/LevelController2.h"

namespace Level
{
    namespace Controller
    {
        LevelController2::LevelController2(int _numberOfEnemies, CharacterType _enemyType)
            : LevelController(_numberOfEnemies, _enemyType, LevelNumber::Level2) { }

        void LevelController2::UpgradeCharacter(Character* _character)
        {
            if (_character->GetCharacterType() == CharacterType::Player) 
            {
                _character->AddItem(GetItem(ItemType::Sword));
                _character->AddSpecialAbility(GetSpecialAbility(SpecialAbilityType::CriticalHit));
                _character->IncreaseMaxHealth(20);
                _character->IncreaseMeleeDamage(20);
                _character->IncreaseDefence(20);
            }
        }
    }
}