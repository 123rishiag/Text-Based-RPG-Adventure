#include "../../../header/Ability/Controllers/LifeStealSpecialAbilityController.h"

namespace Ability
{
    namespace Controller
    {
        LifeStealSpecialAbilityController::LifeStealSpecialAbilityController(float _specialAbilityProbability)
            : SpecialAbilityController(_specialAbilityProbability, SpecialAbilityType::LifeSteal) { }

        void LifeStealSpecialAbilityController::UseSpecialAbility(Character::CharacterController* targetCharacter,
            Character::CharacterController* sourceCharacter)
        {
            targetCharacter->TakeDamage(sourceCharacter->GetMeleeDamage());
            sourceCharacter->Heal(sourceCharacter->GetHeal());
        }
    }
}