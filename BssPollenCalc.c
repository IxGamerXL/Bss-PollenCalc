#include <stdio.h>

// Get user input in the form of a float
float getFloatInput(char inputMessage[], char errorMessage[], float defaultValue) {
	// Init vars
	char line[4096];
	char* inp;
	float result = defaultValue;
	int n = 0;

	// Query
	while (n==0 || (result==defaultValue && defaultValue<0)) {
		printf("%s\n> ", inputMessage);
		inp = fgets(line, sizeof(line), stdin);
		n = sscanf(inp, "%f", &result);
		if (n==0 || (result==defaultValue && defaultValue<0)) {
			printf("%s\n", errorMessage);
		}
	}

	// Give result
	return result;
}

// Get user input in the form of an integer
int getIntInput(char inputMessage[], char errorMessage[], int defaultValue) {
	// Init vars
	char line[4096];
	char* inp;
	int result = defaultValue;
	int n = 0;

	// Query
	while (n==0 || (result==defaultValue && defaultValue<0)) {
		printf("%s\n> ", inputMessage);
		inp = fgets(line, sizeof(line), stdin);
		n = sscanf(inp, "%d", &result);
		if (n==0 || (result==defaultValue && defaultValue<0)) {
			printf("%s\n", errorMessage);
		}
	}

	// Give result
	return result;
}

// Get user input in the form of a character
char getCharacterInput(char inputMessage[], char errorMessage[]) {
	// Init vars
	char line[4096];
	char* inp;
	char result;
	int n = 0;

	// Query
	while (n==0) {
		printf("%s\n> ", inputMessage);
		inp = fgets(line, sizeof(line), stdin);
		n = sscanf(inp, "%c", &result);
		if (n==0) {
			printf("%s\n", errorMessage);
		}
	}

	// Give result
	return result;
}

int cycle() {
	printf("\n\n=====\n");

	// Initialize variables
	float pollenPerTile;
	int tileCount;
	int lines;
	float useDelay;

	int totalTiles;
	float totalPollen;
	float pollenPerSecond;
	
	char response;

	// Question the user
	printf("\n\n");
	pollenPerTile = getFloatInput(
		"How much pollen does this tool collect (per tile)?",
		"Invalid value!",
		-1.0f
	);
	printf("\n");
	tileCount = getIntInput(
		"How many patches does this tool collect from?",
		"Invalid value!",
		-1
	);
	printf("\n");
	lines = getIntInput(
		"How many lines of patches? (optional)",
		"Invalid value!",
		1
	);
	printf("\n");
	useDelay = getFloatInput(
		"How long does it take for the tool to be used a second time?",
		"Invalid value!",
		-1.0f
	);

	// Do some calculating magic
	totalTiles = tileCount * lines;
	totalPollen = pollenPerTile * totalTiles;
	pollenPerSecond = totalPollen / useDelay;

	// Print the results
	printf("\n\n\nInputted variables:\n\n");
	printf("Pollen per patch: %0.2f\n", pollenPerTile);
	printf("Patches: %d\n", tileCount);
	if (lines != 1) printf("Lines: %d\n", lines);
	printf("Used every: %0.2fs\n", useDelay);

	printf("\nMath:\n\n");
	if (lines != 1) printf("%d * %d = Total patches (%d)\n", tileCount, lines, totalTiles);
	printf("%0.2f * %d = Pollen per use (%0.2f)\n", pollenPerTile, totalTiles, totalPollen);
	printf("%0.2f / %0.2f = Pollen per second (%0.2f)\n", totalPollen, useDelay, pollenPerSecond);

	printf("\nCalculated results:\n\n");
	if (lines != 1) printf("Total patches: %d\n", totalTiles);
	printf("Pollen per use: %0.2f\n", totalPollen);
	printf("Pollen per second: %0.2f\n\n", pollenPerSecond);
	while (1==1) {
		response = getCharacterInput("Do another calculation? [y: Retry | n: Exit]", "Invalid response! Correct responses: [y, n]");
		if (response == 'y') {return 1;}
		else if (response == 'n') {return 0;}
		else {printf("Invalid response! Correct responses: [y, n]\n\n");}
	}
}

// Main thread
int main() {
	// Print welcome message
	printf("Welcome to the Bee Swarm Simulator Pollen Calculator!\n\n");
	printf("If you need to see how much pollen total a tool makes,\n");
	printf("this is the program for you!\n");

	// Go on a loop, and exit if the response from the user is to stop calculating.
	while (1==1) {
		if (cycle() == 0) {
			break;
		}
	}

	// Exit program
	return 0;
}