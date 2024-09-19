#include "../../../header/Ability/Controllers/GroundSlashSpecialAbilityController.h"
#include "../../../header/Character/CharacterController.h"

namespace Ability
{
    namespace Controller
    {
        GroundSlashSpecialAbilityController::GroundSlashSpecialAbilityController(float _specialAbilityProbability)
            : SpecialAbilityController(_specialAbilityProbability, SpecialAbilityType::GroundSlash) { }

        void GroundSlashSpecialAbilityController::UseSpecialAbility(Character::CharacterController* targetCharacter,
            Character::CharacterController* sourceCharacter)
        {
            int _damage = sourceCharacter->GetMeleeDamage() * 3;
            targetCharacter->TakeDamage(_damage);
        }
    }
}