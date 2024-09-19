#pragma once
#include <memory>   // For Smart Pointers
#include <vector>   // For Vector Operations
#include<iostream>  // For Standard IO Operations
#include "../../header/Level/LevelNumber.h"

namespace Level
{
    enum class CharacterType;
    enum class SpecialAbilityType;
    enum class ItemType;

    class Character;
    class SpecialAbility;
    class Item;

    class LevelController
    {
    private:
        int numberOfEnemies;
        CharacterType enemyType;
        std::vector<std::unique_ptr<Character>> enemies;
        LevelNumber levelNumber;

    public:
        LevelController(int _numberOfEnemies, CharacterType _enemyType, LevelNumber _levelNumber);
        virtual ~LevelController();

        // Getters
        int GetNumberOfEnemies() const;
        CharacterType GetEnemyType() const;

        // Function to Return Enemy Pointer
        std::unique_ptr<Character> GetEnemy(CharacterType _characterType, int _enemyNumber, Character* _character);
        // Function to Return Special Ability Pointer
        std::unique_ptr<SpecialAbility> GetSpecialAbility(SpecialAbilityType _specialAbilityType);
        // Function to Return Item Pointer
        std::unique_ptr<Item> GetItem(ItemType _itemType);

        
        void GenerateEnemies(Character* _character); // Function to Generate Enemies
        void ShowEnemies(); // Function to show Enemies
        Character* GetEnemyAtIndex(int _characterIndex) const; // Function to Get Enemy Object
        void PopFirstEnemy(); // Function to Pop First Enemy Object

        virtual void UpgradeCharacter(Character* _character) = 0; // Pure Virtual Function to Get UpgradeCharacter
        LevelNumber GetLevelNumber() const;
    };
}