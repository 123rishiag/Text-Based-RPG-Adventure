#include "../../../header/Level/Controllers/LevelController6.h"
#include "../../../header/Character/CharacterController.h"
#include <iostream>

namespace Level
{
    namespace Controller
    {
        using namespace Character;
        using namespace Item;
        using namespace std;

        LevelController6::LevelController6(int _numberOfEnemies, CharacterType _enemyType)
            : LevelController(_numberOfEnemies, _enemyType, LevelNumber::Level6) { }

        void LevelController6::UpgradeCharacter(CharacterController* _character)
        {
            if (_character->GetCharacterType() == CharacterType::Player) 
            {
                _character->IncreaseMaxHealth(20);
                _character->IncreaseMeleeDamage(20);
                _character->IncreaseDefence(20);
            }
            else if (_character->GetCharacterType() == CharacterType::BossEnemy) 
            {
                cout << _character->GetCharacterName() << " recieves the following upgrades: " << endl;
                _character->AddItem(GetItem(ItemType::Gauntlet));
                _character->AddItem(GetItem(ItemType::Boot));
                _character->AddItem(GetItem(ItemType::Amulet));
                _character->AddSpecialAbility(GetSpecialAbility(SpecialAbilityType::GroundSlash));
                _character->AddSpecialAbility(GetSpecialAbility(SpecialAbilityType::SpeedDash));
                _character->AddSpecialAbility(GetSpecialAbility(SpecialAbilityType::HealthRegeneration));
                cout << "--------------------------------------------------" << endl;
            }
        }
    }
}