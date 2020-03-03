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
	if (dmgReceived < 0) {
		m_hitPoints += -dmgReceived;
	}
	else {
		m_hitPoints -= dmgReceived;
	}


}

void Character::addAttack(Attack newAttack)
{
	m_attacks.push_back(newAttack);
}

std::vector<Attack> Character::getAttacks()
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
	std::vector<Attack> availableAttacks;
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
		for (Attack attack : m_attacks) {
			if (attack.isReady()) {
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
		std::cout << getName() << " attacked " << aiCurrentTarget->getName() << std::endl;
		aiCurrentTarget->hit(m_attacks[randomAttack].attackTarget());

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
			for (Attack attack : m_attacks) {
				if (attack.isReady()) {
					std::cout << counter << ". " << attack.getName() << " - DMG: " << attack.getDamage() << " - Cooldown: " << attack.getCoolDown() << " turns" << std::endl;
					availableAttacks.push_back(attack);
					counter++;
				}
				else {
					std::cout << "X" << ". " << attack.getName() << " - DMG: " << attack.getDamage() << " - Cooldown: " << attack.getCoolDown() << " turns" << std::endl;
				}
			}
			std::cin >> chosenAttack;

			//sjekker om valget er innenfor antall angrep som er tilgjengelig
			if (chosenAttack > availableAttacks.size()) {
				std::cout << "Please enter a valid choice" << std::endl;
				validChoice = true;
				counter = 1;
				availableAttacks.clear();

			}
			chosenAttack -= 1;
		}

		//angriper valgt spiller med valgt angrep
		availablePlayers[chosenPlayer]->hit(m_attacks[chosenAttack].attackTarget());
		std::cout << "\n";
		std::cout << "------------------------------" << std::endl;
		std::cout << "\n";


		availableAttacks.clear();
	}

	//kjører run for å holde oversikt over cooldown
	for (Attack x : m_attacks) {
		x.run();
	}
}
Character::~Character() {};
