#include "../../../header/Level/Controllers/LevelController4.h"
#include "../../../header/Character/CharacterController.h"

namespace Level
{
    namespace Controller
    {
        using namespace Character;
        using namespace Item;

        LevelController4::LevelController4(int _numberOfEnemies, CharacterType _enemyType)
            : LevelController(_numberOfEnemies, _enemyType, LevelNumber::Level4) { }

        void LevelController4::UpgradeCharacter(CharacterController* _character)
        {
            if(_character->GetCharacterType() == CharacterType::Player) 
            {
                _character->AddItem(GetItem(ItemType::Armour));
                _character->AddSpecialAbility(GetSpecialAbility(SpecialAbilityType::LifeSteal));
                _character->IncreaseMaxHealth(20);
                _character->IncreaseMeleeDamage(20);
                _character->IncreaseDefence(20);
            }
        }
    }
}