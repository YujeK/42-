/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linedrawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 14:03:54 by asamir-k          #+#    #+#             */
/*   Updated: 2018/09/17 20:18:38 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "mlx.h"
#include "fdf.h"

int signdetector(int x)
{
  if (x > 0)
    return (1);
  if (x < 0)
    return (-1);
  return (0);
}

void	line_draw(void *mlx_ptr,void *win_ptr, int x1,int y1, int x2, int y2, int color)
{
  t_line   *line;

  line = ft_memalloc(sizeof(t_line));

 int  swap=0, temp;

  line->dx = abs(x2 - x1);
  line->dy = abs(y2 - y1);
  line->s1 = signdetector(x2-x1);
  line->s2 = signdetector(y2-y1);

  /* Check if dx or dy has a greater range */
  /* if dy has a greater range than dx swap dx and dy */
  if(line->dy > line->dx){temp = line->dx; line->dx = line->dy; line->dy = temp; swap = 1;}

  /* Set the initial decision parameter and the initial point */
  line->d = 2 * line->dy - line->dx;
  line->x = x1;
  line->y = y1;

  int i;

  i = 1;
while (i <= line->dx)
  {
    mlx_pixel_put(mlx_ptr, win_ptr, line->x, line->y, color);
    while(line->d >= 0) 
    {
      if(swap) line->x = line->x + line->s1;
      else 
      {
        line->y = line->y + line->s2;
        line->d = line->d - 2 * line->dx;
      }
    }
    if(swap) line->y = line->y + line->s2;
    else line->x = line->x + line->s1;
    line->d = line->d + 2 * line->dy;
	i++;
  }
}
