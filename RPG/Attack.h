#pragma once

#include <string>

class Attack
{
private:
	int m_damage;
	int m_cooldown;
	int turnsSinceLastAttack;
	std::string m_name;

public:

	Attack(int dmg, int cooldown, std::string& name);

	int getDamage();

	int getCoolDown();

	std::string getName();

	bool isReady();

	int attackTarget();

	void run();

	~Attack();
};

