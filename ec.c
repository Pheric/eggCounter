#include <stdio.h>

// Define some ANSI color codes
static const char YELLOW[] = "\x1b[33m", \
	GREEN[] = "\x1b[32m", \
	CYAN[] = "\x1b[36m", \
	BOLD[] = "\x1b[1m", \
	RESET[] = "\x1b[0m";

// Make the program "logo"
static const char *eggsAscii = " ..   ..   ..   ..   ..   ..\n"
			".  . .  . .  . .  . .  . .  .\n"
			" ..   ..   ..   ..   ..   ..";

// Declare functions
static int getIntInput(char* prompt);

int main(void) {
  // Print some info and the "logo"
  printf("\nEggCounter -- 2018\n%s%s%s%s\n\n", YELLOW, BOLD, eggsAscii, 
RESET);

  // Provide some context for the user
  printf("%sHow many egg cartons would you like?\n", CYAN);

  int twelvePacks = getIntInput("Normal Cartons (12 eggs): ");
  int eighteenPacks = getIntInput("Large Cartons (18 eggs): ");
  int totalEggCount = twelvePacks * 12 + eighteenPacks * 18;

  printf("%s\n\tYour Order\n", RESET);
  printf("--------------------------\n");
  printf("12 Packs: %d (%d eggs)\n", twelvePacks, twelvePacks * 12);
  printf("18 Packs: %d (%d eggs)\n", eighteenPacks, eighteenPacks * 18);
  printf("   Total: %s%d eggs%s\n", GREEN, totalEggCount, RESET);

  // I had planned to grab the current egg price from some kind of grocery api,
  // but a lot of them charge obscene prices or require a lot of work signing
  // up and messing with settings. So I'll just look up the price on Amazon
  // real quick and hard code it.
  float eggPrice = 2.67; // Derived from the price of a dozen on Amazon

  printf("--------------------------\n");
  printf("Total Price (excl. tax): %s$%.2f%s ($%.2f / egg)\n\n", 
GREEN, totalEggCount * eggPrice, RESET, 
eggPrice);
}

// Gets an integer entered in stdin
// prompt: text displayed before the input is to be entered
// Returns the integer entered
static int getIntInput(char* prompt) {
  // Print the prompt
  printf("%s", prompt);

  int ret = 0;
  // Wait for an integer
  scanf("%d", &ret);
  // If an invalid character is entered, it will be ignored (by scanf()).
  // We need to get rid of it and move on.
  while(getchar() != '\n');

  return ret;
}
