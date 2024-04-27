#include "Snake.h"
#include "SnakeEngine.h"
#include "Windows.h"

void Snake::Move()
{
	if (GetKeyState(VK_UP) & 0x8000) inputDirection = Direction::Up;
	else if (GetKeyState(VK_DOWN) & 0x8000) inputDirection= Direction::Down;
	else if (GetKeyState(VK_RIGHT) & 0x8000) inputDirection = Direction::Right;
	else if (GetKeyState(VK_LEFT) & 0x8000) inputDirection = Direction::Left;

	switch (inputDirection) //Esto para no poder autocomerse
	{
	case Direction::Up:
		if (currentDirection != Direction::Down) currentDirection = Direction::Up;
		break;
	case Direction::Down:
		if (currentDirection != Direction::Up) currentDirection = Direction::Down;
		break;
	case Direction::Right:
		if (currentDirection != Direction::Left) currentDirection = Direction::Right;
		break;
	case Direction::Left:
		if (currentDirection != Direction::Right) currentDirection = Direction::Left;
		break;
	default:
		currentDirection = Direction::Right;
		break;
	}

	switch (currentDirection) //Switch para moverse
	{
	case Direction::Up:
		_headY--;
		break;
	case Direction::Down:
		_headY++;
		break;
	case Direction::Right:
		_headX++;
		break;
	case Direction::Left:
		_headX--;
		break;
	default:
		Direction::Right;
		break;
	}

	body.insert(body.begin(), { _headX, _headY });
	body.pop_back(); 
}

bool Snake::IsSnakeCollisioned()
{
	for (size_t i = 1; i < body.size(); ++i) {
		if (body.size() > 1) //Si la cabeza toca con el cuerpo
		{
			if (body[i].x == body[0].x && body[i].y == body[0].y) return true;
		}
		if (body[0].x <= 0 || body[0].y <= 3 || 
			body[0].x >= 59 || 
			body[0].y >= 26) //Si la cabeza toca con los bordes, revisar luego para pasar el screenWidth y Height
		{
			return true;
		}
	}
	return false;
}

void Snake::Grow()
{
	int newSegmentX = body.back().x;
	int newSegmentY = body.back().y;

	switch (currentDirection) {
	case Direction::Up:
		newSegmentY++; // Colocar el nuevo segmento debajo del último segmento
		break;
	case Direction::Down:
		newSegmentY--; // Colocar el nuevo segmento encima del último segmento
		break;
	case Direction::Left:
		newSegmentX++; // Colocar el nuevo segmento a la derecha del último segmento
		break;
	case Direction::Right:
		newSegmentX--; // Colocar el nuevo segmento a la izquierda del último segmento
		break;
	}

	if (newSegmentX != _headX || newSegmentY != _headY) {
		body.emplace_back(newSegmentX, newSegmentY);
	}
}

int Snake::GetDirection()
{
	switch (currentDirection) {
	case Direction::Up:
		return 0;
	case Direction::Down:
		return 1;
	case Direction::Left:
		return 2;
	case Direction::Right:
		return 3;
	}

	return -1; 
}

void Snake::RestartSnake()
{
	currentDirection = Direction::Right;
	inputDirection = currentDirection;

	_headX = _initialXPos;
	_headY = _initialYPos;

	body.clear();

	body.emplace_back( (_headX), (_headY));

	for (size_t i = 0; i < 4; i++)
	{
		body.emplace_back(_headX  - i - 1, _headY);
	}
}
