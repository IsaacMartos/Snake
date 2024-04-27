#include "ScoreManager.h"

ScoreManager* ScoreManager::instance = nullptr;

ScoreManager* ScoreManager::GetInstance() {
    if (instance == nullptr) {
        instance = new ScoreManager();
    }
    return instance;
}

int ScoreManager::AddPoints(int pointsToAdd)
{
    punctuation += pointsToAdd;
    return  punctuation;
}

int ScoreManager::SubstractPoints(int pointsToSubstract)
{
    punctuation -= pointsToSubstract;
    return  punctuation;
}

int ScoreManager::SetNewRecord(int newRecord)
{
	if (punctuation >= record)
	{
        record = punctuation;
	}
	else if (newRecord > record)
	{
        record = newRecord;
	}
    return record;
}

int ScoreManager::SetPoints(int points)
{
    punctuation = points;
    return points;
}

int ScoreManager::GetPoints()
{
    return punctuation;
}

int ScoreManager::GetRecord()
{
    return record;
}
