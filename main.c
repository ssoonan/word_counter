#include <stdio.h>
#include <string.h>


int word_counter(const char* words) {
  char copied[strlen(words)];
  strcpy(copied, words);
  int counter = 0;

  const char delimiters[] = " ";
  char *token;

  token = strtok(copied, delimiters);

  while (token != NULL) {
    token = strtok(NULL, delimiters);
    counter++;
  }
  return counter;
}

int main(int argc, char const *argv[])
{
  const char* words = "there are many words in this string";
  int counter = word_counter(words);
  printf("words: %d", counter);

  return 0;
}
