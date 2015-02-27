/*
** main.c for serv in /home/geiger_a/rendu/PSU_2014_minitalk/src/client
**
** Made by anthony geiger
** Login   <geiger_a@epitech.net>
**
** Started on  Tue Feb 24 10:34:44 2015 anthony geiger
** Last update Wed Feb 25 15:06:37 2015 anthony geiger
*/

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "my.h"

static int	encode_fonc(char *str, int pid)
{
  int		i;
  int		n;
  char		c;

  i = 0;
  while (str[i])
    {
      n = 0;
      c = str[i];
      while (n != 8)
	{
	  if ((c & (0b10000000) >> n) & (0b10000000 >> n))
	    {
	      if (kill(pid, SIGUSR1) == -1)
		return (1);
	    }
	  else
	    if (kill(pid, SIGUSR2) == -1)
	      return (1);
	  usleep(5);
	  n++;
	}
      i++;
    }
  return (0);
}

int	main(int argc, char **argv)
{
  int  	pid;

  if (argc != 3)
    {
      my_putstr("to few argument\n");
      return (2);
    }
  pid = my_getnb(argv[1]);
  encode_fonc(argv[2], pid);
  return (0);
}
