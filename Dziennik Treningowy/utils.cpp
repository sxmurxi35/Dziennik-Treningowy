#include "utils.h"
#include <cstdlib>
#include <iostream>

const char* randomExercise() {
	static const char* exercise[10] = { "Bench Press", "Overhead Press", "Bicep Curl", "Tricep Pushdown", "Leg Extension", "Deadlift", "Squat", "Lat Pulldown", "Bent Over Row", "Dumbbell Fly"};

	int randomNumber = rand() % 10;

	return exercise[randomNumber];
}