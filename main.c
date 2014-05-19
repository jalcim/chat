#include "servpipe.h"

int main()
{
  init_chat();
  if (!fork())
    {
      chat("jalcim", "test 1");
      chat("jalcim", "test 2");
      chat("jalcim", "test 3");
      chat("jalcim", "test 4");
      chat("jalcim", "test 5");
      exit(0);
    }
  sleep(1);
  printf("start_chat\n\n\n");
  start_chat();
  recup_chat((t_conv *)-1);
}

void init_chat()
{
  static int fd[2];

  pipe(fd);
  recup_pipe(fd);
}

t_conv *recup_chat(t_conv *chat)
{
  static t_conv *schat = NULL;

  if (!chat)
    return (schat);
  schat = chat;
  if (chat == (t_conv *)-1)
      printf("liberation memoire\n");
  return (NULL);
}

int *recup_pipe(int *fd)
{
  static int *sfd = NULL;

  if (!fd)
    return (sfd);
  sfd = fd;
  return (NULL);
}
