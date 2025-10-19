#include "io.h"

int readNumber();

void writeAnswer(int a, int b);

int main() {
	int a = readNumber();

	int b = readNumber();

	writeAnswer(a, b);
}