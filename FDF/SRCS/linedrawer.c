/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linedrawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 14:03:54 by asamir-k          #+#    #+#             */
/*   Updated: 2018/09/17 15:34:26 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "mlx.h"
#include "fdf.h"

void	line_draw(void *mlx_ptr,void *win_ptr, int x1,int y1, int x2, int y2, int color)
{
 int dx, dy, x, y, d, s1, s2, swap=0, temp;

  dx = abs(x2 - x1);
  dy = abs(y2 - y1);
  s1 = sign(x2-x1);
  s2 = sign(y2-y1);

  /* Check if dx or dy has a greater range */
  /* if dy has a greater range than dx swap dx and dy */
  if(dy > dx){temp = dx; dx = dy; dy = temp; swap = 1;}

  /* Set the initial decision parameter and the initial point */
  d = 2 * dy - dx;
  x = x1;
  y = y1;

  int i;

  i = 1;
while (i <= dx)
  {
    mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
    
    while(d >= 0) 
    {
      if(swap) x = x + s1;
      else 
      {
        y = y + s2;
        d = d - 2* dx;
      }
    }
    if(swap) y = y + s2;
    else x = x + s1;
    d = d + 2 * dy;
	i++;
  }
}