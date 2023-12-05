#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int number_to_guess, player_guess, attempts = 0;

    // Initialize random seed
    srand(time(NULL));

    // Generate a random number between 1 and 100
    number_to_guess = rand() % 100 + 1;

    printf("Welcome to the Guess the Number game!\n");
    printf("Try to guess the number between 1 and 100.\n");

    do
    {
        // Get player's guess
        printf("Enter your guess: ");
        scanf("%d", &player_guess);

        // Increment the attempts
        attempts++;

        // Check if the guess is correct
        if (player_guess == number_to_guess)
        {
            printf("Congratulations! You guessed the number in %d attempts.\n", attempts);
        }
        else if (player_guess < number_to_guess)
        {
            printf("Too low! Try again.\n");
        }
        else
        {
            printf("Too high! Try again.\n");
        }

    } while (player_guess != number_to_guess);

    return 0;
}
