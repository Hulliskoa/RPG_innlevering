#include "GameManager.h"
#include "Character.h"
#include "Wizard.h"
#include "Fighter.h"
#include "Druid.h"
#include <iostream>
#include <thread>
#include <chrono>

GameManager::GameManager() {}

void GameManager::startgame()
{
	int numPlayers = 0;
	int classType = 0;
	int numAI = 0;
	std::string playerName;
	std::cout << "Enter number of players: ";
	std::cin >> numPlayers;
	
	//https://stackoverflow.com/questions/18728754/checking-cin-input-stream-produces-an-integer

	if (std::cin.fail()) {
		std::cout << "Please enter a valid number: ";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> numPlayers;
	}


	std::cout << "\n";
	std::cout << "------------------------------" << std::endl;
	std::cout << "\n";
	std::cout << "Enter number of AI players: ";
	std::cin >> numAI;


	if (std::cin.fail()) {
		std::cout << "Please enter a valid number: ";
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> numAI;
	}

	//loop for character creation
	for (int i = 0; i < numPlayers; i++) {

		bool switchBool = true;
		std::cout << "\n";
		std::cout << "------------------------------" << std::endl;
		std::cout << "\n";
		std::cout << "Player " << i + 1 << ", please enter your name: ";
		std::cin >> playerName;
		std::cout << "Choose your class:" << std::endl;
		std::cout << "1. Wizard" << " | 2. Fighter" << " | 3. Druid" << std::endl;
		std::cin >> classType;

		if (std::cin.fail()) {
			std::cout << "Please enter a valid choice" << std::endl;
			std::cin >> classType;
		}
		

		while (switchBool) {
			switch (classType) {
			case 1:
				players.push_back(std::make_shared<Wizard>(Wizard(playerName, false)));
				std::cout << "Wizard chosen" << std::endl;
				switchBool = false;
				break;
			case 2:
				players.push_back(std::make_shared<Fighter>(Fighter(playerName, false)));
				std::cout << "Fighter chosen" << std::endl;
				switchBool = false;
				break;
			case 3:
				players.push_back(std::make_shared<Druid>(Druid(playerName, false)));
				std::cout << "Druid chosen" << std::endl;
				switchBool = false;
				break;
			default:
				std::cout << "Please enter a valid choice: " << std::endl;
				std::cin >> classType;
				switchBool = true;

			}
		}
		std::cout << "\n";
		std::cout << "------------------------------" << std::endl;
		std::cout << "\n";
	}

	for (int i = 0; i < numAI; i++) {
		int random = rand() % 3 + 1;
	
		std::string aiName = "AI-" + std::to_string(i + 1);
		std::cout << "AI " << i + 1 << " created" << std::endl;
		switch (random) {
		case 1:
			players.push_back(std::make_shared<Wizard>(Wizard(aiName, true)));
			break;
		case 2:
			players.push_back(std::make_shared<Fighter>(Fighter(aiName, true)));
			break;
		case 3:
			players.push_back(std::make_shared<Druid>(Druid(aiName, true)));
			break;
		default:
			std::cout << "error" << std::endl;
			break;
		}

	}



	//La til litt "loading" for å lage en følelse av at noe lastes
	std::cout << "Starting game";
	std::chrono::milliseconds duration(300);
	std::cout << ".";
	std::this_thread::sleep_for(duration);
	std::cout << ".";
	std::this_thread::sleep_for(duration);
	std::cout << ".";
	std::this_thread::sleep_for(duration);
	std::cout << "." << std::endl;

	

	//kjører run metoden så lenge det er mer enn 1 player med hp igjen
	while (numAlive > 1) {
		numAlive = 0;
		for (auto x : players) {
			if (x->getHp() > 0) {
				numAlive++;
			}
		
		}
		if (numAlive > 1) {
			run();
		}
	
	}

	//henter ut spilleren som har mer enn 0 hp og som dermed er vinneren
	std::vector<std::shared_ptr<Character>> playersWithHp;
	for (auto player : players) {
		if (player->getHp() > 0) {
			playersWithHp.push_back(player);
		}
	}
	std::cout << "Congratulations " << playersWithHp[0]->getName() << ", you are the champion!" << std::endl;

}

void GameManager::run()
{
	for (std::shared_ptr<Character> x : players) {

		if (x->getHp() == 0) {
			continue;
		}
		x->runTurn(players, x);

	}

}

GameManager::~GameManager() {}
