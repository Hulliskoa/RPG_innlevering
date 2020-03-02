#pragma once
#include <vector>
#include <string>
#include "Attack.h"
#include "HP.h"
#include <iostream>

class Character
{
protected:
	bool isAI = false;
	std::shared_ptr<Character> aiCurrentTarget;
	std::vector<Attack> m_attacks;
	std::string m_characterName;
	HP m_hitPoints;

public:
	Character();
	std::string getName();
	HP getHp();
	void hit(int dmgReceived);
	void addAttack(Attack newAttack);
	std::vector<Attack> getAttacks();
	void runTurn(std::vector<std::shared_ptr<Character>> players, std::shared_ptr<Character> currentPlayer);
	~Character();

};

