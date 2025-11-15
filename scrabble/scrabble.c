#include <stdio.h>
#include <string.h>

int get_score(int *arr, char *word);

int main(void)
{
  int letters[26] = {1, 3, 3, 2, 1,	4, 2,	4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
  char player1[50];
  char player2[50];
  printf("Player 1: ");
  scanf("%49s", player1);
  printf("Player 2: ");
  scanf("%49s", player2);

  int score1 = get_score(letters, player1);
  int score2 = get_score(letters, player2);

  if (score1 > score2) {
    printf("Player 1 wins!\n");
  } else if (score2 > score1) {
    printf("Player 2 wins!\n");
  } else {
    printf("Tie!\n");
  }

  return 0;
}

int get_score(int *arr, char *word)
{
  int score = 0;
  for (int i = 0; i < strlen(word); i++)
  {
    int ascii = word[i];
    if (ascii >= 65 && ascii <= 91)
    {
      score += arr[ascii - 65];
    } else if (ascii >= 97 && ascii <= 122) {
      score += arr[ascii - 97];
    }
  }
  return score;
}