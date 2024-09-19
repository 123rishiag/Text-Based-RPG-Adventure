#pragma once
#include <memory>   // For Smart Pointers
#include "../../header/Level/LevelController.h"
#include "../../header/Level/LevelNumber.h"
#include "../../header/Character/CharacterController.h"

namespace Main
{
    class GameManager 
    {
    private:
        std::unique_ptr<Character::CharacterController> player = nullptr;
        Character::CharacterController* enemy = nullptr;
        std::unique_ptr<Level::LevelController> currentLevel = nullptr;
        Level::LevelNumber currentLevelNumber;

        void CreatePlayer(); // Function to Create Player
        std::unique_ptr<Level::LevelController> InitializeLevel(Level::LevelNumber _levelNumber); // Function to Initialize Level
        void GenerateLevel(); // Function to GenerateLevel()
        void CharacterPerformAction(Character::CharacterController* _character1, Character::CharacterController* _character2); // Function to Choose Player Actions
        void RoundLoop(); // Function to Run Round Loop until Player or Enemy is Dead
        void LevelLoop(); // Function to Create Enemy and Run Round Loop until enemies are available or Player is dead
        void GameLoop(); // Function to Run Game Loop until Player is Dead or Levels are completed

    public:
        GameManager();
        void ShowGameDetails(); // Function to Print Game Story and Details
        void StartGame(); // Function to Start Game
    };
}