#pragma once
#include "../../../header/Level/LevelController.h"

namespace Level
{
    namespace Controller
    {
        class LevelController6 : public LevelController
        {
        public:
            LevelController6(int _numberOfEnemies, Character::CharacterType _enemyType);

            void UpgradeCharacter(Character::CharacterController* _character) override; // Overrided Function to Get UpgradeCharacter
        };
    }
}