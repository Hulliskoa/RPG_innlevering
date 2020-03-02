#pragma once
class HP
{
private:
	int m_HP = 0;
	int m_maxHP = 0;
	int m_AC = 0;

public:
	HP();
	HP(int HP, int AC);

	void operator-= (int dmg);
	void operator+= (int healing);
	bool operator== (int value) const;
	bool operator> (int value) const;
	bool operator< (int value) const;
	bool operator<= (int value) const;
	bool operator>= (int value) const;

	friend bool operator== (int value, const HP hp);
	friend bool operator> (int value, const HP hp);
	friend bool operator< (int value, const HP hp);
	friend bool operator<= (int value, const HP hp);
	friend bool operator>= (int value, const HP hp);

	bool operator> (HP hp) const;
	bool operator< (HP hp) const;
	bool operator<= (HP hp) const;
	bool operator>= (HP hp) const;

	int getHP();
	~HP();
};

