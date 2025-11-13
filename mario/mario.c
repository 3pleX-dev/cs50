#include <stdio.h>

int get_cols(int levels, int cur);

int main(void)
{
  int levels;
  while (1) {
    printf("Enter number of levels: ");
    if (scanf("%d", &levels) == 1 && levels > 0) {
      for (int i = 0; i < levels; i++) {
        get_cols(levels, i);
      }
      printf("\n");
      break;
    } else {
      printf("Not a valid integer\n");
      while(getchar() != '\n');
    }
  }

  return 0;
}

int get_cols(int levels, int cur)
{
  for (int i = 0; i < levels; i++)
  {
    if (i < (levels - 1 - cur)) {
      printf(" ");
    } else {
      printf("#");
    }
  }
  printf("  ");
  for (int i = 0; i < levels; i++)
  {
    if (i < (levels - 1 - cur)) {
      printf("");
    } else {
      printf("#");
    }
  }
  printf("\n");
  return 0;
}