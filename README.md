# Text-Based RPG Adventure: The Murloc Menace

Welcome to **The Murloc Menace**, a text-based RPG adventure game developed in C++. This game combines storytelling, strategic battles, and item collection as you journey through dangerous lands to defeat the fearsome Boss Murloc and save your village.

## Story

In the serene lands of Eldoria, a peaceful village has fallen under the shadow of the Murlocs, vicious creatures led by the fearsome Boss Murloc. Our hero, armed only with courage, must journey through dangerous terrains, gathering the legendary artifacts needed to defeat the Murloc leader and free their home.

## Gameplay Overview

1. Navigate through **6 challenging levels**, each with increasing difficulty.
2. Engage in battle with enemies using **attacks** or choose to **heal**.
3. Collect essential **items** after completing each level to enhance your abilities.
4. Unlock and utilize **special abilities** as you progress, each with unique probabilities of activation during attacks.
5. Confront the **Boss Murloc** in an epic final battle in Level 6, utilizing everything you've gathered throughout the journey.

## Level Awards

- **`Level 1`**:
  - Player Award: **Map** to guide the player's journey.
  - Player Stat Increase: Max Health, Melee Damage, and Defence increase by 20%.

- **`Level 2`**:
  - Player Award: **Sword** unlocking the **Critical Hits** ability (10% chance of activation for massive damage).
  - Player Stat Increase: Max Health, Melee Damage, and Defence increase by 20%.

- **`Level 3`**:
  - Player Award: **Shield** unlocking the **Blocker** ability (20% chance of negating incoming damage).
  - Player Stat Increase: Max Health, Melee Damage, and Defence increase by 20%.

- **`Level 4`**:
  - Player Award: **Armour** unlocking the **Life Steal** ability (30% chance to recover health upon attacking).
  - Player Stat Increase: Max Health, Melee Damage, and Defence increase by 20%.

- **`Level 5`**:
  - Player Award: **Bow** unlocking the **Ranged Attack** ability (40% chance of protecting the player from the next attack).
  - Player Stat Increase: Max Health, Melee Damage, and Defence increase by 20%.

- **`Level 6`**:
  - Player Stat Increase: Max Health, Melee Damage, and Defence increase by 20%.
  - **Boss Murloc**:
    - Items Awarded: **Gauntlet**, **Boot**, **Amulet**.
    - Special Abilities Unlocked: **Ground Slash** (30% chance), **Speed Dash** (20% chance), **Health Regeneration** (10% chance).

## Core Mechanics

- **Smart Pointers**: Leveraged throughout the game to manage dynamic memory safely and efficiently.
- **Polymorphism**: Used to manage different item and ability types, allowing each to have unique behaviors.
- **Enums**: Simplifies the representation of item types, character types, and abilities.
- **Virtual Functions**: Enables flexible, reusable code for character actions and abilities.

## Learning Outcomes

- **Memory Management**: Gained hands-on experience with smart pointers, ensuring efficient memory allocation and deallocation.
- **OOP Principles**: Strengthened understanding of object-oriented programming concepts like inheritance, encapsulation, and polymorphism.
- **Problem Solving**: Improved debugging and optimization skills, ensuring game responsiveness and scalability.
- **Game Mechanics**: Designed strategic combat systems and item upgrades to enhance gameplay engagement.

## Project Structure

### Main Components:

- **Main**:
  - **`GameManager`**: Manages the game flow, including transitions between levels and the story.
  
- **Character**:
  - **`CharacterType`**: Defines character types (Player, Enemy, Boss Enemy).
  - **`CharacterController`**: Manages character behavior and upgrades.
    - **Sub Controllers**: **`PlayerCharacterController`**, **`EnemyCharacterController`**, **`BossEnemyCharacterController`**

- **Level**:
  - **`LevelNumber`**: Defines the level numbers.
  - **`LevelController`**: Handles level-specific logic and progression.
    - **Sub Controllers**: **`LevelController1`**, **`LevelController2`**, **`LevelController3`**, **`LevelController4`**, **`LevelController5`**, **`LevelController6`**

- **Item**:
  - **`ItemType`**: Defines the different types of items collected during the game.
  - **`ItemController`**: Manages item effects and integration.
    - **Sub Controllers**: **`MapItemController`**, **`SwordItemController`**, **`ShieldItemController`**, **`ArmourItemController`**, **`BowItemController`**, **`GauntletItemController`**, **`BootItemController`**, **`AmuletItemController`**

- **Ability**:
  - **`SpecialAbilityType`**: Defines the special abilities available to players and enemies.
  - **`SpecialAbilityController`**: Manages special ability effects.
    - **Sub Controllers**: **`CriticalHitSpecialAbilityController`**, **`BlockerSpecialAbilityController`**, **`LifeStealSpecialAbilityController`**, **`RangedAttackSpecialAbilityController`**, **`GroundSlashSpecialAbilityController`**, **`SpeedDashSpecialAbilityController`**, **`HealthRegenerationSpecialAbilityController`**

### Additional Core Components:

- **Utility**:
  - **`Random`**: Provides random number generation for damage, ability activations, and enemy behavior.

- **Main**: Entry point of the game.

## How to Play

This is a text-based RPG adventure game where you journey through levels and face various enemies. The hero can either inflict damage on enemies or heal during battles. Use the following controls to navigate the gameplay:

- **Attack**: Press `D` to attack your enemy.
- **Heal**: Press `H` to heal.

As you progress through the levels, special abilities will have varying probabilities of activation during attacks, which can dramatically shift the battle in your favor.

## Rules

1. Players take turns to attack or heal during battles.
2. Special abilities have varying probabilities of activating during attacks (refer to each ability's chance).
3. If the hero's health drops to zero, the game is lost.
4. Collect items and abilities to enhance the hero’s power as you progress through each level.

## Setup Instructions

1. Clone the repository:
   ```
   git clone https://github.com/123rishiag/Text-Based-RPG-Adventure.git
   ```

2. Build the project using your preferred C++ compiler.

3. Run the executable in your terminal to start the adventure.

## Video Demo

Check out the [Video Demo](https://www.loom.com/share/a3d0f60d80da4f4b8fa14776b25d4342?sid=ba426849-9fd0-427c-be8a-e812dce3edc8) to see the gameplay in action!