#include <iostream>

using namespace std;

void Swap(int &a, int &b) {
	int c = a;
	a = b;
	b = c;
}

int main() {
	int a, b; cin >> a >> b;
	Swap(a, b);
	cout << a << ' ' << b;
}