#pragma once
#include <string>   // For String Operations

namespace Character
{
	// Create enum for All types of Characters
	enum class CharacterType { Player, Enemy, BossEnemy, None };

	// Create enum for all types of Player Selections
	enum class PlayerSelectActionType { Damage, Heal, None };

	// Function to return the string representation of Character Type
	std::string CharacterTypeToString(CharacterType characterType) 
	{
		switch (characterType) 
		{
		case CharacterType::Player:
			return "Player";
		case CharacterType::Enemy:
			return "Enemy";
		case CharacterType::BossEnemy:
			return "BossEnemy";
		default:
			return "Unknown";
		}
	}

	// Function to Select Action
	PlayerSelectActionType PlayerSelectAction(char selectAction) 
	{
		switch (selectAction) 
		{
		case 'D':
		case 'd':
			return PlayerSelectActionType::Damage;
		case 'H':
		case 'h':
			return PlayerSelectActionType::Heal;
		default:
			return PlayerSelectActionType::None;
		}
	}
}