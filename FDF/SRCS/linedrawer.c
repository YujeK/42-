/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linedrawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 14:03:54 by asamir-k          #+#    #+#             */
/*   Updated: 2018/09/18 16:56:17 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

int		signdetector(int x)
{
	if (x > 0)
		return (1);
	if (x < 0)
		return (-1);
	return (0);
}

void	ft_brosenham(t_env *env, t_line *line, int color)
{
	int i;

	i = 1;
	while (i <= line->dx)
	{
		mlx_pixel_put(env->mlx, env->win, line->x, line->y, color);
		while (line->d >= 0)
		{
			if (line->swap)
				line->x = line->x + line->s1;
			else
			{
				line->y = line->y + line->s2;
				line->d = line->d - 2 * line->dx;
			}
		}
		if (line->swap)
			line->y = line->y + line->s2;
		else
		{
			line->x = line->x + line->s1;
			line->d = line->d + 2 * line->dy;
			i++;
		}
	}
}

void	line_drawer(t_env *env, int x1, int y1, int x2, int y2, int color)
{
	t_line		*line;

	line = ft_memalloc(sizeof(t_line));
	line->swap = 0;
	line->dx = abs(x2 - x1);
	line->dy = abs(y2 - y1);
	line->s1 = signdetector(x2 - x1);
	line->s2 = signdetector(y2 - y1);
	if (line->dy > line->dx)
	{
		ft_swap(&line->dy, &line->dx);
		line->swap = 1;
	}
	line->d = 2 * line->dy - line->dx;
	line->x = x1;
	line->y = y1;
	ft_brosenham(env, line, color);
}
