#include "HP.h"
#include <iostream>

HP::HP(){}

HP::HP(int HP, int AC):m_maxHP(HP), m_HP(HP), m_AC(AC){}

void HP::operator-=(int dmg)
{
	int reducedDmg = dmg - m_AC;
	if (m_HP - reducedDmg <= 0) {
		m_HP = 0;
	}
	else {
		m_HP -= reducedDmg;
		std::cout << "Target lost " << reducedDmg <<"HP and has "  << m_HP << "HP left" << std::endl;
	}

}

void HP::operator+=(int healing)
{
	if ((m_HP + healing) >= m_maxHP) {
		m_HP = m_maxHP;
	}
	else {
		m_HP += healing;
	}
}

bool HP::operator==(int value) const
{
	return m_HP == value;
}

bool HP::operator>(int value) const
{
	return m_HP > value;
}

bool HP::operator<(int value) const
{
	return m_HP < value;
}

bool HP::operator<=(int value) const
{
	return m_HP <= value;
}

bool HP::operator>=(int value) const
{
	return m_HP >= value;
}

bool HP::operator>(HP hp) const
{
	return m_HP > hp.m_HP;
}

bool HP::operator<(HP hp) const
{
	return m_HP < hp.m_HP;
}

bool HP::operator<=(HP hp) const
{
	return m_HP <= hp.m_HP;
}

bool HP::operator>=(HP hp) const
{
	return m_HP >= hp.m_HP;
}

int HP::getHP()
{
	return m_HP;
}

bool operator==(int value, const HP hp)
{
	return value == hp.m_HP;
}

bool operator>(int value, const HP hp)
{
	return value > hp.m_HP;
}

bool operator<(int value, const HP hp)
{
	return value < hp.m_HP;
}

bool operator<=(int value, const HP hp)
{
	return value <= hp.m_HP;
}

bool operator>=(int value, const HP hp)
{
	return value >= hp.m_HP;
}


HP::~HP() {}