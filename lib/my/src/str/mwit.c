/*
** mwit.c for mwit in /home/geiger_a/test
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Fri Feb  6 10:22:05 2015 anthony geiger
** Last update Mon Feb  9 11:14:10 2015 anthony geiger
*/

#include <stdlib.h>
#include "my.h"

int		count_word(char *c, char sep)
{
  int		i;
  int		word;

  word = 1;
  i = 0;
  while (c[i])
    {
      if (c[i] == sep)
	word++;
      while (c[i] == sep)
	i++;
      if (c[i] != '\0')
	i++;
    }
  return (word);
}

int		word_len(char *c, char sep, int y)
{
  int   	i;
  int		len;
  int		count;

  count = 0;
  i = 0;
  len = 0;
  while (count != y)
    {
      while (c[i] != sep && c[i] != '\0')
	{
	  i++;
	}
      count++;
      i++;
    }
  while (c[i] != sep && c[i] != '\0')
    {
      len++;
      i++;
    }
  while (c[i] == sep)
    ++i;
  return (len);
}

char		**add_word_to_tab(char *c, char **tab, int y, char sep)
{
  int		x;
  int   	i;
  int		count;

  count = 0;
  x = 0;
  i = 0;
  while (count != y)
    {
      while (c[i] != sep && c[i] != '\0')
	i++;
      count++;
      i++;
    }
  while (c[i] != sep && c[i] != '\0')
    {
      tab[y][x] = c[i];
      i++;
      x++;
    }
  tab[y][x] = '\0';
  while (c[i] == sep)
    ++i;
  return (tab);
}

char		**mwit(char *c, char sep)
{
  int		word;
  char		**tab;
  int		y;
  int		len;

  y = 0;
  len = 0;
  if (c == NULL)
    return (NULL);
  word = count_word(c, sep);
  if ((tab = malloc(sizeof(char *) * (word + 1))) == NULL)
    return (NULL);
  while (y != word)
    {
      len = 0;
      len = word_len(c, sep, y);
      if ((tab[y] = malloc(sizeof(char) * (len + 1))) == NULL)
	return (NULL);
      add_word_to_tab(c, tab, y, sep);
      y++;
    }
  tab[y] = NULL;
  return (tab);
}
