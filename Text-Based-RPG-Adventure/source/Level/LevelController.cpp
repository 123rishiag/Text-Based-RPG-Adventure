#include "../../header/Level/LevelController.h"

namespace Level
{
    using namespace std;

    LevelController::LevelController(int _numberOfEnemies, CharacterType _enemyType, LevelNumber _levelNumber)
        : numberOfEnemies(_numberOfEnemies), enemyType(_enemyType), levelNumber(_levelNumber) {}

    LevelController::~LevelController() {}

    int LevelController::GetNumberOfEnemies() const { return numberOfEnemies; }
    CharacterType LevelController::GetEnemyType() const { return enemyType; }

    unique_ptr<Character> LevelController::GetEnemy(CharacterType _characterType, int _enemyNumber, Character* _character) 
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
            return make_unique<Enemy>(_characterName, _health, _healPercentage,
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
            return make_unique<BossEnemy>(_characterName, _health, _healPercentage,
                _meleeDamage, _meleeDamagePercentage,
                _rangedDamage, _rangedDamagePercentage,
                _defence, _defencePercentage);
            break;
        default:
            return nullptr;
            break;
        }
    }

    unique_ptr<SpecialAbility> LevelController::GetSpecialAbility(SpecialAbilityType _specialAbilityType) 
    {
        switch (_specialAbilityType) 
        {
        case SpecialAbilityType::CriticalHit:
            return unique_ptr<SpecialAbility>(new CriticalHit(.10));
        case SpecialAbilityType::Blocker:
            return unique_ptr<SpecialAbility>(new Blocker(.10));
        case SpecialAbilityType::LifeSteal:
            return unique_ptr<SpecialAbility>(new LifeSteal(.10));
        case SpecialAbilityType::RangedAttack:
            return unique_ptr<SpecialAbility>(new RangedAttack(.10));
        case SpecialAbilityType::GroundSlash:
            return unique_ptr<SpecialAbility>(new GroundSlash(.10));
        case SpecialAbilityType::SpeedDash:
            return unique_ptr<SpecialAbility>(new SpeedDash(.10));
        case SpecialAbilityType::HealthRegeneration:
            return unique_ptr<SpecialAbility>(new HealthRegeneration(.10));
        default:
            return nullptr;
        }
    }

    unique_ptr<Item> LevelController::GetItem(ItemType _itemType)
    {
        switch (_itemType) 
        {
        case ItemType::Map:
            return unique_ptr<Item>(new Map("World Map"));
        case ItemType::Sword:
            return unique_ptr<Item>(new Sword("Excalibur"));
        case ItemType::Shield:
            return unique_ptr<Item>(new Shield("Shield of Dragon"));
        case ItemType::Armour:
            return unique_ptr<Item>(new Armour("Chainmail"));
        case ItemType::Bow:
            return unique_ptr<Item>(new Bow("Hunter's Bow"));
        case ItemType::Gauntlets:
            return unique_ptr<Item>(new Gauntlets("Gauntlets of Azeroth"));
        case ItemType::Boots:
            return unique_ptr<Item>(new Boots("Boots of Azeroth"));
        case ItemType::Amulet:
            return unique_ptr<Item>(new Map("Amulet of Azeroth"));
        default:
            return nullptr;
        }
    }

    void LevelController::GenerateEnemies(Character* _character) 
    {
        for (int _currentEnemyNumber = 1; _currentEnemyNumber <= numberOfEnemies; _currentEnemyNumber++) 
        {
            unique_ptr<Character> _currentEnemy = GetEnemy(enemyType, _currentEnemyNumber, _character);
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

    Character* LevelController::GetEnemyAtIndex(int _characterIndex) const 
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