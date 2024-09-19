#include "../../../header/Ability/Controllers/SpeedDashSpecialAbilityController.h"

namespace Ability
{
    namespace Controller
    {
        SpeedDashSpecialAbilityController::SpeedDashSpecialAbilityController(float _specialAbilityProbability)
            : SpecialAbilityController(_specialAbilityProbability, SpecialAbilityType::SpeedDash) { }

        void SpeedDashSpecialAbilityController::UseSpecialAbility(Character::CharacterController* targetCharacter,
            Character::CharacterController* sourceCharacter)
        {
            int _damage = sourceCharacter->GetMeleeDamage();
            targetCharacter->TakeDamage(_damage);
            targetCharacter->TakeDamage(_damage);
        }
    }
}