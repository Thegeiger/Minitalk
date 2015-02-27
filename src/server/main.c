/*
** main.c for client in /home/geiger_a/rendu/PSU_2014_minitalk/src
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Feb 24 10:35:53 2015 anthony geiger
** Last update Wed Feb 25 15:40:41 2015 anthony geiger
*/

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "my.h"

static char		conv_btc(char sing)
{
  static char  		c = 0;
  static int		s_nsing = 0;

  if (s_nsing == 0)
    c = 0;
  if (sing == 1)
    {
      c |= (0b10000000 >> s_nsing);
    }
  if (s_nsing == 8)
    {
      s_nsing = 0;
      return (c);
    }
  else
    if (sing != 2)
      s_nsing++;
  return (-1);
}

static void		case_true()
{
  conv_btc(1);
}

static void		case_false()
{
  conv_btc(0);
}

int	main(void)
{
  int	pid;
  char	c;

  pid = getpid();
  my_putnbr(pid);
  my_putchar('\n');
  signal(SIGUSR1, &case_true);
  signal(SIGUSR2, &case_false);
  while (42)
    {
      c = conv_btc(2);
      if (c != -1)
	{
	  my_putchar(c);
	}
    }
  return (0);
}
