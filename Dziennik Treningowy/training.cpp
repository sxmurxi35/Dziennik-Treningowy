#include "training.h"
#include <cstdlib>
#include <cstring>

void Exercise::addSet(int repsInput, float weightInput) {
	Set* newSetsArray = (Set*)malloc((setsCount + 1) * sizeof(Set));

	if (newSetsArray != nullptr) {
		for (int i = 0; i < setsCount; i++) {
			newSetsArray[i] = setsArray[i];
		}

		newSetsArray[setsCount].reps = repsInput;
		newSetsArray[setsCount].weight = weightInput;
		newSetsArray[setsCount].setId = setsCount + 1;

		if (setsArray != nullptr) {
			free(setsArray);
		}

		setsArray = newSetsArray;
		setsCount++;
	}

}

void Training::addExercise(const char* exerciseNameInput) {
	Exercise* newExercisesArray = (Exercise*)calloc(exercisesCount + 1, sizeof(Exercise));

	if (newExercisesArray != nullptr) {
		for (int i = 0; i < exercisesCount; i++) {
			newExercisesArray[i] = exercisesArray[i];
		}

		strcpy(newExercisesArray[exercisesCount].exerciseName, exerciseNameInput);
		newExercisesArray[exercisesCount].exerciseId = exercisesCount + 1;

		if (exercisesArray != nullptr) {
			free(exercisesArray);
		}

		exercisesArray = newExercisesArray;
		exercisesCount++;
	}

}

void TrainingLog::addTraining(const char* trainingDateInput) {
	Training* newTrainingsArray = (Training*)calloc(trainingsCount + 1, sizeof(Training));

	if (newTrainingsArray != nullptr) {
		for (int i = 0; i < trainingsCount; i++) {
			newTrainingsArray[i] = trainingsArray[i];
		}

		strcpy(newTrainingsArray[trainingsCount].trainingDate, trainingDateInput);
		newTrainingsArray[trainingsCount].trainingId = trainingsCount + 1;

		if (trainingsArray != nullptr) {
			free(trainingsArray);
		}

		trainingsArray = newTrainingsArray;
		trainingsCount++;
	}
}

void Exercise::clearMemory() {
	if (setsArray != nullptr) {
		free(setsArray);
		setsCount = 0;
		setsArray = nullptr;
	}
}

void Training::clearMemory() {
	if (exercisesArray != nullptr) {
		for (int i = 0; i < exercisesCount; i++) {
			exercisesArray[i].clearMemory();
		}

		free(exercisesArray);
		exercisesCount = 0;
		exercisesArray = nullptr;
	}
}

void TrainingLog::clearMemory() {
	if (trainingsArray != nullptr) {
		for (int i = 0; i < trainingsCount; i++) {
			trainingsArray[i].clearMemory();
		}

		free(trainingsArray);
		trainingsCount = 0;
		trainingsArray = nullptr;
	}
}

float Training::calculateTrainingVolume() {
	float trainingVolume = 0.0;
	if (exercisesArray != nullptr) {

		for (int i = 0; i < exercisesCount; i++) {
			for (int j = 0; j < exercisesArray[i].setsCount; j++) {
				trainingVolume += (exercisesArray[i].setsArray[j].reps * exercisesArray[i].setsArray[j].weight);
			}
		}
	}
	return trainingVolume;
}

float TrainingLog::calculateVolumeOverall() {
	float trainingVolume = 0.0;

	if (trainingsArray != nullptr) {
		for (int i = 0; i < trainingsCount; i++) {
			trainingVolume += trainingsArray[i].calculateTrainingVolume();
		}
	}
	return trainingVolume;
}

float TrainingLog::calculateVolumeOverall(const char* monthYear) {
	float trainingVolume = 0.0;

	if (trainingsArray != nullptr && monthYear != nullptr) {
		for (int i = 0; i < trainingsCount; i++) {
			if (strstr(trainingsArray[i].trainingDate, monthYear) != nullptr) {
				trainingVolume += trainingsArray[i].calculateTrainingVolume();
			}
		}
	}

	return trainingVolume;
}