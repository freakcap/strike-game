#include<bits/stdc++.h>
using namespace std;

class Player {
private:
	int points, foulCount, missedPocketCount;

public:
	Player() {
		points = 0;
		foulCount = 0;
		missedPocketCount = 0;
	}

	int getPoints();
	void addPoints(int p);
	void deductPoints(int p);
	void pocketMissed();
	void resetPocketMissedCount();
	void foul();
	void resetFoulCount();

};