#include "../../../header/Ability/Controllers/BlockerSpecialAbilityController.h"
#include "../../../header/Character/CharacterController.h"

namespace Ability
{
    namespace Controller
    {
        BlockerSpecialAbilityController::BlockerSpecialAbilityController(float _specialAbilityProbability)
            : SpecialAbilityController(_specialAbilityProbability, SpecialAbilityType::Blocker) { }

        void BlockerSpecialAbilityController::UseSpecialAbility(Character::CharacterController* targetCharacter,
            Character::CharacterController* sourceCharacter)
        {
            sourceCharacter->EnableCanBlock();
        }
    }
}