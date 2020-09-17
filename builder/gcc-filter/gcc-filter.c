#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#ifndef PATH_TO_CC
#define PATH_TO_CC "/usr/bin/gcc"
#endif

int main(int argc, char** argv) {
  char** my_argv = (char**)calloc(argc + 1, sizeof(char*));

  my_argv[0] = PATH_TO_CC;

  int i = 1;
  int j = 1;
  while(i < argc) {
    if (strcmp("-lgcc_s", argv[i]) != 0) {
      my_argv[j] = argv[i];
      j++;
    }
    i++;
  }
  execvp(my_argv[0], &my_argv[0]);
  return 0;
}
