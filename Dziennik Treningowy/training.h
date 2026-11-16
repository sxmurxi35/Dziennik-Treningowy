#pragma once

struct Set
{
	int setId;
	int reps;
	float weight;
};

struct Exercise
{
	int exerciseId;
	char exerciseName[50];
	int setsCount;
	Set* setsArray;
};

class Training
{
	public:
		int trainingId;
		char trainingDate[11];
		int exercisesCount;
		Exercise* exercisesArray;
};