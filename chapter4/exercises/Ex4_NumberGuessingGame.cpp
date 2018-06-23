#include <iostream>

int main() {
	std::cout << "Pick a number between 1 and 100 and I'll guess it in no more, than 7 tries!\n";
	int min = 0, max = 101;
	int currentGuess = 50;
	int numberOfGuesses = 0;
	std::string answer = "";
	bool finished = false;

	while (!finished && numberOfGuesses < 7) {
		std::cout << "Is your number less than " << currentGuess << "? ('y'/'n')\n";
		std::cin >> answer;
		if (answer == "n") {
			min = currentGuess;
			currentGuess = (currentGuess + max) / 2;
		} else if (answer == "y") {
			max = currentGuess;
			currentGuess = (currentGuess + min) / 2;
		} else {
			std::cout << "That's not a valid answer!\n";
			continue;
		}
		++numberOfGuesses;
		finished = (currentGuess == min) || (currentGuess == 100);
	}

	if (numberOfGuesses > 7) {
		std::cout << "You cheated!\n";
	} else {
		std::cout << "Is your number " << currentGuess << "? ('y'/'n')\n";
		std::cin >> answer;
		if (answer == "y") {
			std::cout << "Hurray! :D\n"
				<< "It took me " << numberOfGuesses << " tries to guess that!\n";
		} else {
			std::cout << "Stop lying, I know it is!\n";
		}
	}
	return 0;
}