#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <stdbool.h>

/*
AE - 15 digits; starts with 34 or 37
MC - 16 digits; starts with 51, 52, 53, 54, 55
Visa - 13 and 16 digits; starts with 4

- convert input to string
- get the size of the string and compare with the cards
- get the size of the input and compare if it's within 15, 16 and 13
- check the first digit against visa (4) then AE (34 or 37) then MC (51, 52, 53, 54, 55);
- 
 */
int validate(long card_no, int direction);
bool includes(char *arr[], int size, const char *target);

int main(void)
{
  long card_no = get_long("Number: ");
  char *card_str = malloc(21);
  if (card_str == NULL)
  {
    printf("Memory error\n");
    exit(1);
  }
  sprintf(card_str, "%li", card_no); // convert number to string
  printf("String val: %s, with size: %zu, first two: %c, %c\n", card_str, strlen(card_str), card_str[0], card_str[1]);
  if (strlen(card_str) == 15)
  {
    char sd[3] = {card_str[0], card_str[1], '\0'};
    char *arr[2] = {"34", "37"};
    if (includes(arr, 2, sd))
    {
      int sum = validate(card_no, 1) + validate(card_no, 0);
      if (sum % 10 == 0) {
        printf("AMEX\n");
      } else {
        printf("INVALID!\n");
      }
    } else {
      printf("INVALID!\n");
    }
  }
  if (strlen(card_str) == 16)
  {
    if (card_str[0] == '4')
    {
      char sd[2] = {card_str[0], '\0'};
      char *arr[1] = {"4"};
      if (includes(arr, 1, sd))
      {
        int sum = validate(card_no, 1) + validate(card_no, 0);
        if (sum % 10 == 0) {
          printf("VISA\n");
        } else {
          printf("INVALID!\n");
        }
      } else {
        printf("outside!!");
        printf("INVALID!\n");
      }
    } else {
      char sd[3] = {card_str[0], card_str[1], '\0'};
      char *arr[5] = {"51", "52", "53", "54", "55"};
      if (includes(arr, 5, sd))
      {
        int sum = validate(card_no, 1) + validate(card_no, 0);
        if (sum % 10 == 0) {
          printf("MASTERCARD\n");
        } else {
          printf("INVALID!\n");
        }
      } else {
        printf("INVALID!\n");
      }
    }
  }
  if (strlen(card_str) == 13)
  {
    char sd[2] = {card_str[0], '\0'};
    char *arr[1] = {"4"};
    if (includes(arr, 1, sd))
    {
      int sum = validate(card_no, 1) + validate(card_no, 0);
      if (sum % 10 == 0) {
        printf("VISA\n");
      } else {
        printf("INVALID!\n");
      }
    } else {
      printf("INVALID!\n");
    }
  }
  free(card_str);
  return 0;
}

int validate(long card_no, int direction)
{
  int res = 0;
  int count = 0;
  while (card_no > 0)
  {
    int digit = card_no % 10;
    if (direction == 1 && count % 2 == 1)
    {
      int d_digit = digit * 2;
      int sum = 0;
      while (d_digit > 0)
      {
        sum += d_digit % 10;
        d_digit /= 10;
      }
      res += sum;
    } else if (direction == 0 && count % 2 == 0)
    {
      res += digit;
    }
    card_no = card_no / 10;
    count++;
  }
  return res;
}

bool includes(char *arr[], int size, const char *target)
{
  for (int i = 0; i < size; i++)
  {
    if (strcmp(arr[i], target) == 0)
    {
      return true;
    }
  }
  return false;
}
