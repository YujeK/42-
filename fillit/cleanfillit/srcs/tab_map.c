/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 12:05:53 by ghtouman          #+#    #+#             */
/*   Updated: 2018/05/16 17:24:02 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_get_coord(t_stock *ma_list, int i, int x, int y)
{
	int j;

	while (ma_list)
	{
		i = -1;
		y = 0;
		x = 0;
		j = 0;
		while (ma_list->content[++i])
		{
			if (ma_list->content[i] == '\n')
			{
				y++;
				x = 0;
			}
			if (ma_list->content[i] == '#')
			{
				ma_list->toby[j] = y;
				ma_list->tobx[j++] = x;
			}
			if (ma_list->content[i] != '\n')
				x++;
		}
		ma_list = ma_list->next;
	}
}

void	ft_zaap(t_stock *ma_list)
{
	int i;
	int min_x;
	int min_y;

	while (ma_list)
	{
		i = 1;
		min_x = ft_min(ma_list->tobx[0], ma_list->tobx[1]);
		min_y = ft_min(ma_list->toby[0], ma_list->toby[1]);
		while (++i < 4)
		{
			min_x = ft_min(min_x, ma_list->tobx[i]);
			min_y = ft_min(min_y, ma_list->toby[i]);
		}
		i = -1;
		while (++i < 4)
		{
			ma_list->tobx[i] = ma_list->tobx[i] - min_x;
			ma_list->toby[i] = ma_list->toby[i] - min_y;
		}
		ma_list = ma_list->next;
	}
}

void	ft_height(t_stock *ma_list)
{
	int i;
	int max;

	while (ma_list)
	{
		i = 1;
		max = ft_max(ma_list->toby[0], ma_list->toby[1]);
		while (++i < 4)
			max = ft_max(max, ma_list->toby[i]);
		ma_list->height = max;
		ma_list = ma_list->next;
	}
}

void	free_tab(t_struct *ma_struct)
{
	int j;

	j = 0;
	while (ma_struct->map[j])
	{
		free(ma_struct->map[j]);
		j++;
	}
	free(ma_struct->map);
}

char	**tab_map(t_struct *ma_struct)
{
	int			x;
	int			y;

	ma_struct->map != NULL ? free_tab(ma_struct) : 0;
	if (!(ma_struct->map = (char **)ft_memalloc(sizeof(*ma_struct->map)
			* ma_struct->base_grid)))
		return (NULL);
	x = -1;
	while (++x < ma_struct->base_grid)
	{
		if (!(ma_struct->map[x] = (char*)malloc(sizeof(char)
			* ma_struct->base_grid)))
			return (NULL);
		y = -1;
		while (++y <= ma_struct->base_grid)
		{
			if (y == ma_struct->base_grid)
				ma_struct->map[x][y] = '\n';
			else
				ma_struct->map[x][y] = '.';
		}
		ma_struct->map[x][y] = 0;
	}
	ma_struct->map[x] = 0;
	return (ma_struct->map);
}
