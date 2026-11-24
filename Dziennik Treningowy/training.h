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

	void clearMemory();
};

class Training
{
public:
	int trainingId;
	char trainingDate[11];
	int exercisesCount;
	Exercise* exercisesArray;

	void addExercise(const char* exerciseName);

	void clearMemory();

	float calculateTrainingVolume();
};

class TrainingLog {
public:
	int trainingsCount;
	Training* trainingsArray;

	void addTraining(const char* trainingDate);
	
	void clearMemory();

	float calculateVolumeOverall();
	float calculateVolumeOverall(const char* monthYear);

	Training* findTraining(int trainingId);
	Training* findTraining(const char* trainingDate);
};