#include <stdio.h>
#include <unistd.h>
#include <string.h>

int   main()
{
  FILE *visualiser;
  visualiser = popen("./main.py", "r");
  printf("hello\n");
  pclose(visualiser);
  popen("open 'https://vk.cc/aAmHft'", "r");
  return (0);
}
