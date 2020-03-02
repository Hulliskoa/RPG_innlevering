#include "Druid.h"

Druid::Druid(std::string name, bool AI)
{
	isAI = AI;
	m_characterName = name;
	m_hitPoints = HP(100, 1);
	std::string mainAttackName = "Main attack";
	Attack newAttack(5, 0, mainAttackName);
	addAttack(newAttack);
	std::string specialAttackName = "Heal";
	Attack specialAttack(-25, 3, specialAttackName);
	addAttack(specialAttack);
}
