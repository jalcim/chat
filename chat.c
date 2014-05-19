#include "servpipe.h"

t_conv *find_login(char *login, t_conv *chat)
{
  ft_putstr("find_login");
  if (!chat || !chat->login)
    return (NULL);
  while (chat->prev)
    chat = chat->prev;
  ft_putstr("find_login tet\n");
  while (chat->login && login && ft_strcmp(chat->login, login))
    chat = chat->next;
  ft_putstr("find_login settt\n");
  if (!(ft_strcmp(chat->login, login)))
    return (chat);
  ft_putstr("find_login out\n");
  return (NULL);
}

t_conv *creat_conv(char *login)
{
  t_conv *chat;

  chat = NULL;
  printf("creat_conv\n");
  if (!(chat = malloc(sizeof(t_conv))))
    return (NULL);
  if (!(chat->login = malloc(ft_strlen(login) + 1)))
    return (NULL);
  ft_strncpy(chat->login, login, ft_strlen(login));
  if (!(chat->conv = malloc(sizeof(char *) * 2)))
    return (NULL);
  ft_putstr("conversation creer\n");
  chat->conv[0] = NULL;
  chat->cpt = 0;

  return (chat);
}

char **ft_repointe(char **tab1);
void maj_conv(t_conv *chat, char *buffer)
{
  printf("maj conv\n");
  if (chat->cpt)
    chat->conv = ft_repointe(chat->conv);
   if (!(chat->conv[chat->cpt] = malloc(ft_strlen(buffer+1))))
     {
       ft_putendl("malloc error\n");
       exit(-1);
     }
   chat->conv[chat->cpt] = buffer;
   printf("1 buffer = :%s:\n", buffer);
   printf("2 chat->conv = :%s:\n", chat->conv[chat->cpt]);
   chat->cpt++;
   chat->conv[chat->cpt] = NULL;
}

char **ft_repointe(char **tab1)
{
  char **new;
  int compt;
  int tmp;

  ft_putendl("reajustement des pointeurs");
  new = malloc(sizeof(**tab1) + sizeof(char *));
  compt = 0;
  while (tab1[compt])
    {
      printf("re\n");
      new[compt] = tab1[compt];
      printf("while\n");
      if (tab1[compt])
	{
	  printf("tab[%d] = ", compt);
	  printf(":%s:\n", tab1[compt]);
	}
      else
	printf("ERROR !!!!!!!!!!\n\n\n");
      compt++;
    }
  new[compt] = NULL;
  ft_putendl("reajustement des pointeurs out");
  return (new);
}
