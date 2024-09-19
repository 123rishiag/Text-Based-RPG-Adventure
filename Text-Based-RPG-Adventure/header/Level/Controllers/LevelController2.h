#pragma once
#include "../../../header/Level/LevelController.h"

namespace Level
{
    namespace Controller
    {
        class LevelController2 : public LevelController
        {
        public:
            LevelController2(int _numberOfEnemies, CharacterType _enemyType);

            void UpgradeCharacter(Character* _character) override; // Overrided Function to Get UpgradeCharacter
        };
    }
}