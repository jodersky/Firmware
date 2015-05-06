#include <nuttx/config.h>
#include <stdio.h>
#include <errno.h>

__EXPORT int helloworld_main(int argc, char *argv[]);

int helloworld_main(int argc, char *argv[]) {
  printf("Hello world!\n");
  return 0;
}
