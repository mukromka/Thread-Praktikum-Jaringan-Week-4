class Player {
private:
	enum Players : char
	{
		PlayerX,
		PlayerY
	} currentPlayer;
	float hits;
public:  
	Player(char cek); //constructor
	Player(Player& clone); //cloning class
	void SetHits(float hits);//setter
	float GetHits();//getter
	char randomPlayer();//random player x or y

	Players GetPlayers() 
	{
		return currentPlayer;
	}

};

char Player::randomPlayer() //random a number, if the value is 0, return 'X', else return 'Y'
{
	int random;
	int* i = new int;
	srand((int)i);
	delete i;
	random = rand() % 2;
	if (random == 0)
		return 'X';
	else
		return 'Y';
}

Player :: Player(char check) {
	hits = 0;
	switch (check)
	{
		case 'X': currentPlayer = Players::PlayerX;
			break;
		default : currentPlayer = Players::PlayerY;
			break;
	}
}

Player :: Player(Player& clone) 
{
	hits = clone.hits;
	switch (clone.currentPlayer)
	{
		case Players::PlayerX : currentPlayer = Players::PlayerY;
			break;
		default: currentPlayer = Players::PlayerX;
			break;
	}
}

void Player::SetHits(float hits) {
	this->hits = hits;
}

float Player:: GetHits() {
	return hits;
}