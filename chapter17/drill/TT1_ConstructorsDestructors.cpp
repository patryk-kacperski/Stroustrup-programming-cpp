#include <iostream>

class A
{
public:
	A() {
		std::cout << "A constructed\n";
	}
	virtual ~A() {
		std::cout << "A destructed\n";
	}
	
};

class B: public A
{
public:
	B() {
		std::cout << "B constructed\n";
	}
	~B() {
		std::cout << "B destructed\n";
	}
};

class C
{
public:
	A* a;
	C() {
		a = new A{};
		std::cout << "C constructed\n";
	}
	~C() {
		delete a;
		std::cout << "C destructed\n";
	}
	
};

int main() {
	A a;
	B b;
	C c;
	A* p = new B();
	delete p;
	return 0;
}