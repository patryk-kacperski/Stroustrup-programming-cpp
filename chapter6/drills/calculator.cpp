#include <iostream>

/* Expressions will be evaluated using following grammar
Expression:
	Term
	Expression "+" Term
	Expression "-" Term
Term:
	Primary
	Term "*" Primary
	Term "/" Primary
	Term "%" Primary
Primary:
	Number
	"(" Expression ")"
Number:
	floating-point literal
*/

class Token {
public:
    char kind;        // what kind of token
    double value;     // for numbers: a value 
    Token(char ch)    // make a Token from a char
        :kind(ch), value(0) { }    
    Token(char ch, double val)     // make a Token from a char and a double
        :kind(ch), value(val) { }
};

// Reads characters and composes tokens
Token getToken();

// Deals with + and -
double expression();

// Deals with *, / and %
double term();

// Deals with numbers and parentheses
double primary();

double expression() {
	double left = term();
	Token t = getToken();
	while (true) {
		switch (t.kind) {
		case '+':
			left += term();
			t = getToken();
			break;
		case '-':
			left -= term();
			t = getToken();
			break;
		default:
			return left;
		}
	}
}

double term() {
	double left = primary();
	Token t = getToken();
	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			t = getToken();
			break;
		case '/': {
			double d = primary();
			if (d == 0) {
				throw std::runtime_error("division by 0");
			}
			left /= primary();
			t = getToken();
			break;			
		}
		default:
			return left;
		}
	}	
}

double primary() {
	Token t = getToken();
	switch (t.kind) {
	case '(': {
		double d = expression();
		t = getToken();
		if (t.kind != ')') {
			throw std::runtime_error("missing ')'");
		}
		return d;
	}
	case '8':
		return t.value;
	default:
		throw std::runtime_error("primary expected");
	}
}

Token getToken() {
	char ch;
    std::cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
 //not yet   case ';':    // for "print"
 //not yet   case 'q':    // for "quit"
    case '(': case ')': case '+': case '-': case '*': case '/': 
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
        {    
            std::cin.putback(ch);         // put digit back into the input stream
            double val;
            std::cin >> val;              // read a floating-point number
            return Token('8',val);   // let '8' represent "a number"
        }
    default:
    	throw std::runtime_error("Bad token");
    }
}

int main() {
	try {
		while (std::cin) {
			std::cout << expression() << '\n';
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
		return 1;
	} catch (...) {
		std::cerr << "Unknown error ocurred \n";
		return 2;
	}
}