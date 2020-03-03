#include "Attack.h"
#include <iostream>

Attack::Attack(int dmg, int cooldown, std::string& name, ActionType actionType) : m_damage(dmg), m_cooldown(cooldown), m_name(name), actionType(actionType)
{
	turnsSinceLastAttack = cooldown;

}

int Attack::getDamage()
{
	return m_damage;
}

int Attack::getCoolDown()
{
	if ((m_cooldown - turnsSinceLastAttack) < 0) {
		return 0;
	}
	else {
		return m_cooldown - turnsSinceLastAttack;
	}

}


std::string Attack::getName()
{
	return m_name;
}

bool Attack::isReady()
{
	
	return m_cooldown <= turnsSinceLastAttack;
}

int Attack::attackTarget()
{
	if (isReady()) {
		turnsSinceLastAttack = 0;
		return m_damage;
	}
	else {
		std::cout << "On cooldown." << std::endl;
		std::cout << m_cooldown - turnsSinceLastAttack;
		std::cout << " turns left of cooldown" << std::endl;
		return 0;
	}

}

ActionType Attack::getActionType()
{
	return actionType;
}

void Attack::run()
{
	turnsSinceLastAttack++;
}

Attack::~Attack() {};

