#include "servpipe.h"

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

t_conv *find_login(char *login, t_conv *chat)
{
  printf("find_login");
  if (!chat || !chat->login)
    return (NULL);
  while (chat->prev)//retour debut chaine
    chat = chat->prev;
  //search login
  while (chat->login && login && strcmp(chat->login, login))
    chat = chat->next;
  if (!(strcmp(chat->login, login)))//verification
    return (chat);
  printf("find_login out\n");
  return (NULL);//retour
}

void add_chain(t_conv *block);
t_conv *creat_conv(char *login)
{
  t_conv *chat;

  printf("creat_conv\n");
  if (!(chat = malloc(sizeof(t_conv))))
    error("malloc error : chat\n");
  if (!(chat->login = login))
    error("invalide login\n");
  if (!(chat->conv = malloc(sizeof(char *) * 2)))
    error("malloc error : conv\n");
  chat->conv[0] = NULL;
  chat->conv[1] = NULL;
  chat->cpt = 0;
  add_chain(chat);

  printf("conversation ajouter\n");
  return (chat);
}

void add_chain(t_conv *block)
{
  t_conv *chain;

  block->next = NULL;
  block->prev = NULL;
  if (chain = recup_chat(NULL))
    {
      block->next = chain;
      chain->prev = block;
    }
  recup_chat(block);
}

char **ft_repointe(char **tab1);
void maj_conv(t_conv *chat, char *buffer)
{
  printf("maj conv\n");
  if (chat->cpt)
    chat->conv = ft_repointe(chat->conv);
   if (!(chat->conv[chat->cpt] = malloc(strlen(buffer+1))))
     {
       printf("malloc error\n");
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

  printf("reajustement des pointeurs\n");
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
  printf("reajustement des pointeurs out\n");
  return (new);
}
