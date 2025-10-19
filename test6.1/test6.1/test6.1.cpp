#include <iostream>

using namespace std;

enum TypeItems {
	HELTH_POTIONS,
	TORCHES,
	ARROWS
};

const int MAX_ITEMS = 3;

int countTotalItems(int items[]) {
	int count = 0;
	for (int i = 0; i < MAX_ITEMS; i++) {
		count += items[i];
	}
	return count;
}

int main() {
	int items[MAX_ITEMS] = { 3, 6, 12 };
	cout << "You have " << countTotalItems(items) << " items";
}
