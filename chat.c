#include "servpipe.h"

t_conv *find_login(char *login, t_conv *chat)
{
  printf("find_login\n");
  if (!chat || !chat->login)
    return (NULL);
  while (chat->prev)
    chat = chat->prev;
  while (chat->next && chat->login && login && strcmp(chat->login, login))
    chat = chat->next;
  if (!(strcmp(chat->login, login)))
    return (chat);
  printf("find_login out\n");
  return (NULL);
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
  chat->cpt_read = 0;
  add_chain(chat);
  printf("conversation ajouter\n");
  return (chat);
}

void add_chain(t_conv *block)
{
  t_conv *chain;

  block->next = NULL;
  block->prev = NULL;
  if ((chain = recup_chat(NULL)))
    {
      printf("chain\n\n\n");
      block->next = chain;
      chain->prev = block;
      recup_chat(block);
    }
  else
    {
      printf("init_recup_chat\n\n\n\n");
      recup_chat(block);
    }
}

void print_struct(t_conv *chat);
char **ft_repointe(char **tab1, int cpt);
void maj_conv(t_conv *chat, char *buffer)
{
  printf("maj conv :%s:\n", chat->login);
  if (chat->cpt)
    chat->conv = ft_repointe(chat->conv, chat->cpt);
  chat->conv[chat->cpt] = buffer;
  chat->cpt++;
  chat->conv[chat->cpt] = NULL;
  printf("maj conv out\n");
  print_struct(chat);
}

char **ft_repointe(char **tab1, int cpt)
{
  char **new;
  int compt;

  printf("reajustement des pointeurs cpt = %d\n", cpt);
  printf("malloc :%d:\n", cpt+1);
  new = (char **)malloc((cpt+1 * sizeof(char *)) + sizeof(char *));
  compt = -1;
    while (++compt < cpt)
    {
      printf("compt = %d\n", compt);
      printf("tab = :%p:\n", tab1[compt]);
      printf("new = :%s:\n", tab1[compt]);
      new[compt] = tab1[compt];
      printf("new = :%p:\n", new[compt]);
      printf("new = :%s:\n\n\n", new[compt]);
      }
  new[cpt] = NULL;
  printf("reajustement des pointeurs out\n");
  free(tab1);
  return (new);
}
