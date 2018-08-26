#include <iostream>

class Int {
private:
	int val;
public:
	Int(int val) : val{val} {}

	Int& operator=(int val) {
		this->val = val;
		return *this;
	}
	Int& operator=(const Int& other) {
		this->val = other.val;
		return *this;
	}

	Int operator+(int val) {
		Int res{this->val + val};
		return res;
	}
	Int operator+(const Int& other) {
		Int res{this->val + other.val};
		return res;
	}
	Int operator-(int val) {
		Int res{this->val - val};
		return res;
	}
	Int operator-(const Int& other) {
		Int res{this->val - other.val};
		return res;
	}
	Int operator*(int val) {
		Int res{this->val * val};
		return res;
	}
	Int operator*(const Int& other) {
		Int res{this->val * other.val};
		return res;
	}
	Int operator/(int val) {
		if (val == 0) {
			throw std::invalid_argument("Dividing by zero is not allowed");
		}
		Int res{this->val / val};
		return res;
	}
	Int operator/(const Int& other) {
		if (other.val == 0) {
			throw std::invalid_argument("Dividing by zero is not allowed");
		}
		Int res{this->val / other.val};
		return res;
	}

	void operator+=(int val) {
		this->val += val;
	}
	void operator+=(const Int& other) {
		this->val += other.val;
	}
	void operator-=(int val) {
		this->val -= val;
	}
	void operator-=(const Int& other) {
		this->val -= other.val;
	}
	void operator*=(int val) {
		this->val *= val;
	}
	void operator*=(const Int& other) {
		this->val *= other.val;
	}
	void operator/=(int val) {
		if (val == 0) {
			throw std::invalid_argument("Dividing by zero is not allowed");
		}
		this->val /= val;
	}
	void operator/=(const Int& other) {
		if (other.val == 0) {
			throw std::invalid_argument("Dividing by zero is not allowed");
		}
		this->val /= other.val;
	}
friend std::ostream& operator<<(std::ostream& out, const Int& val);
friend std::istream& operator>>(std::istream& in, Int& val);
};

std::ostream& operator<<(std::ostream& out, const Int& val) {
	out << val.val;
	return out;
}

std::istream& operator>>(std::istream& in, Int& val) {
	in >> val.val;
	return in;
}

int main() {
	Int a{7};
	std::cin >> a;
	std::cout << a << '\n';
	return 0;
}