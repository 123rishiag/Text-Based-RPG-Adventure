#pragma once
#include "../../../header/Level/LevelController.h"

namespace Level
{
    namespace Controller
    {
        class LevelController3 : public LevelController
        {
        public:
            LevelController3(int _numberOfEnemies, Character::CharacterType _enemyType);

            void UpgradeCharacter(Character::CharacterController* _character) override; // Overrided Function to Get UpgradeCharacter
        };
    }
}