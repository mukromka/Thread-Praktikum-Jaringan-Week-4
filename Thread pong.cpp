#include <iostream>
#include <mutex> // using mutex to lock global variable
#include <thread> // thread
#include <stdlib.h> // srand
#include <time.h> // randomize
#include "scoring.h" // Score class
#include "Players.h" // Player class

using namespace std;

Score score(0, 0);

mutex m;//lock global var

void PlayerHit(Player* player, bool* isHit) 
{
	//generate random number 0 to 100
	m.lock();
	int* random = new int;
	srand((int)random);
	delete random;
	player->SetHits(rand() % 100);
	m.unlock();

	//show current player
	if (player->GetPlayers() == 0) 
		cout << " Player X ";
	else 
		cout << " Player Y ";
	cout << "Hit : " << player->GetHits() << " ";

	//check current player hit
	if (player->GetHits() <= 50) 
	{
		// Update score + 1 to opponent score
		if (player->GetPlayers() == 0)
			score.setScore(0,1);
		else 
			score.setScore(1,0);
		cout << " \nHit!" << endl;
		*isHit = true;
	}
	else {
		cout << " Repeat" << endl; //if player didn't hit, then repeat
	}
	//delay thread
	this_thread::sleep_for(chrono::seconds(1));
}

int main()
{
	//generate random
	srand(time(0));
	//create player instance once
	Player playerX('X');
	//clone previous player to new player (Deep Copy)
	Player playerY = playerX;
startOver :
	system("cls");
	score.resetScore();
	//simulation flow (Main Loop)
	while (score.xScore() < 10 && score.yScore() < 10) {
		// Start from random player, player X or player Y
		bool isHit = false;
		while (isHit == false) {
			if (playerX.randomPlayer() == 'X') 
			{
				cout << "Start from player X : " << endl;
			startAgain :
				//player x Thread 
				if (isHit == false)
				{
					thread playerXThread(PlayerHit, &playerX, &isHit);
					playerXThread.join();
				}

				// Player Y Thread
				if (isHit == false)
				{
					thread playerYThread(PlayerHit, &playerY, &isHit);
					playerYThread.join();
				}

				if (isHit == true) 
					break;
				else
					goto startAgain;

			}
			else
			{
				cout << "Start from player Y : " << endl;
			startAgain2 :
				// Player Y Thread
				if (isHit == false)
				{
					thread playerYThread(PlayerHit, &playerY, &isHit);
					playerYThread.join();
				}

				// Player X Thread
				if (isHit == false)
				{
					thread playerXThread(PlayerHit, &playerX, &isHit);
					playerXThread.join();

				}

				if (isHit == true)
					break;
				else
					goto startAgain2;
			}
		}
	}

	//show winner
	if (score.xScore() >= 10) {
		cout << "\nPlayer X win  " << score.xScore() << " - " << score.yScore();
	}
	else {
		cout << "\nPlayer Y win  " << score.yScore() << " - " << score.xScore();
	}
	char repeat;
	cout << "\nAgain ? Y/N " << endl;
	cin >> repeat;
	switch (repeat)
	{
	case 'Y': goto startOver;
		break;
	case 'y': goto startOver;
		break;
	default: return 0;
		break;
	}
}