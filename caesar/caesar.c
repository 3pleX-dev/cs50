#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

/*
- get arguments
- exit program if no argument is passed
- exit program if argument doesn't match criteria
- validate for negative integers
- 65 -> 91; 0 -> 25; ((67 - 65 + 3) % 26) + 65
- ((a + k - A)%26) + A
*/

int main(int argc, char *argv[])
{
  if (argc != 2){
    printf("Usage: ./caesar key\n");
    return 1;
  }
  char *end;
  int n = strtol(argv[1], &end, 10);
  
  if (*end != '\0') {
    printf("Usage: ./caesar key\n");
    return 1;
  }

  char *plaintext = get_string("plaintext:  ");
  char ciphertext[strlen(plaintext) + 1]; // not adding a space for null terminator here will cause progam to keep printing garbage values until it reaches a 0 byte in memory

  for (int i = 0; i < strlen(plaintext); i++) {
    int ascii = plaintext[i];

    if (ascii >= 65 && ascii <= 90)
    {
      int cipher = ((ascii - 65 + n) % 26) + 65;
      ciphertext[i] = cipher;
    } else if (ascii >= 97 && ascii <= 122) {
      int cipher = ((ascii - 97 + n) % 26) + 97;
      ciphertext[i] = cipher;
    } else {
      ciphertext[i] = ascii;
    }
  }

  printf("ciphertext: %s\n", ciphertext);
  return 0;
}