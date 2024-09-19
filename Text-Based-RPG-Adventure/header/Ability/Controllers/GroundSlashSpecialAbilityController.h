#pragma once
#include "../../../header/Ability/SpecialAbilityController.h"

namespace Ability
{
    namespace Controller
    {
        class GroundSlashSpecialAbilityController : public SpecialAbilityController
        {
        public:
            GroundSlashSpecialAbilityController(float _specialAbilityProbability);

            // Overrided Function Use Special Ability
            void UseSpecialAbility(Character::CharacterController* targetCharacter,
                Character::CharacterController* sourceCharacter) override;
        };
    }
}