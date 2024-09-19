#include "../../header/Character/CharacterController.h"
#include "../../header/Utility/Random.h"

namespace Character
{
    using namespace Utility;
    using namespace std;

    CharacterController::CharacterController(string _characterName, int _health, int _healPercentage, int _meleeDamage,
        int _meleeDamagePercentage, int _rangedDamage, int _rangedDamagePercentage, int _defence, int _defencePercentage,
        CharacterType _characterType) : characterName(_characterName), health(_health), healPercentage(_healPercentage), 
        meleeDamage(_meleeDamage), meleeDamagePercentage(_meleeDamagePercentage), rangedDamage(_rangedDamage),
        rangedDamagePercentage(_rangedDamagePercentage), defence(_defence), defencePercentage(_defencePercentage),
        characterType(_characterType)
    {
        // Starting Values of Other Members
        maxHealth = health;
        healAmount = static_cast<int>(maxHealth * healPercentage / 100);
        minMeleeDamage = static_cast<int>(meleeDamage - (meleeDamage * meleeDamagePercentage / 100));
        maxMeleeDamage = static_cast<int>(meleeDamage + (meleeDamage * meleeDamagePercentage / 100));
        minRangedDamage = static_cast<int>(rangedDamage - (rangedDamage * rangedDamagePercentage / 100));
        maxRangedDamage = static_cast<int>(rangedDamage + (rangedDamage * rangedDamagePercentage / 100));
        minDefence = static_cast<int>(defence - (defence * defencePercentage / 100));
        maxDefence = static_cast<int>(defence + (defence * defencePercentage / 100));
    }

    CharacterController::~CharacterController() = default;

    string CharacterController::GetCharacterName() const 
    {
        return characterName + "(" + CharacterTypeToString(GetCharacterType()) + ")";
    }
    int CharacterController::GetHealth() const { return health; }
    int CharacterController::GetHeal() const { return healAmount; }
    int CharacterController::GetMeleeDamage() const 
    {      
        // Player will get Random Damage always by the enemy
        return Random::GetRandomNumber(minMeleeDamage, maxMeleeDamage);
    }
    int CharacterController::GetRangedDamage() const 
    {
        // Player will get Random Damage always by the enemy
        return Random::GetRandomNumber(minRangedDamage, maxRangedDamage);
    }
    int CharacterController::GetDefence() const 
    {
        // Player will get Random Damage always by the enemy
        return Random::GetRandomNumber(minDefence, maxDefence);
    }
    int CharacterController::GetMaxHealth() const { return maxHealth; }

    void CharacterController::EnableCanBlock() { canBlock = true; }
    void CharacterController::DisableCanTakeDamage() { canTakeDamage = false; }

    void CharacterController::IncreaseMaxHealth(int _increaseHealthPercentage) 
    {
        int _increasedMaxHealth = static_cast<int>(static_cast<float>(_increaseHealthPercentage) / 100.0f 
            * static_cast<float>(maxHealth));
        maxHealth += _increasedMaxHealth;
        cout << GetCharacterName() << "'s Max Health Increased by " << _increasedMaxHealth << "(" << _increaseHealthPercentage
            << " %) points." << endl;
        // Setting Health to Max Health
        health = maxHealth;
    }

    void CharacterController::IncreaseMeleeDamage(int _increaseDamagePercentage) 
    {
        int _increasedMeleeDamage = static_cast<int>(static_cast<float>(_increaseDamagePercentage) / 100.0f 
            * static_cast<float>(meleeDamage));
        meleeDamage += _increasedMeleeDamage;
        cout << GetCharacterName() << "'s Melee Damage Increased by " << _increasedMeleeDamage << "(" << _increaseDamagePercentage
            << " %) points." << endl;
        // Setting Min and Max Melee Damage
        minMeleeDamage = static_cast<int>(meleeDamage - (meleeDamage * meleeDamagePercentage / 100));
        maxMeleeDamage = static_cast<int>(meleeDamage + (meleeDamage * meleeDamagePercentage / 100));
    }

    void CharacterController::IncreaseDefence(int _increaseDefencePercentage) 
    {
        int _increasedDefence = static_cast<int>(static_cast<float>(_increaseDefencePercentage) / 100.0f 
            * static_cast<float>(defence));
        defence += _increasedDefence;
        cout << GetCharacterName() << "'s Defence Increased by " << _increasedDefence << "(" << _increaseDefencePercentage
            << " %) points." << endl;
        // Settting Min and Max Defence
        minDefence = static_cast<int>(defence - (defence * defencePercentage / 100));
        maxDefence = static_cast<int>(defence + (defence * defencePercentage / 100));
    }

    void CharacterController::ShowCharacterName() 
    {
        cout << "Character's Name is " << GetCharacterName() << "." << endl;
    }
    void CharacterController::ShowHealth() 
    {
        cout << GetCharacterName() << "\'s Current Health is " << GetHealth() << " points." << endl;
    }
    void CharacterController::ShowMaxHealth() 
    {
        cout << GetCharacterName() << "\'s Max Health is " << GetMaxHealth() << " points and it can heal by " << healAmount 
            << " points." << endl;
    }
    void CharacterController::ShowMeleeDamage() 
    {
        cout << GetCharacterName() << "\'s Melee Damage can be between " << minMeleeDamage << " and " << maxMeleeDamage 
            << " points." << endl;
    }
    void CharacterController::ShowRangedDamage() 
    {
        cout << GetCharacterName() << "\'s Ranged Damage can be between "  << minRangedDamage << " and " << maxRangedDamage 
            << " points." << endl;
    }
    void CharacterController::ShowDefence() 
    {
        cout << GetCharacterName() << "\'s Defence can be between " << minDefence << " and " << maxDefence << " points." << endl;
    }
    void CharacterController::ShowStats() 
    {
        ShowCharacterName();
        ShowMaxHealth();
        ShowMeleeDamage();
        ShowRangedDamage();
        ShowDefence();
    }
    void CharacterController::ShowItems() 
    {
        cout << GetCharacterName() << " have following Items in the inventory: " << endl;
        for (int i = 0; i < items.size(); i++) 
        {
            cout << "Item " << i + 1 << ": "  << ItemTypeToString(items[i]->GetItemType()) << " -> " << items[i]->GetItemName() 
                << endl;
        }
    }
    void CharacterController::ShowSpecialAbilities() 
    {
        cout << GetCharacterName() << " have following Special Abilities in the skillset: " << endl;
        for (int i = 0; i < specialAbilities.size(); i++) 
        {
            cout << "Special Ability " << i + 1 << ": " << SpecialAbilityTypeToString(specialAbilities[i]->GetSpecialAbilityType())
                << " with Activation Probability(" << specialAbilities[i]->GetSpecialAbilityProbability() * 100.0 << " %)." << endl;
        }
    }

    int CharacterController::GetItemLocation(ItemType _itemType) const 
    {
        int _itemLocation;
        if (items.size() == 0) 
        {
            _itemLocation = -1;
        }
        else 
        {
            int i = 0;
            do 
            {
                if (items[i]->GetItemType() == _itemType) 
                {
                    _itemLocation = i;
                }
                i += 1;
            } while (i < items.size() && _itemLocation == -1);
        }
        return _itemLocation;
    }

    void CharacterController::AddItem(unique_ptr<Item> _item) 
    {
        bool _isAlreadyPresent = false;
        ItemType _itemType = _item->GetItemType();
        _isAlreadyPresent = GetItemLocation(_itemType) != -1;
        if (!_isAlreadyPresent) 
        {
            items.push_back(move(_item));
            cout << ItemTypeToString(_itemType) << " Item is added in " << GetCharacterName() << "\'s inventory." << endl;
        }
        else 
        {
            cout << ItemTypeToString(_item->GetItemType()) << " is already present in " << GetCharacterName() << "\'s inventory." 
                << endl;
        }
    }

    int CharacterController::GetSpecialAbilityLocation(SpecialAbilityType _specialAbilityType) const 
    {
        int _specialAbilityLocation;
        if (specialAbilities.size() == 0) 
        {
            _specialAbilityLocation = -1;
        }
        else 
        {
            int i = 0;
            do 
            {
                if (specialAbilities[i]->GetSpecialAbilityType() == _specialAbilityType) 
                {
                    _specialAbilityLocation = i;
                }
                i += 1;
            } while (i < specialAbilities.size() && _specialAbilityLocation == -1);
        }
        return _specialAbilityLocation;
    }

    void CharacterController::AddSpecialAbility(unique_ptr<SpecialAbility> _specialAbility) 
    {
        bool _isAlreadyPresent = false;
        SpecialAbilityType _specialAbilityType = _specialAbility->GetSpecialAbilityType();
        _isAlreadyPresent = GetSpecialAbilityLocation(_specialAbilityType) != -1;
        if (!_isAlreadyPresent) 
        {
            specialAbilities.push_back(move(_specialAbility));
            cout << SpecialAbilityTypeToString(_specialAbilityType) << " Special Ability is added in " << GetCharacterName()
                << "\'s skillset." << endl;
        }
        else 
        {
            cout << SpecialAbilityTypeToString(_specialAbility->GetSpecialAbilityType()) << " is already present in " 
                << GetCharacterName() << "\'s inventory." << endl;
        }
    }

    void CharacterController::PerformSpecialAbility(CharacterController* targetCharacter, PlayerSelectActionType selectedAction, SpecialAbility* _specialAbility) 
    {
        cout << "Special Ability Activated: " << SpecialAbilityTypeToString(_specialAbility->GetSpecialAbilityType()) << endl;
        cout << this->GetCharacterName() << " " << SpecialAbilityTypeToDefinition(_specialAbility->GetSpecialAbilityType())
            << "." << endl;
        _specialAbility->UseSpecialAbility(targetCharacter, this);
    }

    void CharacterController::PerformNormalAbility(CharacterController* targetCharacter, PlayerSelectActionType selectedAction) 
    {
        if (selectedAction == PlayerSelectActionType::Damage) 
        {
            targetCharacter->TakeDamage(GetMeleeDamage());
        }
        else 
        {
            this->Heal(GetHeal());
        }
    }

    void CharacterController::PerformAbility(CharacterController* targetCharacter,  PlayerSelectActionType selectedAction, float _randomProbability) 
    {
        if (selectedAction == PlayerSelectActionType::Damage) 
        {
            vector<SpecialAbility*> _applicableSpecialAbilities; // To store all the special abilities
            // applicable within Probability Limit
            float _totalWeight = 0; // To store the total weight

            // Fetching all Special Abilities applicable to the Character smaller than
            // passed probability limit and their cumulative weights
            for (auto& _ability : specialAbilities) 
            {
                if (_ability->GetSpecialAbilityProbability() >= _randomProbability) 
                {
                    _applicableSpecialAbilities.push_back(_ability.get());
                    _totalWeight += _ability->GetSpecialAbilityProbability();
                }
            }

            // If Special Abilities are applicable, getting one random special
            // ability(weighted) among them
            if (!_applicableSpecialAbilities.empty()) 
            {
                sort(_applicableSpecialAbilities.begin(), _applicableSpecialAbilities.end(), [](SpecialAbility* a, SpecialAbility* b) 
                    {
                        return a->GetSpecialAbilityProbability() > b->GetSpecialAbilityProbability();
                    }
                );
                float _randomNumber = static_cast<float>(Random::GetRandomNumber(0, static_cast<int>(_totalWeight * 100))) / 100.0f;

                // Finding the first ability where cumultive weight is greater than or
                // equal to _randomNumber
                int _selectedIndex = 0;
                float _cummulatveWeight = 0.0f;
                for (int i = 0; i < _applicableSpecialAbilities.size(); i++) 
                {
                    _cummulatveWeight += _applicableSpecialAbilities[i]->GetSpecialAbilityProbability();
                    if (_cummulatveWeight >= _randomNumber) 
                    {
                        _selectedIndex = i;
                        break;
                    }
                }
                PerformSpecialAbility(targetCharacter, selectedAction, _applicableSpecialAbilities[_selectedIndex]);
            }
            else 
            {
                PerformNormalAbility(targetCharacter, selectedAction);
            }
        }
        else 
        {
            PerformNormalAbility(targetCharacter, selectedAction);
        }
    }

    void CharacterController::TakeDamage(int _damage) 
    {
        // Checking if Character defence is more or equals to damage inflicted
        // then damage will be 0
        int _totalDamage;
        if (defence >= _damage || canBlock == true || canTakeDamage == false) 
        {
            _totalDamage = 0;
        }
        else 
        {
            _totalDamage = _damage - defence;
        }
        health -= _totalDamage;

        // Health can't be -ve
        if (health < 0) 
        {
            health = 0;
        }

        cout << GetCharacterName() << " takes Total Damage of " << _totalDamage << " points with Defence of " << defence 
            << " points and Damage of " << _damage << " points." << endl;
        canTakeDamage = true;
        canBlock = false;
    }

    void CharacterController::Heal(int _heal) 
    {
        health += _heal;
        // Health can't be more than max health
        if (health > maxHealth) 
        {
            health = maxHealth;
        }
        cout << GetCharacterName() << " heals by " << _heal << " points." << endl;
    }

    bool CharacterController::IsAlive() const 
    {
        bool _isAlive = true;
        if (health == 0) 
        {
            _isAlive = false;
        }
        return _isAlive;
    }

    CharacterType CharacterController::GetCharacterType() const
    {
        return characterType;
    }

}