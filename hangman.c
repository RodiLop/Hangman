#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void gameStart(int numLetters, char* word);

int main(void)
{
	int numLetters;
	char buffer[500];

	// intro
	printf("*   *  *****  *     *  *****  *           *  *****  *     *  **\n");
	printf("*   *  *   *  **    *  *      **         **  *   *  **    *  **\n");
	printf("*   *  *   *  * *   *  *      * *       * *  *   *  * *   *  **\n");
	printf("*****  *****  *  *  *  *      *  *     *  *  *****  *  *  *  **\n");
	printf("*   *  *   *  *   * *  *  **  *   *   *   *  *   *  *   * *    \n");
	printf("*   *  *   *  *    **  *   *  *    * *    *  *   *  *    **  **\n");
	printf("*   *  *   *  *     *  *****  *     *     *  *   *  *     *  **\n");
	printf("Hello welcome to Hangman!!\nMake sure the person who is about to guess is looking away!!\n");
	printf("How many letters does your word have?\n");
	printf("Number of letters: ");
	scanf("%d", &numLetters);
	while ( getchar() != '\n' );

	char *word = malloc(sizeof(char) * (numLetters + 1));
	printf("\nEnter your word?: ");
	scanf("%s", buffer);
	while ( getchar() != '\n' );
	strcpy(word, buffer);

	// Error handling: If number of letters is not correct
	if(strlen(word) != numLetters)
	{
		printf("The word entered and the number do not correlate!! Ending game...\n");
		exit(0);
	}

// Calls game
	gameStart(numLetters, word);
	free(word);

	return 0;
}

void gameStart(int numLetters, char* word)
{
	int i = 0, correctFlag = 0;
	char currentGuess;
	char *guessed = malloc(sizeof(char) * (numLetters + 1));
	int correctCounter = 0;
	int incorrectCounter = 0;
	//int len = strlen(guessed);

	for (i = 0; i < numLetters; i++)
	{
		guessed[i] = '_';
	}

	for (i = 0; i < 200; i++)
	{
		printf("\n");
	}

	printf("\nOk tell your friend to look!!\nPress enter when ready!!\n");

	while(1)
	{
		getchar();
		printf("\nYou have %d out of 6 wrong guesses\n", incorrectCounter);
		printf("\nCurrent progress: ");
		for(i = 0; i < numLetters; i++)
		{
			printf("%c ", guessed[i]);
		}
		printf("\n");

		printf("\nGuess a letter!: ");
		scanf("%c", &currentGuess);

		for(i = 0; i < numLetters; i++)
		{
			if(currentGuess == word[i])
			{
				guessed[i] = currentGuess;
				correctCounter++;
				correctFlag++;
			}
		}

		if(correctFlag == 0)
			incorrectCounter++;
		correctFlag = 0;

		if (correctCounter == numLetters)
		{
			printf("You win!! :)\nYou guessed %s correctly!!\n", word);
			free(guessed);
			return;
		}
		if (incorrectCounter == 6)
		{
			printf("You lose!! :(\nThe word was: %s\n", word);
			free(guessed);
			return;
		}
	}
}
