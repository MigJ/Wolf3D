/*
** move_forward.c for  in /home/joubert/delivery/wolf3d
** 
** Made by Joubert Miguel
** Login   <miguel.joubert@epitech.eu>
** 
** Started on  Tue Jan  3 11:19:47 2017 Joubert Miguel
** Last update Tue Jan  3 12:25:12 2017 Joubert Miguel
*/

#include "../include/my.h"

sfVector2f	move_forward(sfVector2f pos, float direction, float distance)
{
  sfVector2f	res;

  res.x = pos.x + (distance * cos(direction));
  res.y = pos.y + (distance * sin(direction));
  return (res);
}
