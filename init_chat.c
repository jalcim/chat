#include "servpipe.h"

void init_chat()
{
  int *pipefd;

  if (!(pipefd = (int *)malloc(2*sizeof(int))))
    error("malloc error\n");
  pipe(pipefd);
  recup_pipefd(pipefd);
}

int *recup_pipefd(int *pipe)
{
  static int *s_pipe = NULL;

  if (!pipe)
    {
      printf("recup_pipe ret\n");
      return (s_pipe);
    }
  else if (pipe != (int *)-1)
    {
      printf("recup_pipe reg\n");
      s_pipe = pipe;
    }
  else
    if (s_pipe)
      {
	printf("recup_pipe free\n");
	close(s_pipe[0]);
	close(s_pipe[1]);
	free(s_pipe);
      } 
  return (NULL);
}

t_conv *recup_chat(t_conv *chat)
{
  static t_conv *schat = NULL;
  int compt;

  if (!chat)
    return (schat);
  /*  else if (chat == (t_conv *)-1 && schat)
    while (schat->next)
      {
	schat = schat->next;
	compt = -1;
	if (schat->prev)
	  {
	    while (++compt < schat->prev->cpt)
	      if (schat->prev->conv[compt])
		free(schat->prev->conv[compt]);
	    free(schat->prev->login);
	    free(schat->prev);
	    schat->prev = NULL;
	  }
	  }*/
  else
    schat = chat;
  return (NULL);
}
