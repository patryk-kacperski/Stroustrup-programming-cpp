#include <iostream>
#include <vector>
#include <fstream>
#include <string>

constexpr int numberOfPointsToRead = 7;
const std::string fileName = "mydata.txt";

struct Point {
	double x;
	double y;
};

void read(std::vector<Point> &v) {
	std::cout << "Please enter " << numberOfPointsToRead << " pairs of coordinates\n";
	for (int i = 0; i < numberOfPointsToRead; ++i) {
		double x, y;
		std::cin >> x >> y;
		v.push_back({x, y});
	}
}

void print(std::vector<Point> const &v) {
	for (Point p : v) {
		std::cout << "(" << p.x << ", " << p.y << ")\n";
	}
}

void printToFile(std::vector<Point> const &v) {
	std::ofstream fout {fileName};
	if (!fout) {
		throw std::runtime_error("File not opened!");
	}
	for (Point p : v) {
		fout << "(" << p.x << ", " << p.y << ")\n";
	}
}

void readFromFile(std::vector<Point> &v) {
	std::ifstream fin {fileName};
	if (!fin) {
		throw std::runtime_error("File not opened!");
	}
	char c1, c2, c3; // '(', ',', and ')''
	double x, y;
	while (fin >> c1) {
		fin >> x >> c2 >> y >> c3;
		v.push_back({x, y});
	}
}

bool compare(std::vector<Point> const &v1, std::vector<Point> const &v2) {
	if (v1.size() != v2.size()) {
		return false;
	}
	for (unsigned int i = 0; i < v1.size(); ++i) {
		if (v1[i].x != v2[i].x || v1[i].y != v2[i].y) {
			return false;
		}
	}
	return true;
}

int main() {
	std::vector<Point> originalPoints;
	std::vector<Point> processedPoints;

	read(originalPoints);
	std::cout << "\nOriginal points:\n";
	print(originalPoints);
	printToFile(originalPoints);
	readFromFile(processedPoints);
	std::cout << "\nProcessed points: \n";
	print(processedPoints);
	bool areSame = compare(originalPoints, processedPoints);
	std::cout << (areSame ? "Vectors are the same" : "Something's wrong!");
	return 0;
}