#include "Druid.h"

Druid::Druid(std::string name, bool AI)
{
	isAI = AI;
	m_characterName = name;
	m_hitPoints = HP(100, 1);
	std::string mainAttackName = "Main attack";
	addAttack(std::make_shared<Attack>(5, 0, mainAttackName, offensive));
	std::string specialAttackName = "Heal";
	addAttack(std::make_shared<Attack>(25, 3, specialAttackName, heal));
}
