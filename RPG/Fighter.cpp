#include "Fighter.h"

Fighter::Fighter(std::string& name, bool AI)
{
	isAI = AI;
	m_characterName = name;
	m_hitPoints = HP(200, 3);
	std::string mainAttackName = "Main attack";
	Attack newAttack(5, 0, mainAttackName);
	addAttack(newAttack);
	std::string specialAttackName = "Special attack";
	Attack specialAttack(20, 2, specialAttackName);
	addAttack(specialAttack);
}
