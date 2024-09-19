#include "../../header/Ability/SpecialAbilityController.h"

namespace Ability
{
    SpecialAbilityController::SpecialAbilityController(float _specialAbilityProbability, SpecialAbilityType _specialAbilityType)
        : specialAbilityProbability(_specialAbilityProbability), specialAbilityType(_specialAbilityType) { }

    SpecialAbilityController::~SpecialAbilityController() = default;

    float SpecialAbilityController::GetSpecialAbilityProbability() const 
    {
        return specialAbilityProbability;
    }

    SpecialAbilityType SpecialAbilityController::GetSpecialAbilityType() const
    {
        return specialAbilityType;
    }
}