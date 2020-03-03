#include "Character.h"

Character::Character() {}

std::string Character::getName()
{
	return m_characterName;
}

HP Character::getHp()
{
	return m_hitPoints;
}

void Character::hit(int dmgReceived)
{
	m_hitPoints -= dmgReceived;
}

void Character::addAttack(std::shared_ptr<Attack> newAttack)
{
	m_attacks.push_back(newAttack);
}

std::vector<std::shared_ptr<Attack>> Character::getAttacks()
{
	return m_attacks;
}

void Character::runTurn(std::vector<std::shared_ptr<Character>> players, std::shared_ptr<Character> currentPlayer)
{

	int chosenPlayer;
	int chosenAttack;
	bool validChoice = true;
	bool validPlayer = true;
	std::vector<std::shared_ptr<Character>> availablePlayers;
	std::vector<std::shared_ptr<Attack>> availableAttacks;
	int counter = 1;

	//sjekker om den boolske verdien isAI i character classen er satt til true

	if (isAI) {
		//ai kode
		for (std::shared_ptr<Character> player : players) {
			if (player != currentPlayer && player->getHp() > 0) {
				availablePlayers.push_back(player);
			}
		}
		//sjekker hvilke attacks som ikke har cooldown
		for (auto attack : m_attacks) {
			if (attack->isReady()) {
				availableAttacks.push_back(attack);
			}
		}
		//sjekker om AI'en har et "target" hvis ikke settes target på nytt
		if (aiCurrentTarget != nullptr) {
			if (aiCurrentTarget->getHp() == 0) {
				aiCurrentTarget = availablePlayers[rand() % availablePlayers.size()];
			}
		}
		else {
			aiCurrentTarget = availablePlayers[rand() % availablePlayers.size()];
		}


		int randomAttack = rand() % availableAttacks.size();
	
		//sjekker om ai har valgt heal
		if (availableAttacks[randomAttack]->getActionType() == offensive) {
			std::cout << getName() << " attacked " << aiCurrentTarget->getName() << std::endl;
			aiCurrentTarget->hit(availableAttacks[randomAttack]->attackTarget());
		}
		else {
			std::cout << getName() << " healed for: " << availableAttacks[randomAttack]->getDamage() << " HP"  << std::endl;
			currentPlayer->m_hitPoints += availableAttacks[randomAttack]->getDamage();
		}
	

		if (aiCurrentTarget->getHp() == 0) {
			std::cout << aiCurrentTarget->getName() << " died" << std::endl;
		}
		availableAttacks.clear();
		std::cout << "\n";
		std::cout << "------------------------------" << std::endl;
		std::cout << "\n";
	}
	else {


		std::cout << getName();
		std::cout << " - Please choose your target" << std::endl;

		std::cout << "\n";


		//while loop for å håndtere feil input fra spiller
		while (validPlayer) {
			validPlayer = false;
			for (std::shared_ptr<Character> player : players) {
				if (player != currentPlayer && player->getHp() > 0) {
					std::cout << counter << ". " << player->getName() << " - HP: " << player->getHp().getHP() << std::endl;
					availablePlayers.push_back(player);
					counter++;
				}
			}

			std::cin >> chosenPlayer;

			if (std::cin.fail()) {
				std::cout << "Please enter a valid number: ";
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cin >> chosenPlayer;
			}

			//sjekker om valget er innenfor antall spillere
			if (chosenPlayer > availablePlayers.size()) {
				std::cout << "Please enter a valid choice" << std::endl;
				validPlayer = true;
				counter = 1;
				availablePlayers.clear();
			}


			std::cout << "\n";
			std::cout << "------------------------------" << std::endl;
			std::cout << "\n";
			chosenPlayer -= 1;


		}

		std::cout << getName() << " - Please choose your action" << std::endl;
		counter = 1;


		//while loop for å håndtere feil input fra spiller
		while (validChoice) {
			validChoice = false;
			for (auto attack : m_attacks) {
				if (attack->isReady()) {
					std::cout << counter << ". " << attack->getName() << " - DMG: " << attack->getDamage() << " - Cooldown: " << attack->getCoolDown() << " turns" << std::endl;
					availableAttacks.push_back(attack);
					counter++;
				}
				else {
					std::cout << "X" << ". " << attack->getName() << " - DMG: " << attack->getDamage() << " - Cooldown: " << attack->getCoolDown() << " turns" << std::endl;
				}
			}
			std::cin >> chosenAttack;

			if (std::cin.fail()) {
				std::cout << "Please enter a valid number: ";
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cin >> chosenAttack;
			}


			//sjekker om valget er innenfor antall angrep som er tilgjengelig
			if (chosenAttack > availableAttacks.size()) {
				std::cout << "Please enter a valid choice" << std::endl;
				validChoice = true;
				counter = 1;
				availableAttacks.clear();

			}
			chosenAttack -= 1;
		}

		//sjekker om angrepet er offensivt eller ikke
		if (availableAttacks[chosenAttack]->getActionType() == offensive) {
			//angriper valgt spiller med valgt angrep
			availablePlayers[chosenPlayer]->hit(availableAttacks[chosenAttack]->attackTarget());
		}
		else {
			std::cout << getName() << " healed for: " << availableAttacks[chosenAttack]->getDamage() << " HP" << std::endl;
			currentPlayer->m_hitPoints += availableAttacks[chosenAttack]->getDamage();
		}

	
		
		std::cout << "\n";
		std::cout << "------------------------------" << std::endl;
		std::cout << "\n";


		availableAttacks.clear();
	}

	//kjører run for å holde oversikt over cooldown
	for (auto x : m_attacks) {
		x->run();
	}
}
Character::~Character() {};
