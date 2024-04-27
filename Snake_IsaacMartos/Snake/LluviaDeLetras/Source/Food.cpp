#include "Food.h"
#include "ScoreManager.h"
#include "Snake.h"

void Food::FoodRespawn(int screenWidth, int screenHeight)
{
	x = 2 + (std::rand() % (screenWidth - 2));
	y = 4 + (std::rand() % (screenHeight - 1));

	foodList.push_back({x, y});
}

void Food::OnTouch()
{
	for (size_t i = 0; i < foodList.size(); i++)
	{
		int comidaX = foodList[i].first;
		int comidaY = foodList[i].second;

		// Coordenadas de la cabeza de la serpiente
		int cabezaX = serpiente->GetBody()[0].x;
		int cabezaY = serpiente->GetBody()[0].y;

		// Comparar coordenadas
		if (comidaX == cabezaX && comidaY == cabezaY) {
			// La comida ha sido tocada por la serpiente
			ScoreManager::GetInstance()->AddPoints(1); 
			foodList.erase(foodList.begin() + i);
			serpiente->Grow();
		}
	}
}

std::vector<std::pair<int, int>> Food::GetFoodList()
{
	return foodList;
}

void Food::ResetFoodList()
{
	foodList.clear();
}
