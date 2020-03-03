#include "Fighter.h"

Fighter::Fighter(std::string& name, bool AI)
{
	isAI = AI;
	m_characterName = name;
	m_hitPoints = HP(200, 3);
	std::string mainAttackName = "Main attack";
	addAttack(std::make_shared<Attack>(5, 0, mainAttackName, offensive));
	std::string specialAttackName = "Special attack";
	addAttack(std::make_shared<Attack>(20, 2, specialAttackName, offensive));
}
