#include <stdlib.h>
#include <unistd.h>

void error(char *strerr)
{
  write(1, strerr, sizeof(*strerr));
  exit(-1);
}

void init_chat()
{
  int *pipe;

  if (!(pipe = (int *)malloc(2*sizeof(int))))
    error("malloc error\n");
  pipe(pipe);
  recup_pipe(pipe);
}

int *recup_pipe(int *pipe)
{
  static int *s_pipe = NULL;

  if (!pipe)
    return (s_pipe);
  else if (pipe != -1)
    s_pipe = pipe;
  else
    if (s_pipe)
      {
	close(s_pipe[0]);
	close(s_pipe[1]);
	free(s_pipe);
      } 
  return (NULL);
}
