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

class Token_stream {
public: 
    Token_stream();   // make a Token_stream that reads from cin
    Token get();      // get a Token (get() is defined elsewhere)
    void pushback(Token t);    // put a Token back
private:
    bool full;        // is there a Token in the buffer?
    Token buffer;     // here is where we keep a Token put back using putback()
};

Token_stream::Token_stream()
:full(false), buffer(0)    // no Token in buffer
{
}

void Token_stream::pushback(Token t)
{
    if (full) {
    	std::runtime_error("pushback() into a full buffer");
    }
    buffer = t;       // copy t to buffer
    full = true;      // buffer is now full
}


Token Token_stream::get()
{
    if (full) {       // do we already have a Token ready?
        // remove token from buffer
        full=false;
        return buffer;
    } 

    char ch;
    std::cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
    case ';':    // for "print"
    case 'q':    // for "quit"
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
    	std::runtime_error("Bad token");
    }
}

Token_stream ts;

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
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term();
			t = ts.get();
			break;
		default:
			ts.pushback(t);
			return left;
		}
	}
}

double term() {
	double left = primary();
	Token t = ts.get();
	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			t = ts.get();
			break;
		case '/': {
			double d = primary();
			if (d == 0) {
				throw std::runtime_error("division by 0");
			}
			left /= primary();
			t = ts.get();
			break;			
		}
		default:
			ts.pushback(t);
			return left;
		}
	}	
}

double primary() {
	Token t = ts.get();
	switch (t.kind) {
	case '(': {
		double d = expression();
		t = ts.get();
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

int main() {
	try {
		double val = 0;
		while (std::cin) {
			Token t = ts.get();
			if (t.kind == 'q') {
				break;
			}
			if (t.kind == ';') {
				std::cout << "=" << val << '\n';
			} else {
				ts.pushback(t);
			}
			val = expression();
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << '\n';
		return 1;
	} catch (...) {
		std::cerr << "Unknown error ocurred \n";
		return 2;
	}
}