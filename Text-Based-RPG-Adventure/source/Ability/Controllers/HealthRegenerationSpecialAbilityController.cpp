#include "../../../header/Ability/Controllers/HealthRegenerationSpecialAbilityController.h"
#include "../../../header/Character/CharacterController.h"

namespace Ability
{
    namespace Controller
    {
        HealthRegenerationSpecialAbilityController::HealthRegenerationSpecialAbilityController(float _specialAbilityProbability)
            : SpecialAbilityController(_specialAbilityProbability, SpecialAbilityType::HealthRegeneration) { }

        void HealthRegenerationSpecialAbilityController::UseSpecialAbility(Character::CharacterController* targetCharacter,
            Character::CharacterController* sourceCharacter)
        {
            sourceCharacter->Heal(sourceCharacter->GetHeal() * 3);
        }
    }
}