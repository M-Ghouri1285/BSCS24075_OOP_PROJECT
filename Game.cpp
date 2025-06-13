#include "Game.h"

Game::Game() : player1(nullptr), player2(nullptr), gameOver(false)
{
    availableItems.push(new HealthPotion());
    availableItems.push(new ManaPotion());
    availableItems.push(new FrostSword());
    availableItems.push(new PoisonDagger());
}

Game::~Game()
{
    cleanup();
}

void Game::startGame()
{
    cout << "=== WELCOME TO THE BATTLE GAME ===" << endl;
    cout << endl;

    cout << "PLAYER 1 SETUP" << endl;
    selectCharacter(player1, 1);
    selectItems(player1);

    cout << endl;

    cout << "PLAYER 2 SETUP" << endl;
    selectCharacter(player2, 2);
    selectItems(player2);

    cout << endl;

    cout << "=== BATTLE BEGINS ===" << endl;
    battlePhase();
}

void Game::selectCharacter(Character*& player, int playerNumber)
{
    int choice = 0;
    my_str name;

    cout << "PLAYER " << playerNumber << " SETUP" << endl;
    cout << "Player " << playerNumber << ", enter your name: ";

    cin >> name;
    cin.ignore(10000, '\n');

    while (true)
    {
        cout << endl;
        cout << "Choose your class:" << endl;
        cout << "1. Warrior (High HP, Medium Attack)" << endl;
        cout << "2. Mage (Medium HP, High Magic)" << endl;
        cout << "3. Archer (Balanced)" << endl;
        cout << "Enter choice (1-3): ";

        if (!(cin >> choice) || choice < 1 || choice > 3)
        {
            cout << "Invalid input. Please enter a number between 1 and 3." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
        }
        else 
        {
            cin.ignore(10000, '\n');
            break;
        }
    }

    switch (choice) 
    {
    case 1: player = new Warrior(name); break;
    case 2: player = new Mage(name); break;
    case 3: player = new Archer(name); break;
    }

    cout << endl << player->getName() << " the ";
    if (dynamic_cast<Warrior*>(player)) cout << "Warrior";
    else if (dynamic_cast<Mage*>(player)) cout << "Mage";
    else cout << "Archer";
    cout << " has joined the battle!" << endl << endl;
}

void Game::selectItems(Character* player)
{
    cout << player->getName() << ", select up to 5 items:" << endl;

    for (int i = 0; i < availableItems.size(); i++)
    {
        cout << i + 1 << ". " << availableItems[i]->getName()
            << " - " << availableItems[i]->getDesc() << endl;
    }
    cout << "0. Finish selection" << endl;

    int itemsSelected = 0;
    while (itemsSelected < 5)
    {
        int choice;
        cout << "Choose item (1-" << availableItems.size() << ") or 0 to finish: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Try again." << endl;
            continue;
        }

        if (choice == 0)
        {
            if (itemsSelected == 0)
            {
                cout << "You must select at least 1 item." << endl;
                continue;
            }
            break;
        }

        if (choice > 0 && choice <= availableItems.size())
        {
            Item* original = availableItems[choice - 1];
            Item* selectedItem = nullptr;

            if (original->getName().is_equal("Health Potion")) 
            {
                selectedItem = new HealthPotion();
            }
            else if (original->getName().is_equal("Mana Potion")) 
            {
                selectedItem = new ManaPotion();
            }
            else if (original->getName().is_equal("Frost Sword")) 
            {
                selectedItem = new FrostSword();
            }
            else if (original->getName().is_equal("Poison Dagger")) 
            {
                selectedItem = new PoisonDagger();
            }

            player->addItem(selectedItem);
            itemsSelected++;
            cout << "Added " << selectedItem->getName() << " to inventory." << endl;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    }
}

void Game::battlePhase()
{
    int turn = 1;
    while (!gameOver)
    {
        cout << endl << "=== TURN " << turn << " ===" << endl;
        displayBattleStatus();

        cout << endl << player1->getName() << "'s turn:" << endl;
        playerTurn(player1, player2);
        if (gameOver) break;

        cout << endl << player2->getName() << "'s turn:" << endl;
        playerTurn(player2, player1);

        turn++;
    }
}

void Game::playerTurn(Character* attacker, Character* defender)
{
    int choice = 0;

    do
    {
        cout << "Choose action:" << endl;
        cout << "1. Basic Attack" << endl;
        cout << "2. Special Ability" << endl;
        cout << "3. Use Item" << endl;
        cout << "Enter choice (1-3): ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > 3)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Try again." << endl;
            choice = 0;
        }
    } while (choice < 1 || choice > 3);

    switch (choice)
    {
    case 1:
        attacker->attack(*defender);
        break;
    case 2:
        attacker->specialAbility(*defender);
        break;
    case 3:
        if (attacker->getInventory().empty())
        {
            cout << "No items in inventory!" << endl;
            playerTurn(attacker, defender);
            return;
        }
        attacker->showInventory();

        int itemChoice = -1;
        do
        {
            cout << "Choose item to use (0-" << attacker->getInventory().size() - 1 << "): ";
            cin >> itemChoice;

            if (cin.fail() || itemChoice < 0 || itemChoice >= attacker->getInventory().size())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input." << endl;
                itemChoice = -1;
            }
        } while (itemChoice == -1);

        attacker->useItem(itemChoice);
        break;
    }

    defender->processStatusEffects();

    if (!defender->isAlive())
    {
        cout << endl << "=== BATTLE OVER ===" << endl;
        cout << attacker->getName() << " wins the battle!" << endl;
        gameOver = true;
    }
}

void Game::displayBattleStatus()
{
    cout << player1->getName() << ": HP " << player1->getHealth() << "/" << player1->getMaxHealth()
        << " | MP " << player1->getMana() << "/" << player1->getMaxMana() << endl;
    cout << player2->getName() << ": HP " << player2->getHealth() << "/" << player2->getMaxHealth()
        << " | MP " << player2->getMana() << "/" << player2->getMaxMana() << endl;
}

void Game::cleanup()
{
    if (player1) delete player1;
    if (player2) delete player2;

    for (int i = 0; i < availableItems.size(); i++)
    {
        delete availableItems[i];
    }
    availableItems.clear();
}
