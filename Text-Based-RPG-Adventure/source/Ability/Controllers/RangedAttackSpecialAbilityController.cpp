#include "../../../header/Ability/Controllers/RangedAttackSpecialAbilityController.h"

namespace Ability
{
    namespace Controller
    {
        RangedAttackSpecialAbilityController::RangedAttackSpecialAbilityController(float _specialAbilityProbability)
            : SpecialAbilityController(_specialAbilityProbability, SpecialAbilityType::RangedAttack) { }

        void RangedAttackSpecialAbilityController::UseSpecialAbility(Character::CharacterController* targetCharacter,
            Character::CharacterController* sourceCharacter)
        {
            targetCharacter->TakeDamage(sourceCharacter->GetRangedDamage());
            sourceCharacter->DisableCanTakeDamage();
        }
    }
}