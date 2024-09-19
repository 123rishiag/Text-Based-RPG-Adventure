#pragma once
#include <memory>   // For Smart Pointers
#include <vector>   // For Vector Operations
#include <iostream>  // For Standard IO Operations
#include "../../header/Character/CharacterType.h"
#include "../../header/Item/ItemController.h"
#include "../../header/Ability/SpecialAbilityController.h"

namespace Character
{
    class CharacterController
    {
    private:
        // Main Members
        std::string characterName;       // Name of Character
        int health;                 // Health of Character
        int healPercentage;         // Heal Percentage for Healing(1-100 only)
        int meleeDamage;            // Melee Damage of Character
        int meleeDamagePercentage;  // Melee Damage Percentage for Dynamic Melee Damage(1-100 only)
        int rangedDamage;           // Ranged Damage of Character
        int rangedDamagePercentage; // Ranged Damage Percentage for Dynamic Ranged Damage(1-100 only)
        int defence;                // Defence of Character
        int defencePercentage; // Defence Percentage for Dynamic Defence(1-100 only)
        CharacterType characterType; // Character Type

        // Other Members
        int maxHealth;         // Max Health of Character
        int healAmount;        // Heal Amount of Character
        int minMeleeDamage;    // Minimum Melee Damage
        int maxMeleeDamage;    // Maximum Melee Damage
        int minRangedDamage;   // Minimum Ranged Damage
        int maxRangedDamage;   // Maximum Ranged Damage
        int minDefence;        // Minimum Defence
        int maxDefence;        // Maximum Defence
        bool canBlock = false; // Flag to Check if the Character can Block
        bool canTakeDamage = true; // Flag to Check if Character can Take DamageAttacks
        std::vector<std::unique_ptr<Ability::SpecialAbilityController>> specialAbilities;    // Special Abilities of Character
        std::vector<std::unique_ptr<Item::ItemController>> items; // Items Owned by Character

    public:
        CharacterController(std::string _characterName, int _health, int _healPercentage, int _meleeDamage,
            int _meleeDamagePercentage, int _rangedDamage, int _rangedDamagePercentage, int _defence, int _defencePercentage,
            CharacterType _characterType);
        virtual ~CharacterController();

        // Getters
        std::string GetCharacterName() const;
        int GetHealth() const;
        int GetHeal() const;
        int GetMeleeDamage() const;
        int GetRangedDamage() const;
        int GetDefence() const;
        int GetMaxHealth() const;

        // Setters
        void EnableCanBlock();
        void DisableCanTakeDamage();

        // Functions to Increase Member Values
        void IncreaseMaxHealth(int _increaseHealthPercentage); // To increase Maximum Health of Character
        void IncreaseMeleeDamage(int _increaseDamagePercentage); // To increase Melee Damage of Character
        void IncreaseDefence(int _increaseDefencePercentage); // To increase Defence of Character

        // Stats Functions
        void ShowCharacterName();
        void ShowHealth();
        void ShowMaxHealth();
        void ShowMeleeDamage();
        void ShowRangedDamage();
        void ShowDefence();
        void ShowStats();
        void ShowItems();
        void ShowSpecialAbilities();

        // Other Functions
        int GetItemLocation(Item::ItemType _itemType) const; // Function to Get Item Location
        void AddItem(std::unique_ptr<Item::ItemController> _item); // Function to Add Items in Character's Inventory
        int GetSpecialAbilityLocation(Ability::SpecialAbilityType _specialAbilityType) const; // Function to Get Special Ability Location
        void AddSpecialAbility(std::unique_ptr<Ability::SpecialAbilityController> _specialAbility); // Function to Add Special Ability in Character's Skillset
        void PerformSpecialAbility(CharacterController* targetCharacter, PlayerSelectActionType selectedAction, Ability::SpecialAbilityController* _specialAbility);
        void PerformNormalAbility(CharacterController* targetCharacter, PlayerSelectActionType selectedAction);
        void PerformAbility(CharacterController* targetCharacter, PlayerSelectActionType selectedAction, float _randomProbability);

        
        void TakeDamage(int _damage); // Function to Take Damage by Character
        void Heal(int _heal); // Function to Heal Character
        
        bool IsAlive() const; // Function to check whether character is alive or not

        CharacterType GetCharacterType() const;
    };
}