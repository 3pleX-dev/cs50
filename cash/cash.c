#include <stdio.h>

// denominations: 25, 10, 5, 1
// while amount is not 0 continue dividing

int main(void) {
  int change = 0;
  while(1) {
    printf("Change owed: ");
    if (scanf("%d", &change) == 1 && change > 0) {
      int rem = change;
      int denominations = 0;
      while(rem > 0) {
        if (rem >= 25) {
          denominations += rem / 25;
          rem %= 25;
        } else if (rem >= 10) {
          denominations += rem / 10;
          rem %= 10;
        } else if (rem >= 5) {
          denominations += rem / 5;
          rem %= 5;
        } else {
          denominations += rem;
          rem %= 1;
        } 
      }
      printf("%d\n", denominations);
      break;
    } else {
      printf("Invalid amount!\n");
      while(getchar() != '\n');
    }
  }

  return 0;
}