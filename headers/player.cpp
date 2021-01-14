#include<bits/stdc++.h>
#include "player.h"
using namespace std;


int Player:: getPoints() {
	return this->points;
}

void Player:: addPoints(int p) {
	this->points += p;
	this->resetPocketMissedCount();
	return;
}

void Player:: deductPoints(int p) {
	this->points -= p;
	this->foul();
	return;
}

void Player:: pocketMissed() {
	missedPocketCount++;
	if (missedPocketCount >= 3) {
		this->deductPoints(1);
		this->resetPocketMissedCount();
	}
}

void Player:: resetPocketMissedCount() {
	missedPocketCount = 0;
}

void Player:: foul() {
	foulCount++;
	if (foulCount >= 3) {
		this->deductPoints(1);
		this->resetFoulCount();
	}
}

void Player:: resetFoulCount() {
	foulCount = 0;
}