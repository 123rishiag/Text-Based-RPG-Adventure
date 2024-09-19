#pragma once
#include <memory>   // For Smart Pointers
#include <vector>   // For Vector Operations
#include <iostream>  // For Standard IO Operations
#include "../../header/Level/LevelNumber.h"

namespace Character
{
    enum class CharacterType;
    class CharacterController;
}

namespace Level
{
    enum class SpecialAbilityType;
    enum class ItemType;

    class SpecialAbility;
    class Item;

    class LevelController
    {
    private:
        int numberOfEnemies;
        Character::CharacterType enemyType;
        std::vector<std::unique_ptr<Character::CharacterController>> enemies;
        LevelNumber levelNumber;

    public:
        LevelController(int _numberOfEnemies, Character::CharacterType _enemyType, LevelNumber _levelNumber);
        virtual ~LevelController();

        // Getters
        int GetNumberOfEnemies() const;
        Character::CharacterType GetEnemyType() const;

        // Function to Return Enemy Pointer
        std::unique_ptr<Character::CharacterController> GetEnemy(Character::CharacterType _characterType, int _enemyNumber, 
            Character::CharacterController* _character);
        // Function to Return Special Ability Pointer
        std::unique_ptr<SpecialAbility> GetSpecialAbility(SpecialAbilityType _specialAbilityType);
        // Function to Return Item Pointer
        std::unique_ptr<Item> GetItem(ItemType _itemType);

        
        void GenerateEnemies(Character::CharacterController* _character); // Function to Generate Enemies
        void ShowEnemies(); // Function to show Enemies
        Character::CharacterController* GetEnemyAtIndex(int _characterIndex) const; // Function to Get Enemy Object
        void PopFirstEnemy(); // Function to Pop First Enemy Object

        virtual void UpgradeCharacter(Character::CharacterController* _character) = 0; // Pure Virtual Function to Get UpgradeCharacter
        LevelNumber GetLevelNumber() const;
    };
}