#include <iostream>
#include "Consts.h"

using namespace std;

int getStartHeight() {
	cout << "Enter the initial height of the tower in meters: ";
	int n; cin >> n;
	return n;
}

double calcHeight(int seconds, double currentHeight) {
	double distanceFallen = G * (pow(seconds, 2) / 2);
	currentHeight -= distanceFallen;
	if (currentHeight <= 0) {
		currentHeight = 0;
	}
	return currentHeight;
}

void printHeight(double height, int seconds) {
	if (height == 0) {
		cout << "At " << seconds << " seconds, the ball is on the ground." << endl;
	}
	else {
		cout << "At " << seconds << " seconds, the ball is at height: " << height << " meters" << endl;
	}

}

int main() {
	double currentHeight = getStartHeight();
	for (int i = 0; i <= 5; i++) {
		double height = calcHeight(i, currentHeight);
		printHeight(height, i);
	}
}