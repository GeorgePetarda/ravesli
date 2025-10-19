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

bool printHeight(double height, int seconds) {
	if (height == 0) {
		cout << "At " << seconds << " seconds, the ball is on the ground." << endl;
		return false;
	}
	else {
		cout << "At " << seconds << " seconds, the ball is at height: " << height << " meters" << endl;
		return true;
	}

}

int main() {
	double currentHeight = getStartHeight();
	int cntSeconds = 0;
	double height = calcHeight(cntSeconds, currentHeight);
	while (printHeight(height, cntSeconds)) {
		height = calcHeight(cntSeconds, currentHeight);
		cntSeconds++;
	}
}