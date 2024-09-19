#pragma once
#include "../../../header/Level/LevelController.h"

namespace Level
{
    namespace Controller
    {
        class LevelController4 : public LevelController
        {
        public:
            LevelController4(int _numberOfEnemies, Character::CharacterType _enemyType);

            void UpgradeCharacter(Character::CharacterController* _character) override; // Overrided Function to Get UpgradeCharacter
        };
    }
}