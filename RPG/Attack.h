#pragma once

#include <string>


enum ActionType { heal, offensive };

class Attack
{
private:
	ActionType actionType;
	int m_damage;
	int m_cooldown;
	int turnsSinceLastAttack;
	std::string m_name;

public:

	Attack(int dmg, int cooldown, std::string& name, ActionType actionType);

	int getDamage();

	int getCoolDown();

	std::string getName();

	bool isReady();

	int attackTarget();
	ActionType getActionType();
	void run();

	~Attack();
};

