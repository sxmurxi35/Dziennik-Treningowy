#include "training.h"
#include <cstdlib>

void Exercise::addSet(int reps, float weight){
	Set* newSetsArray = (Set*)malloc((setsCount + 1) * sizeof(Set));

	for (int i = 0; i < setsCount; i++) {
		newSetsArray[i] = setsArray[i];
	}

	newSetsArray[setsCount].reps = reps;
	newSetsArray[setsCount].weight = weight;
	newSetsArray[setsCount].setId = setsCount + 1;

	if (setsArray != nullptr) {
		free(setsArray);
	}

	setsArray = newSetsArray;
	setsCount++;
}