#pragma once
#include <string>   // For String Operations

namespace Level
{
	// Create enum for all Level Numbers
	enum class LevelNumber 
	{
		Level1 = 1,
		Level2,
		Level3,
		Level4,
		Level5,
		Level6,
		None
	};

	// the string representation of Level Numbers
	inline std::string LevelNumberToString(LevelNumber levelNumber)
	{
		switch (levelNumber) 
		{
		case LevelNumber::Level1:
			return "Level 1";
		case LevelNumber::Level2:
			return "Level 2";
		case LevelNumber::Level3:
			return "Level 3";
		case LevelNumber::Level4:
			return "Level 4";
		case LevelNumber::Level5:
			return "Level 5";
		case LevelNumber::Level6:
			return "Final Level";
		default:
			return "Unknown";
		}
	}
}