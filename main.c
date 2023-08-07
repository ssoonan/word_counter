#include <stdio.h>
#include <string.h>



int main(int argc, char const *argv[])
{
  char * words = "there are many words in this string";
  int length = strlen(words);
  for (size_t i = 0; i < length; i++)
  { 
    printf(words[i]);
  }
  

  return 0;
}
