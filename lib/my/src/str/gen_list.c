/*
** gen_list.c for gen_list in /home/geiger_a/test
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Fri Feb 20 12:12:13 2015 anthony geiger
** Last update Tue Feb 24 10:32:11 2015 anthony geiger
*/

#include <stdlib.h>
#include "my.h"

t_glist*	new_glist(t_glist* old, void* data)
{
  t_glist*	new;
  t_glist*	tmp;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->next = NULL;
  new->prev = NULL;
  new->data = data;
  if (old == NULL)
    return (new);
  tmp = old;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  new->prev = tmp;
  return (old);
}

void		free_glist(t_glist *s)
{
  t_glist*	tmp;

  tmp = s;
  while (tmp->next != NULL)
    tmp = tmp->next;
  while (tmp->prev != NULL)
    {
      tmp = tmp->prev;
      free(tmp);
    }
}

void		*list_finder(t_glist *s, t_alias alias)
{
  unsigned int 	i;
  t_glist	*tmp;

  tmp = s;
  i = 0;
  while (i != alias)
    {
      tmp = tmp->next;
      ++i;
    }
  return (tmp->data);
}
