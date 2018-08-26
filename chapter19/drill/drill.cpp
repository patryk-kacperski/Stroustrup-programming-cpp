#include <iostream>
#include <string>
#include <vector>

template<typename T> struct S {
	S(T val) : val{val} {}

	T& get();
	const T& get() const;

	S& operator=(const T& val);

private:
	T val;
};

template<typename T> T& S<T>::get() { return val; }
template<typename T> const T& S<T>::get() const { return val; }

template<typename T> S<T>& S<T>::operator=(const T& val) {
	this->val = val;
	return *this;
}

template<typename T> void readVal(T& v) {
	std::cin >> v;
}

int main() {
	S<int> a{0};
	S<char> b{0};
	S<double> c{0};
	S<std::string> d{""};
	S<std::vector<int>> e{{1, 2, 3, 4, 5}};

	std::cout << "Enter an int: ";
	readVal(a.get());
	std::cout << "Enter a char: ";
	readVal(b.get());
	std::cout << "Enter a double: ";
	readVal(c.get());
	std::cout << "Enter a string: ";
	readVal(d.get());

	std::cout << "int: " << a.get() << '\n';
	std::cout << "char: " << b.get() << '\n';
	std::cout << "double: " << c.get() << '\n';
	std::cout << "string: " << d.get() << '\n';
	std::cout << "vector: ";
	for (int i : e.get()) std::cout << e.get()[i] << ' ';
	std::cout << '\n';
	return 0;
}