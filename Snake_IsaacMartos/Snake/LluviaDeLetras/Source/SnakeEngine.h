#pragma once
#include "GameEngine.h"
#include "Snake.h"
#include "Food.h"

class SnakeEngine : public GameEngine
{
	int currentScore;
	int record;
	Snake serpiente;
	Food comida;
	int prevLastSegmentX;
	int prevLastSegmentY;
	std::vector<SnakeSegment> body;

	bool isGameOver;
	int screenWidth;
	int screenHeight;

public:

	SnakeEngine(int _boardSizeX, int _boardSizeY, int _timePerFrame)
		: GameEngine(_boardSizeX, _boardSizeY, _timePerFrame), serpiente(_boardSizeX / 2, _boardSizeY / 2),
		comida('@', &serpiente), screenWidth(_boardSizeX), screenHeight(_boardSizeY)
	{
		Restart();
	}

	~SnakeEngine()
	{}

	void draw() override;
	void update() override;

	void DrawBoard();
	void DrawScore();
	void DrawAnimatedElements();

	int GetScreenWidth() { return screenWidth; }
	int GetScreenHeight() { return screenHeight;}
	bool GetGameOverState() { return isGameOver; }

	void Restart();
};

