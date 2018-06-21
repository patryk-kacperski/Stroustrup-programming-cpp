#include <iostream>

int main() {
	std::string firstName;
	std::cout << "Enter the name of the person you want to write to: ";
	std::cin >> firstName;
	std::cout << "Dear " << firstName << ",\nHow are you?\nI am fine.\nI miss you.\n";
	std::cout << "Enter the name of your firend: ";

	std::string friendName;
	std::cin >> friendName;
	std::cout << "Have you seen " << friendName << " lately?\n";

	char friendGender {0};
	std::cout << "If your friend is male please enter 'm'. Otherwise enter 'f': ";
	std::cin >> friendGender;
	if (friendGender == 'm') {
		std::cout << "If you see " << friendName << " please ask him to call me\n";
	}
	if (friendGender == 'f') {
		std::cout << "If you see " << friendName << " please ask her to call me\n";
	}

	int age;
	std::cout << "Enter the age of the recipient: ";
	std::cin >> age;
	std::cout << "I hear you just had a birthday and you are " << age << " years old\n";

	if (age < 12) {
		std::cout << "Next year you will be " << age + 1 << '\n';
	}
	if (age == 17) {
		std::cout << "Next year you will be able to vote\n";
	}
	if (age > 70) {
		std::cout << "I hope you're enjoying retirement\n";
	}

	std::cout << "Yours sincerely\n\n Patryk\n";
	return 0;
}