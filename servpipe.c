#include "servpipe.h"

int print_str_struct(t_conv *chat);
void print_struct(t_conv *chat);

int chat(char *login, char *buffer)
{
  int *fd;

  if (!(fd = recup_pipefd(NULL)))
    return (-1);
  printf("ecriture de la part de :%s: message :%s:\n",login, buffer);
  write(fd[1], login, strlen(login));
  write(fd[1], "\0", 1);
  write(fd[1], buffer, strlen(buffer));
  write(fd[1], "\0", 1);
  return (0);
}

void start_chat()
{
  int *fd;
  t_conv *chat;
  char *buffer;
  char *login;

  printf("start_chat\n");
  chat = recup_chat(NULL);
    if (chat)
      printf("chat recup\n");
  fd = recup_pipefd(NULL);
  while (size_fd(fd[0]))
    {
      login = NULL;
      buffer = NULL;
      if ((!(login = ft_fd_in_str(fd[0])))
	  || (!(buffer = ft_fd_in_str(fd[0]))))
	break;
      printf("lecture de la part de :%s: message :%s:\n",login, buffer);
      if ((chat = find_login(login, chat)))
	printf("chat trouver\n");
      else
	{
	  chat = creat_conv(login);
	  printf("chat creer\n");
	}
      maj_conv(chat, buffer);
      printf("start buffer = :%s:\n", buffer);
      login = NULL;
      buffer = NULL;
    }
  //  recup_chat(chat);
    print_struct(chat);
}

void print_struct(t_conv *chat)
{
  //  int b = 1;

  printf("print_struct\n");
  dup2(2, 1);
  //  while (chat->prev)
  //chat = chat->prev;
  //  while (b)
  //{
      while (print_str_struct(chat))
	{}
      chat->cpt_read = 0;
      //      if (chat->next)
      //chat = chat->next;
      //      else
	//b = 0;
      // }
  printf("print_struct out\n");
}

int print_str_struct(t_conv *chat)
{
  if (chat->cpt_read >= chat->cpt)
    return (0);
  if (!chat->login)
    printf("pas d'login\n");
  if (!chat->conv[chat->cpt_read])
    printf("error structure\n");
  printf("aff\n");
  printf("login :%s: chat conv[%d] sur [%d]= :%s:\n", 
	 chat->login, chat->cpt_read, chat->cpt, chat->conv[chat->cpt_read]);
  printf("XD\n");
  chat->cpt_read++;
  return (1);
}
