#include <iostream>

#include "ScoreManager.h"
#include "SnakeEngine.h"
#include "Windows.h"

int main()
{	
	SnakeEngine *engine = new SnakeEngine(60, 27, 1.0f);
	
	bool executeLoop = true;
	while (executeLoop)
	{
		engine->updateEngine();

		if (GetKeyState(VK_ESCAPE) & 0x8000)
			executeLoop = false;

		if (engine->GetGameOverState())
		{
			ScoreManager::GetInstance()->SetNewRecord(ScoreManager::GetInstance()->GetPoints());
			std::cout << "Game Over! Presiona la tecla Enter para volver a empezar...";
			while (!(GetAsyncKeyState(VK_RETURN) & 0x8000))
			{
				Sleep(100);
			}
			engine->Restart();
		}
	}

	delete engine;
}




