#include <stdio.h>
#include <string.h>

char *self_strtok(char *s, const char *delim)
{
	static char *last;
	return strtok_r(s, delim, &last);
}

char *strtok_r(char *s, const char *delim, char **last)
{
	char *spanp;
	int c, sc;
	char *tok;
	if (s == NULL && (s = *last) == NULL)
		return (NULL);
	/*
	 * Skip (span) leading delimiters (s += strspn(s, delim), sort of).
	 */
cont:
	c = *s++; 
  // delim이 1글자인 건 아니군~! 그러니까 여기서도 +는 필요하다
  // 이 loop는 c == sc가 계속 이어질 때만 반복됨. 이게 도중에 깨지면 밑으로 진행, 이 상태에서 null로 끝나버리면 end
	for (spanp = (char *)delim; (sc = *spanp++) != 0;) {
		if (c == sc)
			goto cont;
	}
	if (c == 0) {		/* no non-delimiter characters */
		*last = NULL;
		return (NULL);
	}
	tok = s - 1;
	/*
	 * Scan token (scan for delimiters: s += strcspn(s, delim), sort of).
	 * Note that delim must have one NUL; we stop if we see that, too.
	 */
	for (;;) {
		c = *s++;
		spanp = (char *)delim;
		do {
			if ((sc = *spanp++) == c) {
				if (c == 0)
					s = NULL;
				else
					s[-1] = 0;
				*last = s;
				return (tok);
			}
		} while (sc != 0);
	}
	/* NOTREACHED */
}

int word_counter(const char* words) {
  char copied[strlen(words)];
  strcpy(copied, words);
  int counter = 0;

  const char *delimiters = " ";
  char *token;

  token = self_strtok(copied, delimiters);

  while (token != NULL) {
    token = self_strtok(NULL, delimiters);
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
