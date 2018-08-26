#include <iostream>

template<typename T>
class Number {
public:
	int val;

	Number(int val) : val{val} {}

	Number& operator=(int val) {
		this->val = val;
		return *this;
	}
	Number& operator=(const Number& other) {
		this->val = other.val;
		return *this;
	}

	Number operator+(int val) {
		Number res{this->val + val};
		return res;
	}
	Number operator+(const Number& other) {
		Number res{this->val + other.val};
		return res;
	}
	Number operator-(int val) {
		Number res{this->val - val};
		return res;
	}
	Number operator-(const Number& other) {
		Number res{this->val - other.val};
		return res;
	}
	Number operator*(int val) {
		Number res{this->val * val};
		return res;
	}
	Number operator*(const Number& other) {
		Number res{this->val * other.val};
		return res;
	}
	Number operator/(int val) {
		if (val == 0) {
			throw std::invalid_argument("Dividing by zero is not allowed");
		}
		Number res{this->val / val};
		return res;
	}
	Number operator/(const Number& other) {
		if (other.val == 0) {
			throw std::invalid_argument("Dividing by zero is not allowed");
		}
		Number res{this->val / other.val};
		return res;
	}

	void operator+=(int val) {
		this->val += val;
	}
	void operator+=(const Number& other) {
		this->val += other.val;
	}
	void operator-=(int val) {
		this->val -= val;
	}
	void operator-=(const Number& other) {
		this->val -= other.val;
	}
	void operator*=(int val) {
		this->val *= val;
	}
	void operator*=(const Number& other) {
		this->val *= other.val;
	}
	void operator/=(int val) {
		if (val == 0) {
			throw std::invalid_argument("Dividing by zero is not allowed");
		}
		this->val /= val;
	}
	void operator/=(const Number& other) {
		if (other.val == 0) {
			throw std::invalid_argument("Dividing by zero is not allowed");
		}
		this->val /= other.val;
	}
};

template<typename T> std::ostream& operator<<(std::ostream& out, const Number<T>& val) {
	out << val.val;
	return out;
}

template<typename T> std::istream& operator>>(std::istream& in, Number<T>& val) {
	in >> val.val;
	return in;
}

int main() {
	Number<int> a{7};
	std::cin >> a;
	std::cout << a << '\n';
	return 0;
}