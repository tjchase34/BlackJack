#include <iostream>
#include <string>
#include <cstdlib>


int dealt_hand;
int hand;
int comp_hand;

int bet_amount;
int chips = 50;

char choice1;
char playagain1;

void play() {

	int dealt_hand = (rand() % 17 + 3);
	int comp_hand = (rand() % 10 + 15);

	hand = dealt_hand;

	std::cout << "-------------------------" << std::endl;
	std::cout << "| Welcome to BlackJack! |" << std::endl;
	std::cout << "-------------------------" << std::endl;

	std::cout << "You have " << chips << " chips" << std::endl;
	std::cout << "How many chips would you like to bet?" << std::endl;
	std::cin >> bet_amount;

	for (int i=0; i < 100; i=i+1) {

		std::cout << "Your hand is currently " << hand << std::endl;

		if (((hand > 21) && (comp_hand <= 21)) || (hand > 21)) {
			std::cout << "You bust and the dealer wins!" << std::endl;
			std::cout << "You lost " << bet_amount << " chips!" << std::endl;
			chips = chips - bet_amount;
			break;
		}

		if (hand == 21) {
			std::cout << "Blackjack!" << std::endl;
			std::cout << "The dealers hand is " << comp_hand << std::endl;

			if (hand == comp_hand) {
				std::cout << "It's a draw!" << std::endl;
				std::cout << "Chips returned!" << std::endl;
				break;
			}	
			else {
				std::cout << "You win!" << std::endl;
				std::cout << "You have won " << bet_amount << " chips!" << std::endl;
				chips = chips + bet_amount;
				break;
			}
		}

		std::cout << "Would you like to (h)it or (s)tay?" << std::endl;
		std::cin >> choice1;

		if (choice1 == 'h') {
			hand = hand + (rand() % 11 + 1);
		}

		if (choice1 == 's') {
			std::cout << "Your hand is " << hand << std::endl;

			if (hand == 21) {
				std::cout << "Blackjack!" << std::endl;
			}

			std::cout << "The dealers hand is " << comp_hand << std::endl;

			if ((hand <= 21) && (comp_hand > 21)) {
				std::cout << "The dealer has bust!" << std::endl;
			}

			if (comp_hand == 21) {
				std::cout << "The dealer has blackjack!" << std::endl;
			}

			if (hand == comp_hand) {
				std::cout << "It's a draw!" << std::endl; 
				std::cout << "Chips returned!" << std::endl;
			}

			if (((hand > comp_hand) && (comp_hand != 21)) || ((hand <= 21) && (comp_hand != 21) && (hand > comp_hand))  || (comp_hand > 21) && (hand <= 21)) {
				std::cout << "You win!" << std::endl; 
				std::cout << "You have won " << bet_amount << " chips!" << std::endl;
				chips = chips + bet_amount;
			}

			if (((hand < comp_hand) && (hand != 21) && (comp_hand <=21)) || ((comp_hand <= 21) && (hand != 21) && (comp_hand > hand)) || (hand > 21) && (comp_hand <= 21)) {
				std::cout << "The dealer wins!" << std::endl;
				std::cout << "You have lost " << bet_amount << " chips!" << std::endl;
				chips = chips - bet_amount; 
			}

			break;
		}		
	}

	playagain1 = 'n';
}

int main() { 

	srand(time(0));

	play();

	playagain1 = 'n';

	for (int i=0; i < 100;) {

		if (chips == 0) {
			std::cout << "You are out of chips!" << std::endl;
			std::cout << "The game is over!" << std::endl;
			break;
		}

		std::cout << "Would you like to play again? (y/n)" << std::endl;

		std::cin >> playagain1;

		if (playagain1 != 'y') {
			break;
		}

		while (playagain1 == 'y') {

			if (playagain1 == 'y') {
				i = i+1;
				play();		
			}

			else {
				break;
			}

		}

	}

	return (0);

}
