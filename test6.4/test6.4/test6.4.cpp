#include <iostream>
#include <array>
#include <ctime>
#include <cstdlib>

using namespace std;

enum Ranks {
	RANK_2,
	RANK_3,
	RANK_4,
	RANK_5,
	RANK_6,
	RANK_7,
	RANK_8,
	RANK_9,
	RANK_10,
	RANK_VALET,
	RANK_DAMA,
	RANK_KOROL,
	RANK_TYZ,
	MAX_RANK
};

enum Suits {
	SUIT_CHERVI,
	SUIT_BYBNA,
	SUIT_PIKA,
	SUIT_KRESTE,
	MAX_SUIT
};

struct CardDef {
	Suits suit;
	Ranks rank;
};

void printCard(const CardDef &cardDef) {
	switch (cardDef.rank) {
	case RANK_2:
		cout << "2";
		break;
	case RANK_3:
		cout << "3";
		break;
	case RANK_4:
		cout << "4";
		break;
	case RANK_5:
		cout << "5";
		break;
	case RANK_6:
		cout << "6";
		break;
	case RANK_7:
		cout << "7";
		break;
	case RANK_8:
		cout << "8";
		break;
	case RANK_9:
		cout << "9";
		break;
	case RANK_10:
		cout << "10";
		break;
	case RANK_VALET:
		cout << "V";
		break;
	case RANK_DAMA:
		cout << "D";
		break;
	case RANK_KOROL:
		cout << "K";
		break;
	case RANK_TYZ:
		cout << "T";
		break;
	}
	switch (cardDef.suit) {
	case SUIT_PIKA:
		cout << "P";
		break;
	case SUIT_KRESTE:
		cout << "K";
		break;
	case SUIT_BYBNA:
		cout << "B";
		break;
	case SUIT_CHERVI:
		cout << "C";
		break;
	}
}

void swapCards(CardDef &a, CardDef &b) {
	CardDef c = a;
	a = b;
	b = c;
}

int getRandomNumber(int min, int max) {
	static const double fraction = 1.0 / (static_cast <double> (RAND_MAX) + 1.0);
	return static_cast <int> (rand() * fraction * (max - min + 1) + min);
}

void shuffleDeck(array <CardDef, 52> &deck) {
	for (int i = 0; i < 52; i++) {
		int j = getRandomNumber(0, 51);
		swapCards(deck[i], deck[j]);
	}
}

void fillingDeck(array <CardDef, 52>& deck) {
	int pos = 0;
	for (int i = 0; i < MAX_RANK; i++) {
		for (int j = 0; j < MAX_SUIT; j++) {
			deck[pos].suit = static_cast <Suits> (j);
			deck[pos].rank = static_cast <Ranks> (i);
			pos++;
		}
	}
}

int getCardValue(const CardDef& cardDef) {
	switch (cardDef.rank) {
	case RANK_2:
		return 2;
		break;
	case RANK_3:
		return 3;
		break;
	case RANK_4:
		return 4;
		break;
	case RANK_5:
		return 5;
		break;
	case RANK_6:
		return 6;
		break;
	case RANK_7:
		return 7;
		break;
	case RANK_8:
		return 8;
		break;
	case RANK_9:
		return 9;
		break;
	case RANK_10:
		return 10;
		break;
	case RANK_VALET:
		return 10;
		break;
	case RANK_DAMA:
		return 10;
		break;
	case RANK_KOROL:
		return 10;
		break;
	case RANK_TYZ:
		return 1;
		break;
	}
}

void playBlackJeck(array <CardDef, 52>& deck) {
	/*for (int i = 0; i < 52; i++) {
		printCard(deck[i]);
		cout << endl;
	}*/
	int playersScore = 0, dealersScore = 0;
	cout << "Dealers card: ";
	printCard(deck[0]);
	dealersScore += getCardValue(deck[0]);
	if (deck[0].rank == RANK_TYZ && dealersScore < 11) {
		dealersScore += 10;
	}
	cout << endl << "Your cards: ";
	printCard(deck[1]);
	cout << ' ';
	printCard(deck[2]);
	playersScore += getCardValue(deck[1]);
	if (deck[1].rank == RANK_TYZ && playersScore < 11) {
		playersScore += 10;
	}
	playersScore += getCardValue(deck[2]);
	if (deck[2].rank == RANK_TYZ && playersScore < 11) {
		playersScore += 10;
	}
	cout << endl;
	int pos = 3;
	while (playersScore <= 21) {
		cout << "Your score: " << playersScore << endl;
		cout << "hit/stand" << endl;
		string requaest; cin >> requaest;
		if (requaest == "stand") {
			break;
		}
		printCard(deck[pos]);
		cout << endl;
		playersScore += getCardValue(deck[pos]);
		if (deck[pos].rank == RANK_TYZ && playersScore < 11) {
			playersScore += 10;
		}
		pos++;
	}
	cout << "Your score: " << playersScore << endl;
	if (playersScore > 21) {
		cout << "You lose :(" << endl;
		return;
	}
	if (playersScore == 21) {
		cout << "BLACKJECK!!!" << endl;
	}
	while (dealersScore < 17) {
		cout << "dealers hit " << endl;
		printCard(deck[pos]);
		cout << endl;
		dealersScore += getCardValue(deck[pos]);
		if (deck[pos].rank == RANK_TYZ && dealersScore < 11) {
			dealersScore += 10;
		}
		pos++;	
	}
	cout << "Dealers score: " << dealersScore << endl;
	if (dealersScore > 21) {
		cout << "You win!" << endl;
		return;
	}
	if (dealersScore == 21) {
		cout << "BLACKJECK!!!" << endl;
	}
	if (dealersScore == playersScore) {
		cout << "Draw" << endl;
	}
	if (dealersScore < playersScore) {
		cout << "You win!" << endl;
	}
	if (dealersScore > playersScore) {
		cout << "You lose :(" << endl;
	}
}

void play() {
	array <CardDef, 52> deck;
	fillingDeck(deck);
	shuffleDeck(deck);
	playBlackJeck(deck);
	cout << "Play again?" << endl << "y/n" << endl;
	char again;
	cin >> again;
	if (again == 'y') {
		play();
	}
}

int main() {
	srand(time(nullptr));
	rand();
	play();
}