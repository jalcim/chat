#include <stdio.h>
#include <stdlib.h>

void error(char *str)
{
  perror("error ->");
  exit(-1);
}
