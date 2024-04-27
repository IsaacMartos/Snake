#pragma once
class ScoreManager
{
	static ScoreManager* instance;
public:
	ScoreManager()
	{
		instance = this;
	}

	int punctuation = 0;
	int record = 0;

	static ScoreManager* GetInstance();
	int AddPoints(int pointsToAdd);
	int SubstractPoints(int pointsToSubstract);
	int SetNewRecord(int newRecord);
	int SetPoints(int points);
	int GetPoints();
	int GetRecord();
};

