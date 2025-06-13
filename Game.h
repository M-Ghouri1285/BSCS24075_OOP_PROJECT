#pragma once
#ifndef GAME_H
#define GAME_H

#include "Character.h"
#include "Archer.h"
#include "Mage.h"
#include "Warrior.h"
#include "HealthPotion.h"
#include "ManaPotion.h"
#include "FrostSword.h"
#include "PoisonDagger.h"
#include "vector.h"
#include <iostream>

using namespace std;

class Game 
{
private:
    Character* player1;
    Character* player2;
    Dynamic_array<Item*> availableItems;
    bool gameOver;

public:
    Game();
    ~Game();
    void startGame();
    void selectCharacter(Character*& player, int playerNumber);
    void selectItems(Character* player);
    void battlePhase();
    void playerTurn(Character* attacker, Character* defender);
    void displayBattleStatus();
    void cleanup();
};

#endif !GAME_H
