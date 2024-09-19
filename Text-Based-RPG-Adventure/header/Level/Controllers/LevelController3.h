#pragma once
#include "../../../header/Level/LevelController.h"

namespace Level
{
    namespace Controller
    {
        class LevelController3 : public LevelController
        {
        public:
            LevelController3(int _numberOfEnemies, CharacterType _enemyType);

            void UpgradeCharacter(Character* _character) override; // Overrided Function to Get UpgradeCharacter
        };
    }
}