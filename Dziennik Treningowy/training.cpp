#include "training.h"
#include <cstdlib>
#include <cstring>

void Exercise::addSet(int repsInput, float weightInput){
	Set* newSetsArray = (Set*)malloc((setsCount + 1) * sizeof(Set));

	if (newSetsArray != nullptr){
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

void Training::addExercise(const char* exerciseNameInput){
	Exercise* newExercisesArray = (Exercise*)calloc(exercisesCount + 1, sizeof(Exercise));

	if (newExercisesArray != nullptr){
		for (int i = 0; i < exercisesCount; i++) {
			newExercisesArray[i] = exercisesArray[i];
		}

		strcpy(newExercisesArray[exercisesCount].exerciseName, exerciseNameInput);

		if (exercisesArray != nullptr) {
			free(exercisesArray);
		}

		exercisesArray = newExercisesArray;
		exercisesCount++;
	}

}