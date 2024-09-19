#pragma once
#include "../../../header/Level/LevelController.h"

namespace Level
{
    namespace Controller
    {
        class LevelController4 : public LevelController
        {
        public:
            LevelController4(int _numberOfEnemies, CharacterType _enemyType);

            void UpgradeCharacter(Character* _character) override; // Overrided Function to Get UpgradeCharacter
        };
    }
}