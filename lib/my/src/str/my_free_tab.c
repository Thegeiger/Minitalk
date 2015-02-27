/*
** my_free_tab.c for free in /home/geiger_a/rendu/PSU_2014_minishell2/new
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Mon Feb  9 11:10:57 2015 anthony geiger
** Last update Mon Feb  9 11:12:00 2015 anthony geiger
*/

#include "my.h"

void		my_free_tab(char **tab, int len)
{
  while (len != -1)
    free(tab[len--]);
  free(tab);
}
