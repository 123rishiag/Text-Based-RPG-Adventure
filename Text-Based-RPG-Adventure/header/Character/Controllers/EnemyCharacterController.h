#pragma once
#include "../../../header/Character/CharacterController.h"

namespace Character
{
    namespace Controller
    {
        class EnemyCharacterController : public CharacterController
        {
        public:
            EnemyCharacterController(std::string _characterName, int _health, int _healPercentage, int _meleeDamage,
                int _meleeDamagePercentage, int _rangedDamage, int _rangedDamagePercentage, int _defence, int _defencePercentage);
        };
    }
}