#include <iostream>
#include <ctime>
#include <cstdlib>

int main() {
	srand(time(0));
	// Prepare answer
	std::string answer {"xxxx"};
	for (int i = 0; i < 4; ++i) {
		char digit = (rand() % 10) + '0'; 
		while (answer.find(digit) != std::string::npos) {
			digit = (digit - '0' + 1) % 10 + '0';
		}
		answer[i] = digit;
	}

	int bulls {0}, cows {0}, numberOfPlayerMoves {0};
	std::string guess;
	std::cout << "Game of bulls and cows! Rules:\n"
		<< "Program randomly selects a sequence of 4 different digits\n"
		<< "Your task is to guess it in as little moves as possible\n"
		<< "Whenever you enter a guess you get following score:\n"
		<< "\tYou get 1 bull for each digit that is at the correct place of the sequence\n"
		<< "\tYou get 1 cow for each digit that is in the sequence, but in the wrong place\n"
		<< "Once you get 4 bulls you win! Good luck!\n\n";
	// Game loop
	while (bulls != 4) {
		// Read guess
		bulls = 0;
		cows = 0;
		std::cout << "Enter a guess: ";
		std::cin >> guess;
		while (guess.size() != 4) {
			std::cout << "Wrong input!\n\n"
				<< "Enter a guess: ";
			std::cin >> guess;
		}
		// Test guess
		for (int i = 0; i < 4; ++i)
		{
			if (guess[i] == answer[i]) {
				bulls++;
			} else if (answer.find(guess[i]) != std::string::npos) {
				cows++;
			}
		}
		++numberOfPlayerMoves;
		// Print result of a guess
		std::cout << "Your current result is\n"
			<< "bulls: " << bulls << " cows: " << cows << "\n\n";
	}
	// Print game result
	std::cout << "Congratulations, you won! It took you " << numberOfPlayerMoves << " guesses!\n";
	return 0;
}