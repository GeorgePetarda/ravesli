#include <iostream>

using namespace std;

int getNumber() {
	cout << "Enter a double value: ";
	int number; cin >> number;
	return number;
}

char getSymbol() {
	cout << "Enter one of the following: ";
	char symbol; cin >> symbol;
	return symbol;
}

void printResult(int a, int b, char symbol, int result) {
	cout << a << ' ' << symbol << ' ' << b << " = " << result;
}

int main() {
	int a = getNumber();
	int b = getNumber();
	const char symbol = getSymbol();
	int result;
	if (symbol == '+') {
		result = a + b;
	}
	if (symbol == '-') {
		result = a - b;
	}
	if (symbol == '*') {
		result = a * b;
	}
	if (symbol == '/') {
		result = a / b;
	}
	printResult(a, b, symbol, result);
}