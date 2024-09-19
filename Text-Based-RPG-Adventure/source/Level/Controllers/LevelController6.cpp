#include "../../../header/Level/Controllers/LevelController6.h"
#include<iostream>

namespace Level
{
    namespace Controller
    {
        using namespace std;

        LevelController6::LevelController6(int _numberOfEnemies, CharacterType _enemyType)
            : LevelController(_numberOfEnemies, _enemyType, LevelNumber::Level6) { }

        void LevelController6::UpgradeCharacter(Character* _character)
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
                _character->AddItem(GetItem(ItemType::Gauntlets));
                _character->AddItem(GetItem(ItemType::Boots));
                _character->AddItem(GetItem(ItemType::Amulet));
                _character->AddSpecialAbility(GetSpecialAbility(SpecialAbilityType::GroundSlash));
                _character->AddSpecialAbility(GetSpecialAbility(SpecialAbilityType::SpeedDash));
                _character->AddSpecialAbility(GetSpecialAbility(SpecialAbilityType::HealthRegeneration));
                cout << "--------------------------------------------------" << endl;
            }
        }
    }
}