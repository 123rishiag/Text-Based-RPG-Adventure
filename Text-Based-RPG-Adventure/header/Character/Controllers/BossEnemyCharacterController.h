#pragma once
#include "../../../header/Character/CharacterController.h"

namespace Character
{
    namespace Controller
    {
        class BossEnemyCharacterController : public CharacterController
        {
        public:
            BossEnemyCharacterController(std::string _characterName, int _health, int _healPercentage, int _meleeDamage,
                int _meleeDamagePercentage, int _rangedDamage, int _rangedDamagePercentage, int _defence, int _defencePercentage);
        };
    }
}