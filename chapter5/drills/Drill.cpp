#include <iostream>
#include <vector>
#include <exception>

int main() {
	try {
		// 1
		// std::Cout << "Success!\n";
		/*********************/
		// std::cout << "Success!\n";

		// 2
		// std::cout << "Success!\n;
		/*********************/
		// std::cout << "Success!\n";

		// 3
		// std::cout << "Success" << !\n"
		/*********************/
		// std::cout << "Success" << "!\n";

		// 4
		// std::cout << success << '\n';
		/*********************/
		// std::cout << "Success!" << '\n';

		// 5
		// std::string res = 7;
		// std::vector<int> v(10);
		// v[5] = res;
		// std::cout << "Success!\n";
		/*********************/
		// int res = 7;
		// std::vector<int> v(10);
		// v[5] = res;
		// std::cout << "Success!\n";

		// 6
		// std::vector<int> v(10);
		// v(5) = 7;
		// if (v(5) != 7)
		// 	std::cout << "Success!\n";
		/*********************/
		// std::vector<int> v(10);
		// v[5] = 7;
		// if (v[5] == 7)
		// 	std::cout << "Success!\n";

		// 7
		// if (cond) {
		// 	std::cout << "Success!\n";
		// } else {
		// 	std::cout << "Fail!\n";
		// }
		/*********************/
		// if (true) {
		// 	std::cout << "Success!\n";
		// } else {
		// 	std::cout << "Fail!\n";
		// }

		// 8
		// bool c = false;
		// if (c) {
		// 	std::cout << "Success!\n";
		// } else {
		// 	std::cout << "Fail!\n";
		// }
		/*********************/
		// bool c = true;
		// if (c) {
		// 	std::cout << "Success!\n";
		// } else {
		// 	std::cout << "Fail!\n";
		// }

		// 9
		// std::string s = "ape";
		// boo c = "fool" < s;
		// if (c) {
		// 	std::cout << "Success!\n";
		// }
		/*********************/
		// std::string s = "ape";
		// bool c = "fool" > s;
		// if (c) {
		// 	std::cout << "Success!\n";
		// }

		// 10
		// std::string s = "ape";
		// if (s == "fool") {
		// 	std::cout << "Success!\n";
		// }
		/*********************/
		// std::string s = "ape";
		// if (s != "fool") {
		// 	std::cout << "Success!\n";
		// }

		// 11
		// std::string s = "ape";
		// if (s == "fool") {
		// 	std::cout < "Success!\n";
		// }
		/*********************/
		// std::string s = "ape";
		// if (s != "fool") {
		// 	std::cout << "Success!\n";
		// }

		// 12
		// std::string s = "ape";
		// if (s+"fool") {
		// 	std::cout << "Success!\n";
		// }
		/*********************/
		// std::string s = "ape";
		// if (s != "fool") {
		// 	std::cout << "Success!\n";
		// }
		return 0;
	} catch (std::exception& e) {
		std::cerr << "error: " << e.what() << '\n';
		return 1;
	} catch (...) {
		std::cerr << "Oops: unknown exception!\n";
		return 2;
	}
}