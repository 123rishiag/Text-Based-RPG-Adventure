#include "../../../header/Ability/Controllers/CriticalHitSpecialAbilityController.h"

namespace Ability
{
    namespace Controller
    {
        CriticalHitSpecialAbilityController::CriticalHitSpecialAbilityController(float _specialAbilityProbability)
            : SpecialAbilityController(_specialAbilityProbability, SpecialAbilityType::CriticalHit) { }

        void CriticalHitSpecialAbilityController::UseSpecialAbility(Character::CharacterController* targetCharacter,
            Character::CharacterController* sourceCharacter) 
        {
            int _damage = sourceCharacter->GetMeleeDamage() * 2;
            targetCharacter->TakeDamage(_damage);
        }
    }
}