#include<bits/stdc++.h>
#include "headers/carrom.h"
using namespace std;

int main() {
	Carrom carrom;
	Player player1, player2;
	int choice, currPlayer(0);
	while (!carrom.isEmpty() && !carrom.isWon(player1, player2)) {
		cout << "\nPlayer " << ((currPlayer & 1) + 1) << "'s turn : Select from below\n";
		cout << "1. Strike\n";
		cout << "2. Multistrike\n";
		cout << "3. Red strike\n";
		cout << "4. Striker strike\n";
		cout << "5. Defunct coin\n";
		cout << "6. None\n";
		cout << "7. View Current Score\n";
		cout << "8. Quit Game\n";
		cin >> choice;
		switch (choice) {
		case 1:
		{
			if (currPlayer & 1) carrom.strike(player2);
			else carrom.strike(player1);
			break;
		}
		case 2:
		{
			if (currPlayer & 1) carrom.multiStrike(player2);
			else carrom.multiStrike(player1);
			break;
		}
		case 3:
		{
			if (currPlayer & 1) carrom.redStrike(player2);
			else carrom.redStrike(player1);
			break;
		}
		case 4:
		{
			if (currPlayer & 1) carrom.strikerStrike(player2);
			else carrom.strikerStrike(player1);
			break;
		}
		case 5:
		{
			if (currPlayer & 1) carrom.defunctCoin(player2);
			else carrom.defunctCoin(player1);
			break;
		}
		case 6:
		{
			if (currPlayer & 1) carrom.nothing(player2);
			else carrom.nothing(player1);
			break;
		}
		case 7:
		{
			cout << "\nCurrent Score :\n Player 1 : " << player1.getPoints() << "\n Player 2 : " << player2.getPoints() << endl;
			currPlayer--;
			break;
		}
		case 8:
		{
			cout << "QUITTING GAME ...\n";
			return 0;
		}
		default :
		{
			cout << "Wrong Choice. Try again !!\n";
			currPlayer--;
		}
		}
		currPlayer++;
	}
	carrom.printResult(player1, player2);
	cout << "\nTHANK YOU FOR PLAYING\n";
	return 0;
}