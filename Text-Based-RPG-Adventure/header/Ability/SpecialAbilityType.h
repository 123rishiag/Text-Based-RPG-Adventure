#pragma once
#include <string>   // For String Operations

namespace Ability
{
    // Create enum for All types of Special Abilities
    enum class SpecialAbilityType 
    {
        CriticalHit,
        Blocker,
        LifeSteal,
        RangedAttack,
        GroundSlash,
        SpeedDash,
        HealthRegeneration,
        None
    };

    // Function to return the string representation of Special Ability Type
    std::string SpecialAbilityTypeToString(SpecialAbilityType specialAbilityType)
    {
        switch (specialAbilityType) 
        {
        case SpecialAbilityType::CriticalHit:
            return "Critical Hit";
        case SpecialAbilityType::Blocker:
            return "Blocker";
        case SpecialAbilityType::LifeSteal:
            return "Life Steal";
        case SpecialAbilityType::RangedAttack:
            return "Ranged Attack";
        case SpecialAbilityType::GroundSlash:
            return "Ground Slash";
        case SpecialAbilityType::SpeedDash:
            return "Speed Dash";
        case SpecialAbilityType::HealthRegeneration:
            return "Health Regeneration";
        default:
            return "Unknown";
        }
    }

    // Function to return the definition of Special Ability Type
    std::string SpecialAbilityTypeToDefinition(SpecialAbilityType specialAbilityType) 
    {
        switch (specialAbilityType) 
        {
        case SpecialAbilityType::CriticalHit:
            return "gets massive Damage Boost";
        case SpecialAbilityType::Blocker:
            return "will block all damage on next hit";
        case SpecialAbilityType::LifeSteal:
            return "will recover a small amount of HP after giving damage";
        case SpecialAbilityType::RangedAttack:
            return "will attack now and won't take damage by next attack";
        case SpecialAbilityType::GroundSlash:
            return "gets massive Damage Boost";
        case SpecialAbilityType::SpeedDash:
            return "attacks twice in a row";
        case SpecialAbilityType::HealthRegeneration:
            return "will recover a Big Amount of HP";
        default:
            return "Unknown";
        }
    }
}