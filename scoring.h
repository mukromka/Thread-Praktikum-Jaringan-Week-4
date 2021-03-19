class Score {
private:
	int PlayerXScore;
	int PlayerYScore;
public:
	Score(int x, int y);//constructor
	int xScore();//getter x
	int yScore();//getter y
	void setScore(int x, int y);//setter
	void resetScore();
};

void Score::resetScore()
{
	PlayerXScore = 0;
	PlayerYScore = 0;
}

Score::Score(int x, int y) 
{
	PlayerXScore = x;
	PlayerYScore = y;
}
void Score::setScore(int x, int y)
{
	PlayerXScore += x;
	PlayerYScore += y;
}
int Score:: xScore() 
{
	return PlayerXScore;
}
int Score::yScore() 
{
	return PlayerYScore;
}