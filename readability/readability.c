#include <stdio.h>
#include <cs50.h>
#include <math.h>

// count number of letters ignoring spaces;
// count the number of words;
// count the number of sentences;

int main(void) {
  string s = get_string("Text: ");
  int letters = 0;
  int words = 1;
  int sentences = 0;

  int i = 0;
  while (s[i] != '\0') {
    if (s[i] != ' ' && s[i] != '?' && s[i] != '.' && s[i] != '!' && s[i] != '\'' && s[i] != '-' && s[i] != '"' && s[i] != ',') {
      letters++;
    }
    if (s[i] == ' ') {
      words++;
    }
    if (s[i] == '?' || s[i] == '.' || s[i] == '!') {
      sentences++;
    }
    i++;
  }
  float L = (letters / (float) words) * 100;
  float S = (sentences / (float) words) * 100;
  float index = 0.0588f * L - 0.296f * S - 15.8f;

  if (index < 1) {
    printf("Before Grade 1\n");
  } else if (index > 16) {
    printf("16+\n");
  } else {
    printf("Grade %d\n", (int) round(index));
  }
  return 0;
}