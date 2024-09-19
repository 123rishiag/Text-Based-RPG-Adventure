#pragma once
#include "../../header/Ability/SpecialAbilityType.h"
#include "../../header/Character/CharacterController.h"

namespace Ability
{
    class SpecialAbilityController
    {
    private:
        float specialAbilityProbability; // Special Ability Probability
        SpecialAbilityType specialAbilityType;

    public:
        SpecialAbilityController(float _specialAbilityProbability, SpecialAbilityType _specialAbilityType);
        virtual ~SpecialAbilityController();

        // Pure Virtual Function to Use Special Ability
        virtual void UseSpecialAbility(Character::CharacterController* targetCharacter, 
            Character::CharacterController* sourceCharacter) = 0;

        // Getters
        float GetSpecialAbilityProbability() const;
        SpecialAbilityType GetSpecialAbilityType() const;
    };
}