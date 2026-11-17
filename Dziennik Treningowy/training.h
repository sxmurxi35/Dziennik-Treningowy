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

	void addSet(int reps, float weight);
};

class Training
{
	public:
		int trainingId;
		char trainingDate[11];
		int exercisesCount;
		Exercise* exercisesArray;

		void addExercise(const char* exerciseName);
};

class TrainingLog {
	public:
		int trainingCount;
		Training* trainingArray;

		void addTraining(const char* trainingDate);
};