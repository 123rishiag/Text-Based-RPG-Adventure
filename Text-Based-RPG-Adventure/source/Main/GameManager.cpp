#include "../../header/Main/GameManager.h"
#include "../../header/Utility/Random.h"
#include "../../header/Level/Controllers/LevelController1.h"
#include "../../header/Level/Controllers/LevelController2.h"
#include "../../header/Level/Controllers/LevelController3.h"
#include "../../header/Level/Controllers/LevelController4.h"
#include "../../header/Level/Controllers/LevelController5.h"
#include "../../header/Level/Controllers/LevelController6.h"

namespace Main
{
    using namespace Level;
    using namespace Level::Controller;
    using namespace Utility;
    using namespace std;

    GameManager::GameManager() 
    {
        Random::Init();
        ShowGameDetails();
        CreatePlayer();
        currentLevelNumber = LevelNumber::Level1;
    }

    void GameManager::CreatePlayer()
    {
        player = unique_ptr<Character>(
            new Player("Rishi", // Name of Character
                300,     // Health of Character
                60,      // Heal Percentage for Healing(1-100 only)
                70,      // Melee Damage of Character
                0,       // Melee Damage Percentage for Dynamic Melee
                // Damage(1-100 only)
                50,      // Ranged Damage of Character
                0,       // Ranged Damage Percentage for Dynamic Ranged
                // Damage(1-100 only)
                20,      // Defence of Character
                0 // Defence Percentage for Dynamic Defence(1-100 only)
            ));
    }

    unique_ptr<LevelController> GameManager::InitializeLevel(LevelNumber _levelNumber)
    {
        switch (_levelNumber) 
        {
        case LevelNumber::Level1:
            return unique_ptr<LevelController>(new LevelController1(1, CharacterType::Enemy));
        case LevelNumber::Level2:
            return unique_ptr<LevelController>(new LevelController2(2, CharacterType::Enemy));
        case LevelNumber::Level3:
            return unique_ptr<LevelController>(new LevelController3(3, CharacterType::Enemy));
        case LevelNumber::Level4:
            return unique_ptr<LevelController>(new LevelController4(4, CharacterType::Enemy));
        case LevelNumber::Level5:
            return unique_ptr<LevelController>(new LevelController5(5, CharacterType::Enemy));
        case LevelNumber::Level6:
            return unique_ptr<LevelController>(new LevelController6(1, CharacterType::BossEnemy));
        default:
            return nullptr;
        }
    }

    void GameManager::GenerateLevel() 
    {
        if (static_cast<int>(currentLevelNumber) < static_cast<int>(LevelNumber::None)) 
        {
            currentLevel = InitializeLevel(static_cast<LevelNumber>(currentLevelNumber));
            currentLevel->GenerateEnemies(player.get());
        }
    }

    void GameManager::CharacterPerformAction(Character* _character1, Character* _character2) 
    {
        PlayerSelectActionType selectedAction;

        cout << _character1->GetCharacterName() << "\'s turn:" << endl;

        if (_character1->GetCharacterType() == CharacterType::Player) 
        {
            char action;
            cout << "Select D to Damage or H to Heal" << endl;

            cin >> action;
            selectedAction = PlayerSelectAction(action);
            cout << endl;
        }
        else 
        {
            selectedAction = PlayerSelectActionType::Damage;
        }

        // Performing Action Based on Selection
        if (selectedAction == PlayerSelectActionType::None) 
        {
            cout << "Turn Missed!!!: (Select D to Damage or H to Heal)" << endl;
        }
        else 
        {
            // Computing Random Probability to Activate Special Ability
            float _randomProbality =
                static_cast<float>(99 - Random::GetRandomNumber(0, 99)) / 100.f;
            _character1->PerformAbility(_character2, selectedAction,
                _randomProbality);
        }
        // Show Player's Updated Health
        _character1->ShowHealth();
        _character2->ShowHealth();
        cout << endl;
    }

    void GameManager::RoundLoop() 
    {
        player->ShowStats();
        cout << endl;
        enemy->ShowStats();
        cout << endl;
        // Game Loop to Run Game until Player is Dead or no enemies are left
        int turn = 0;
        while (player->IsAlive() && enemy->IsAlive()) 
        {
            if (turn % 2 == 0) 
            {
                cout << "--------------------------------------------------" << endl;
                CharacterPerformAction(player.get(), enemy);
            }
            else 
            {
                CharacterPerformAction(enemy, player.get());
            }
            turn += 1;
        }
        // Priting Round Win Message
        if (player->IsAlive()) 
        {
            cout << "--------------------------------------------------" << endl;
            cout << player->GetCharacterName() << " wins this Round!" << endl;
            cout << "--------------------------------------------------" << endl;
        }
    }

    void GameManager::LevelLoop() 
    {
        int _round = 1;
        do 
        {
            enemy = currentLevel->GetEnemyAtIndex(0);
            currentLevel->UpgradeCharacter(enemy);
            // Perform round loop if there's an enemy
            cout << "                      Round " << _round << "                      " << endl;
            cout << "--------------------------------------------------" << endl;
            if (enemy != nullptr) 
            {
                RoundLoop();
            }
            currentLevel->PopFirstEnemy();
            _round += 1;
        } while (player->IsAlive() && currentLevel->GetEnemyAtIndex(0));

        // Priting Level Win Message
        if (player->IsAlive()) 
        {
            cout << "--------------------------------------------------" << endl;
            cout << player->GetCharacterName() << " wins this Level!" << endl;
            cout << "--------------------------------------------------" << endl;
            cout << "--------------------------------------------------" << endl;
        }
    }

    void GameManager::GameLoop() 
    {
        do 
        {
            // Generating Level
            GenerateLevel();
            cout << "--------------------------------------------------" << endl;
            cout << "                      " << LevelNumberToString(currentLevel->GetLevelNumber()) << "                      " << endl;
            cout << "--------------------------------------------------" << endl;
            cout << "--------------------------------------------------" << endl;
            LevelLoop();

            if (player->IsAlive() && currentLevelNumber < LevelNumber::None) 
            {
                // Upgrading Player after each level
                cout << player->GetCharacterName() << " recieves the following upgrades: " << endl;
                currentLevel->UpgradeCharacter(player.get());
            }
            cout << "--------------------------------------------------" << endl;
            // Incrementing Next Level
            currentLevelNumber = static_cast<LevelNumber>(static_cast<int>(currentLevelNumber) + 1);
        } while (player->IsAlive() && currentLevelNumber < LevelNumber::None);
    }

    void GameManager::ShowGameDetails() 
    {
        cout << "Welcome to the Text-based RPG Adventure Game: The Murloc Menace\n\n";
        cout << "Story:\n";
        cout << "In the serene lands of Eldoria, a peaceful village has fallen under the shadow of the Murlocs, ";
        cout << "vicious creatures led by the fearsome Boss Murloc. Our hero,  armed only with courage, ";
        cout << "must journey through dangerous terrains, gathering the legendary artifacts needed ";
        cout << "to defeat the Murloc leader and free their home.\n\n";

        cout << "Gameplay Overview:\n";
        cout << "1) Navigate through 6 challenging levels, each with increasing difficulty.\n";
        cout << "2) Engage in battle with enemies using attacks, or choose to heal.\n";
        cout << "3) Collect essential items after completing each level to enhance your abilities.\n";
        cout << "4) Utilize special abilities that unlock as you progress, each with a 10% chance of activation during attacks.\n";
        cout << "5) Confront the Boss Murloc in a final epic battle in Level 6, utilizing everything you've gathered.\n\n";

        cout << "Items and Abilities:\n";
        cout << "- Level 1: Receive a Map to guide your journey.\n";
        cout << "- Level 2: Gain a Sword and the 'Critical Hits' ability for massive damage.\n";
        cout << "- Level 3: Acquire a Shield and the 'Blocker' ability to negate incoming damage.\n";
        cout << "- Level 4: Obtain Armour and the 'Life Steal' ability to recover health upon attacking.\n";
        cout << "- Level 5: Earn a Bow and the 'Ranged Attack' ability, which protects you from the next attack after use.\n";
        cout << "- Level 6: Prepare for the final battle against the Boss Murloc, "
            "who has abilities like Ground Slash, Speed Dash, and Health Regeneration.\n\n";

        cout << "Controls:\n";
        cout << "- Press 'D' to Attack.\n";
        cout << "- Press 'H' to Heal.\n";
        cout << "- Follow on-screen prompts for using special abilities when they activate.\n\n";

        cout << "Embark on your quest to save your village and become the hero Eldoria needs!\n";
        cout << "Good luck!\n";
    }

    void GameManager::StartGame() 
    {
        cout << "--------------------------------------------------" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "                     Game Started                 " << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "--------------------------------------------------" << endl;
        GameLoop();

        // Game Over
        if (player->IsAlive()) 
        {
            cout << player->GetCharacterName() << " Wins!" << endl;
        }
        else 
        {
            cout << player->GetCharacterName() << " Lost!" << endl;
            cout << endl;
        }

        cout << "--------------------------------------------------" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "                     Game Over                    " << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "--------------------------------------------------" << endl;
    }
}