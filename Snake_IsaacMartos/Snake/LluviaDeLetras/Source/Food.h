#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>
#include "Snake.h"

class Food
{
	std::vector<std::pair<int, int>> foodList;
	Snake* serpiente;

public:
	int x = 0, y = 0;
	char letraComida;

	Food(char comida, Snake* serpientePtr) : letraComida(comida), serpiente(serpientePtr) {
		std::srand(static_cast<unsigned>(std::time(nullptr)));
	}

	void FoodRespawn(int x, int y);
	void OnTouch();
	std::vector<std::pair<int, int>> GetFoodList();
	void ResetFoodList();
};

