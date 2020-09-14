#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
  char** my_argv = (char**)calloc(argc + 1, sizeof(char*));

  char* cc = getenv("CC");

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
