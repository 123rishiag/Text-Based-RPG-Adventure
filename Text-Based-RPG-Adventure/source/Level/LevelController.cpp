#include "../../header/Level/LevelController.h"
#include "../../header/Character/CharacterController.h"
#include "../../header/Character/Controllers/EnemyCharacterController.h"
#include "../../header/Character/Controllers/BossEnemyCharacterController.h"

namespace Level
{
    using namespace Character;
    using namespace Character::Controller;
    using namespace Item;
    using namespace Ability;
    using namespace std;

    LevelController::LevelController(int _numberOfEnemies, CharacterType _enemyType, LevelNumber _levelNumber)
        : numberOfEnemies(_numberOfEnemies), enemyType(_enemyType), levelNumber(_levelNumber) {}

    LevelController::~LevelController() {}

    int LevelController::GetNumberOfEnemies() const { return numberOfEnemies; }
    CharacterType LevelController::GetEnemyType() const { return enemyType; }

    unique_ptr<CharacterController> LevelController::GetEnemy(CharacterType _characterType, int _enemyNumber, CharacterController* _character)
    {
        // Increase Difficulty as Level Increases
        float _difficultyFactor = static_cast<float>(GetLevelNumber()) / (static_cast<float>(LevelNumber::None) - 1.0f); // Difficulty of Level
        string _characterName;       // Name of Character
        int _health;                 // Health of Character
        int _healPercentage;         // Heal Percentage for Healing(1-100 only)
        int _meleeDamage;            // Melee Damage of Character
        int _meleeDamagePercentage;  // Melee Damage Percentage for Dynamic Melee Damage(1-100 only)
        int _rangedDamage;           // Ranged Damage of Character
        int _rangedDamagePercentage; // Ranged Damage Percentage for Dynamic Ranged Damage(1-100 only)
        int _defence;                // Defence of Character
        int _defencePercentage;      // Defence Percentage for Dynamic Defence(1-100 only)

        switch (_characterType) 
        {
        case CharacterType::Enemy:
            _characterName = "Enemy " + to_string(_enemyNumber);
            _health = static_cast<int>(_character->GetMaxHealth() * _difficultyFactor);
            _healPercentage = 0;
            _meleeDamage = static_cast<int>(_character->GetMeleeDamage() * _difficultyFactor);
            _meleeDamagePercentage = 20;
            _rangedDamage = static_cast<int>(_character->GetRangedDamage() * _difficultyFactor);
            _rangedDamagePercentage = 10;
            _defence = static_cast<int>(_character->GetDefence() * _difficultyFactor);
            _defencePercentage = 20;
            return make_unique<EnemyCharacterController>(_characterName, _health, _healPercentage,
                _meleeDamage, _meleeDamagePercentage,
                _rangedDamage, _rangedDamagePercentage,
                _defence, _defencePercentage);
            break;
        case CharacterType::BossEnemy:
            _characterName = "Murloc";
            _health = static_cast<int>(_character->GetMaxHealth() * _difficultyFactor);
            _healPercentage = 0;
            _meleeDamage = static_cast<int>(_character->GetMeleeDamage() * _difficultyFactor);
            _meleeDamagePercentage = 30;
            _rangedDamage = static_cast<int>(_character->GetRangedDamage() * _difficultyFactor);
            _rangedDamagePercentage = 20;
            _defence = static_cast<int>(_character->GetDefence() * _difficultyFactor);
            _defencePercentage = 30;
            return make_unique<BossEnemyCharacterController>(_characterName, _health, _healPercentage,
                _meleeDamage, _meleeDamagePercentage,
                _rangedDamage, _rangedDamagePercentage,
                _defence, _defencePercentage);
            break;
        default:
            return nullptr;
            break;
        }
    }

    unique_ptr<SpecialAbilityController> LevelController::GetSpecialAbility(SpecialAbilityType _specialAbilityType)
    {
        switch (_specialAbilityType) 
        {
        case SpecialAbilityType::CriticalHit:
            return unique_ptr<SpecialAbilityController>(new CriticalHit(.10));
        case SpecialAbilityType::Blocker:
            return unique_ptr<SpecialAbilityController>(new Blocker(.10));
        case SpecialAbilityType::LifeSteal:
            return unique_ptr<SpecialAbilityController>(new LifeSteal(.10));
        case SpecialAbilityType::RangedAttack:
            return unique_ptr<SpecialAbilityController>(new RangedAttack(.10));
        case SpecialAbilityType::GroundSlash:
            return unique_ptr<SpecialAbilityController>(new GroundSlash(.10));
        case SpecialAbilityType::SpeedDash:
            return unique_ptr<SpecialAbilityController>(new SpeedDash(.10));
        case SpecialAbilityType::HealthRegeneration:
            return unique_ptr<SpecialAbilityController>(new HealthRegeneration(.10));
        default:
            return nullptr;
        }
    }

    unique_ptr<ItemController> LevelController::GetItem(ItemType _itemType)
    {
        switch (_itemType) 
        {
        case ItemType::Map:
            return unique_ptr<ItemController>(new Map("World Map"));
        case ItemType::Sword:
            return unique_ptr<ItemController>(new Sword("Excalibur"));
        case ItemType::Shield:
            return unique_ptr<ItemController>(new Shield("Shield of Dragon"));
        case ItemType::Armour:
            return unique_ptr<ItemController>(new Armour("Chainmail"));
        case ItemType::Bow:
            return unique_ptr<ItemController>(new Bow("Hunter's Bow"));
        case ItemType::Gauntlet:
            return unique_ptr<ItemController>(new Gauntlets("Gauntlets of Azeroth"));
        case ItemType::Boot:
            return unique_ptr<ItemController>(new Boots("Boots of Azeroth"));
        case ItemType::Amulet:
            return unique_ptr<ItemController>(new Map("Amulet of Azeroth"));
        default:
            return nullptr;
        }
    }

    void LevelController::GenerateEnemies(CharacterController* _character)
    {
        for (int _currentEnemyNumber = 1; _currentEnemyNumber <= numberOfEnemies; _currentEnemyNumber++) 
        {
            unique_ptr<CharacterController> _currentEnemy = GetEnemy(enemyType, _currentEnemyNumber, _character);
            enemies.push_back(move(_currentEnemy));
        }
    }

    void LevelController::ShowEnemies() 
    {
        if (enemies.empty()) 
        {
            cout << "Empty";
        }
        for (auto& _currentEnemy : enemies) 
        {
            cout << _currentEnemy->GetCharacterName() << endl;
        }
    }

    CharacterController* LevelController::GetEnemyAtIndex(int _characterIndex) const
    {
        if (_characterIndex >= 0 && _characterIndex < enemies.size()) 
        {
            return enemies[_characterIndex].get();
        }
        else 
        {
            return nullptr;
        }
    }

    void LevelController::PopFirstEnemy() { enemies.erase(enemies.begin()); }

    LevelNumber LevelController::GetLevelNumber() const
    {
        return levelNumber;
    }
}