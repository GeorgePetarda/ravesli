#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int Start();
bool check(int hiddenNumber, int guessNumber);
void playAgain();
void play();
bool guesses(int attempts, int hiddenNumber);
int checkInput();

int Start() {
	cout << "Let's play a game. I'm thinking of a number. You have 7 tries to guess what it is." << endl;
	rand();
	rand();
	int randomNumber = rand() % 101;
	return randomNumber;
}

bool check(int hiddenNumber, int guessNumber) {
	if (hiddenNumber < guessNumber) {
		cout << "Your guess is too low." << endl;
		return false;
	}
	if (hiddenNumber > guessNumber) {
		cout << "Your guess is too high." << endl;
		return false;
	}
	if (hiddenNumber == guessNumber) {
		cout << "Correct! You win!" << endl;
		return true;
	}
}

void playAgain() {
	cout << "Would you like to play again (y/n)? ";
	char h; cin >> h;
	if (h == 'y') {
		play();
	}
	else if (h == 'n') {
		cout << "Thank you for playing." << endl;
	}
	else {
		cin.ignore(32767, '\n');
		cout << "Enter correct value!" << endl;
		playAgain();
	}
}

bool guesses(int attempts, int hiddenNumber) {
	int i = 1;
	while (attempts--) {
		cout << "Guess #" << i << ": ";
		int guessNumber = checkInput();
		if (check(hiddenNumber, guessNumber)) {
			return true;
		}
		i++;
	}
	return false;
}

int checkInput() {
	int value;
	cin >> value;
	cin.ignore(32767, '\n');
	if (cin.fail()) {
		cin.clear();
		cin.ignore(32767, '\n');
		cout << "Enter correct value!" << endl;
		checkInput();
	}
	else {
		return value;
	}
}

void play() {
	int hiddenNumber = Start();
	//cout << hiddenNumber << endl;
	int attempts = 7;
	if (!guesses(attempts, hiddenNumber)) {
		cout << "Sorry, you lose. The correct number was " << hiddenNumber << '.' << endl;
	}
	playAgain();
}
	
int main() {
	srand(time(nullptr));
	play();
}
