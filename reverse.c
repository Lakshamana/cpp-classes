#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *reverse(const char *s) {
  int l = strlen(s);

  char *r = (char *)calloc(l + 1, sizeof(char));

  for (r += l; *s; s++) {
    *(--r) = *s;
  }

  return r;
}

int main(int argc, char *argv[]) {
  const char *s = "hello";
  printf("reversed: %s\n", reverse(s));
  return EXIT_SUCCESS;
}
