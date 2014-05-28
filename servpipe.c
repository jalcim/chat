#include "servpipe.h"

int chat(char *login, char *buffer)
{
  int *fd;

  if (!(fd = recup_pipe(NULL)))
    return (-1);
  printf("ecriture de la part de :%s: message :%s:\n",login, buffer);
  write(fd[1], login, ft_strlen(login));
  write(fd[1], "\0", 1);
  write(fd[1], buffer, ft_strlen(buffer));
  write(fd[1], "\0", 1);
  return (0);
}

void start_chat()
{
  int *fd;
  t_conv *chat;
  char *buffer;
  char *login;

  static int test = -1;

  printf("start_chat\n");
   chat = recup_chat(NULL);
    if (chat)
      ft_putstr("chat recup");
  fd = recup_pipe(NULL);
  while (size_fd(fd[0]))
    {
      if ((!(login = ft_fd_in_str(fd[0])))
	  || (!(buffer = ft_fd_in_str(fd[0]))))
	break;

      printf("tour %d\n", ++test);
      printf("lecture de la part de :%s: message :%s:\n",login, buffer);
      if ((chat = find_login(login, chat)))
	  ft_putstr("chat trouver\n");
      else
	{
	  chat = creat_conv(login);
	  ft_putstr("chat creer\n");
	}
      maj_conv(chat, buffer);
      printf("chat->log :%s:\n", chat->login);
      printf("chat->conv :%s:\n", chat->conv[chat->cpt -1]);
      printf("?\n");
    }
  printf("exit\n");
  if (login)
    ft_putendl(login);
  if (buffer)
    ft_putendl(buffer);
}
