#include<bits/stdc++.h>
#include "player.h"
using namespace std;

class Carrom {
private:
	int coins, red;

public:
	Carrom() {
		coins = 9;
		red = 1;
	}

	bool isEmpty();
	void strike(Player& p);
	void multiStrike(Player& p);
	void redStrike(Player& p);
	void strikerStrike(Player& p);
	void defunctCoin(Player& p);
	void nothing(Player& p);
	bool isWon(Player& p1, Player& p2);
	void printResult(Player& p1, Player& p2);
};