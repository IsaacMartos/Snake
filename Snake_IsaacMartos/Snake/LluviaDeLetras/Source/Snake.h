#pragma once
#include <vector>
#include <iostream>
#include "DrawEngine.h"

enum class Direction {
	Up,
	Down,
	Right,
	Left
};

struct SnakeSegment //Cada segmento de la serpiente
{
	int x;
	int y;

	SnakeSegment(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}
};

class Snake
{
	std::vector<SnakeSegment> body; //Cuerpo formado por segmentos
	Direction currentDirection;
	Direction inputDirection;
	int _initialXPos, _initialYPos; //Para guardar posicion inicial

public:
	int _headX, _headY;

	Snake(int startWidthPos, int startHeightPos): currentDirection(Direction::Right), inputDirection(Direction::Right), _initialXPos(startWidthPos),
	                                              _initialYPos(startHeightPos), _headX(startWidthPos),
	                                              _headY(startHeightPos)
	{
		SnakeSegment segment{startWidthPos, startHeightPos};
		segment.x = startWidthPos;
		segment.y = startHeightPos;

		currentDirection = Direction::Right;
		inputDirection = currentDirection;
	};

	void Move();
	bool IsSnakeCollisioned();
	void Grow();
	const std::vector<SnakeSegment>& GetBody() const {
		return body;
	}
	int GetDirection();
	void RestartSnake(); 

};

