#include "Wizard.h"



Wizard::Wizard(std::string& name, bool AI)
{
	isAI = AI;
	m_characterName = name;
	m_hitPoints = HP(5, 1);
	std::string mainAttackName = "Main attack";
	addAttack(std::make_shared<Attack>(10, 0, mainAttackName, offensive));
	std::string specialAttackName = "Special attack";
	addAttack(std::make_shared<Attack>(50, 3, specialAttackName, offensive));


}
