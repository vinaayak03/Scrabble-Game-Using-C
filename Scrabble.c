#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Function to compute the score of a word
int compute_score(char word[])
{
    int score = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        // Only consider alphabetic characters
        if (isalpha(word[i]))
        {
            // Convert the letter to lowercase
            char letter = tolower(word[i]);
            // Calculate score based on the letter's position in the alphabet
            score += POINTS[letter - 'a'];
        }
    }
    return score;
}

int main(void)
{
    // Get input from both players
    char word1[100], word2[100];
    printf("Player 1: ");
    scanf("%99s", word1); // Use %99s to prevent buffer overflow
    printf("Player 2: ");
    scanf("%99s", word2);

    // Compute scores for both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Determine the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}
