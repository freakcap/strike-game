#include<bits/stdc++.h>
#include "carrom.h"
using namespace std;

bool Carrom ::  isEmpty() {
	return coins == 0 && red == 0;
}

void Carrom ::  strike(Player& p) {
	if (this->isEmpty() || (this->coins == 0 && this->red != 0)) {
		cout << "Wrong Move\n";
		return;
	}
	coins--;
	p.addPoints(1);
}

void Carrom ::  multiStrike(Player& p) {
	if (this->isEmpty() || (this->coins == 0 && this->red != 0)) {
		cout << "Wrong Move\n";
		return;
	}
	coins -= 2;
	p.addPoints(2);
}

void Carrom ::  redStrike(Player& p) {
	if (this->isEmpty() || this->red == 0) {
		cout << "Wrong Move\n";
		return;
	}
	red = 0;
	p.addPoints(3);
}

void Carrom ::  strikerStrike(Player& p) {
	p.pocketMissed();
	p.deductPoints(1);
}

void Carrom ::  defunctCoin(Player& p) {
	if (this->isEmpty()) {
		cout << "Wrong Move\n";
		return;
	}
	p.pocketMissed();
	if (this->coins == 0 && this->red != 0) {
		red = 0;
		p.deductPoints(2);
	}
	else {
		coins--;
		p.deductPoints(2);
	}
}

void Carrom ::  nothing(Player& p) {
	p.pocketMissed();
}

bool Carrom ::  isWon(Player& p1, Player& p2) {
	int diff = abs(p1.getPoints() - p2.getPoints());
	int lead = max(p1.getPoints(), p2.getPoints());
	return diff >= 3 && lead >= 5;
}

void Carrom ::  printResult(Player& p1, Player& p2) {
	int diff = abs(p1.getPoints() - p2.getPoints());
	int lead = max(p1.getPoints(), p2.getPoints());
	if (diff < 3 || lead < 5) {
		cout << "** THE GAME IS DRAW !! **\n";
		return;
	}
	else {
		string winner =  p1.getPoints() == lead ? "1" : "2" ;
		cout << "** THE GAME IS WON BY PLAYER " << winner << " **\n";
		cout << "Final Score :\n Player 1 : " << p1.getPoints() << "\n Player 2 : " << p2.getPoints() << endl;
		return;
	}
}