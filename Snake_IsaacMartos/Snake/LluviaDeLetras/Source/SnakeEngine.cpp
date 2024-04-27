#include "SnakeEngine.h"
#include "Helpers.h"
#include "ScoreManager.h"
#include <iostream>
#include <string>

void SnakeEngine::update()
{
	DEBUG_LOG("UPDATE");

	body = serpiente.GetBody();
	prevLastSegmentX = body.back().x;
	prevLastSegmentY = body.back().y;

	serpiente.Move();
	if (serpiente.IsSnakeCollisioned()) isGameOver = true;

	comida.OnTouch();	
	comida.FoodRespawn(drawEngine->boardSizeX - 2, drawEngine->boardSizeY - 5);	
}

void SnakeEngine::draw()
{
	drawEngine->ClearScreen();
	
	DrawBoard(); //Fill the matrix with the board
	DrawScore(); //Fill the matrix with the score
	DrawAnimatedElements(); //Fill the matrix with the animated elements

	drawEngine->DrawMatrix();
}

void SnakeEngine::DrawBoard()
{
	drawEngine->DrawAtPos(201,0); // '╔';
	drawEngine->DrawAtPos(187, drawEngine->boardSizeX - 2, 0);//'╗';
	drawEngine->DrawAtPos(200, 0, drawEngine->boardSizeY - 1);//'╚';
	drawEngine->DrawAtPos(188, drawEngine->boardSizeX - 2, drawEngine->boardSizeY - 1);//'╝';

	drawEngine->DrawRow(205, 0, drawEngine->boardSizeX - 1);
	drawEngine->DrawRow(205, 2, drawEngine->boardSizeX - 1);
	drawEngine->DrawRow(205, 3, drawEngine->boardSizeX - 1);
	drawEngine->DrawRow(205, drawEngine->boardSizeY - 1, drawEngine->boardSizeX - 1);
	drawEngine->DrawColumn(186, drawEngine->boardSizeY, 0);
	drawEngine->DrawColumn(186, drawEngine->boardSizeY, drawEngine->boardSizeX - 2);

	drawEngine->DrawAtPos(185, drawEngine->boardSizeX - 2,2);
	drawEngine->DrawAtPos(185, drawEngine->boardSizeX - 2,3);
	drawEngine->DrawAtPos(204, 0, 2);
	drawEngine->DrawAtPos(204, 0, 3);

	drawEngine->DrawAtPos("PUNTUACION:", 1, 4);
	drawEngine->DrawAtPos("RECORD:", 1, drawEngine->boardSizeX - 16);

}

void SnakeEngine::DrawScore()
{
	char scoreChars[10]; 
	char recordChars[10];

	_itoa_s(ScoreManager::GetInstance()->GetPoints(), scoreChars, 10); //http://www.cplusplus.com/reference/cstdlib/itoa/
	_itoa_s(ScoreManager::GetInstance()->GetRecord(), recordChars, 10);

	for (int i = 0; i < 10; i++)
	{
		if (scoreChars[i] > 0)
			drawEngine->DrawAtPos(scoreChars[i], 15 + i, 1);
		if (recordChars[i] > 0)
			drawEngine->DrawAtPos(recordChars[i], drawEngine->boardSizeX - 9 + i, 1);
	}
}

void SnakeEngine::DrawAnimatedElements()
{
	for (const auto& segment : body) {
		drawEngine->DrawAtPos(219, segment.x, segment.y);
	}

	drawEngine->DrawAtPos(' ', prevLastSegmentX, prevLastSegmentY);

	drawEngine->DrawAtPos(comida.letraComida, comida.x, comida.y);
}

void SnakeEngine::Restart()
{
	isGameOver = false;

	int currentPoints = ScoreManager::GetInstance()->GetPoints();
	int currentRecord = ScoreManager::GetInstance()->GetRecord();

	if (currentPoints > currentRecord) {
		ScoreManager::GetInstance()->SetNewRecord(currentPoints);
	}
	ScoreManager::GetInstance()->SetPoints(0);

	drawEngine->ClearScreen();
	drawEngine->ResetMatrix(' ');
	comida.ResetFoodList();
	serpiente.RestartSnake();
}
