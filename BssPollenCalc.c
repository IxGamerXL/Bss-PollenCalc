#include <stdio.h>
#include <windows.h>

float getInput(char inputMessage[], char errorMessage[]) {
	// Init vars
	char line[4096];
	char* inp;
	float result = 0;
	int n = 0;

	// Query
	while (n==0 || result==0) {
		printf("%s\n> ", inputMessage);
		inp = fgets(line, sizeof(line), stdin);
		n = sscanf(inp, "%f", &result);
		if (n==0 || result==0) {
			printf("%s\n", errorMessage);
		}
	}

	return result;
}

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

	return result;
}

int cycle() {
	// Initialize variables
	float pollenPerTile = 0;
	float tileCount = 0;
	float useDelay = 0;

	float totalPollen;
	float pollenPerSecond;
	
	char response;

	// Question the user
	printf("\n\n");
	pollenPerTile = getInput("How much pollen does this tool collect (per tile)?", "Invalid float!");
	printf("\n");
	tileCount = getInput("How many tiles does this tool collect from?", "Invalid float!");
	printf("\n");
	useDelay = getInput("How long does it take for the tool to be used a second time?", "Invalid float!");

	// Do some calculating magic
	totalPollen = pollenPerTile * tileCount;
	pollenPerSecond = totalPollen / useDelay;

	printf("\n\n\nInputted variables:\n\n");
	printf("Pollen per tile: %0.2f\n", pollenPerTile);
	printf("Tiles per use: %0.2f\n", tileCount);
	printf("Used every: %0.2fs\n", useDelay);
	printf("\nMath:\n\n");
	printf("%0.2f * %0.2f = Pollen/harvest (%0.2f)\n", pollenPerTile, tileCount, totalPollen);
	printf("%0.2f / %0.2f = Pollen/second (%0.2f)\n", totalPollen, useDelay, pollenPerSecond);
	printf("\nCalculated results:\n\n");
	printf("Pollen/harvest: %0.2f\n", totalPollen);
	printf("Pollen/second: %0.2f\n\n", pollenPerSecond);
	while (1==1) {
		response = getCharacterInput("Again? [y/n]", "INVALID RESPONSE!");
		if (response == 'y') {return 1;}
		else if (response == 'n') {return 0;}
		else {printf("INVALID RESPONSE!\n\n");}
	}
}

int main() {
	// Print welcome message
	printf("Welcome to the Bee Swarm Simulator Pollen Calculator!\n\n");
	printf("If you need to see how much pollen per second a tool makes,\n");
	printf("this is the program for you!\n\n");
	printf("If you input characters or commas (,), the program will crash.\n");
	printf("Please avoid doing so.\n");
	MessageBox(NULL, "Goodbye, cruel world!", "Note", MB_OK);

	// Go on a loop, and exit if the response from the user is to stop calculating.
	while (1==1) {
		if (cycle() == 0) {
			break;
		}
	}

	// Exit program
	return 0;
}