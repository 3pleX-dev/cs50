#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  if (argc != 2){
    printf("Usage: ./substitution key\n");
    return 1;
  }
  int len = strlen(argv[1]);
  
  if (len != 26) {
    printf("Key must contain 26 characters.\n");
    return 1;
  }

  char rule[26] = {0};
  for (int i = 0; i < 26; i++) {
    int ascii = argv[1][i];
    for (int j = 0; j < i; j++) {
      if (ascii == rule[j]) {
        printf("Key must not contain duplicate characters.\n");
        return 1;
      }
    }
    if ((ascii < 65 || ascii > 90) && (ascii < 97 || ascii > 122)) {
      printf("Key must only contain alphabet characters.\n");
      return 1;
    }
    rule[i] = ascii;
  }

  char *plaintext = get_string("plaintext:  ");
  int textlen = strlen(plaintext);
  char ciphertext[textlen + 1];
  ciphertext[textlen] = '\0';

  for (int i = 0; i < textlen; i++) {
    int ascii = plaintext[i];

    if (ascii >= 65 && ascii <= 90)
    {
      int idx = ascii - 65; // reset to 0
      ciphertext[i] = (rule[idx] >= 97) ? rule[idx] - 32 : rule[idx];
    } else if (ascii >= 97 && ascii <= 122) {
        int idx = ascii - 97;
        ciphertext[i] = (rule[idx] <= 90) ? rule[idx] + 32 : rule[idx];
    } else {
      ciphertext[i] = ascii;
    }
  }

  printf("ciphertext: %s\n", ciphertext);
  return 0;
}