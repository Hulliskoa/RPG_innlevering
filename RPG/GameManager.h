#pragma once
#include "Character.h"
class GameManager
{
private:
	std::vector<std::shared_ptr<Character>> players;
	int numAlive = 100;//vilk�rlig tall over 1 for � holde oversikt over antall spillere etter start

public:
	GameManager();
	void startgame();
	void run();
	~GameManager();
};

