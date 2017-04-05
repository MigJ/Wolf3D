/*
** tools.c for  in /home/joubert/delivery/f_wolf3d/wolf3d
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Sun Jan 15 18:34:14 2017 Joubert Miguel
** Last update Tue Feb 28 01:58:48 2017 Joubert Miguel
*/

#include "../include/my.h"

int	my_count_lines(char *str)
{
  int   i;
  int   lines;

  lines = i = 0;
  while (str[i] != 0)
    {
      if (str[i] == '\n')
	lines++;
      i++;
    }
  return (lines);
}

int	my_count_char(char *str, int i)
{
  int   c;

  c = 0;
  if (str == NULL || str[i] == 0 || str[i] == '\0')
    return (84);
  while (str[i] != '\n')
    i++, c++;
  return (c);
}

int	**my_ret_map(char **av)
{
  t_file        F;
  int   **map;

  F.size = F.k = F.i = F.j = 0;
  F.fd = open(av[1], O_RDONLY);
  while (read(F.fd, &F.c, 1) != 0)
    F.size++;
  F.buffer = malloc(sizeof(char) * 10 * F.size + 1);
  F.fd = open(av[1], O_RDONLY);
  read(F.fd, F.buffer, F.size);
  F.buffer[F.size] = 0;
  map = malloc(sizeof(int *) * 10 * my_count_lines(F.buffer) + 1);
  *map = malloc(sizeof(int) * 10 * my_count_char(F.buffer, F.i) + 1);
  while (F.buffer[F.i] != 0)
    {
      if (F.buffer[F.i] == '\n'){
	map[F.j][F.k] = 84;
	F.j++, F.k = 0, F.i++;
	map[F.j] = malloc(sizeof(int) * 10 * my_count_char(F.buffer, F.i) + 1);
      }
      map[F.j][F.k] = F.buffer[F.i] - 48;
      F.i++, F.k++;
    }
  *map[F.j] = 84;
  return (map);
}
