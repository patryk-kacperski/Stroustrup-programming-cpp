#include <iostream>
#include <vector>

template<typename T> void addVectors(std::vector<T> &v1, std::vector<T> &v2) {
	if (v1.size() != v2.size()) { throw std::invalid_argument("Vectors must be of the same size"); }
	for (int i = 0; i < v1.size(); ++i) {
		v1[i] += v2[i];
	}
}

template<typename T> void printVector(const std::vector<T> &v) {
	for (int i : v) {
		std::cout << i << ' ';
	}
}

int main() {
	std::vector<int> v1 {1, 2, 3, 4, 5};
	std::vector<int> v2 {3, 3, 3, -1, 3};
	addVectors(v1, v2);
	printVector(v1);
	return 0;
}