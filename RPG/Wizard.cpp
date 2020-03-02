#include "Wizard.h"



Wizard::Wizard(std::string& name, bool AI)
{
	isAI = AI;
	m_characterName = name;
	m_hitPoints = HP(5, 1);
	std::string mainAttackName = "Main attack";
	Attack newAttack(10, 0, mainAttackName);
	addAttack(newAttack);
	std::string specialAttackName = "Special attack";
	Attack specialAttack(50, 3, specialAttackName);
	addAttack(specialAttack);

}
