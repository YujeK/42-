/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 19:19:33 by ghtouman          #+#    #+#             */
/*   Updated: 2018/05/16 17:26:51 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		ft_check(t_stock *ma_list, t_struct *ma_struct, int y, int x)
{
	int	check;
	int	i;

	i = -1;
	check = TRUE;
	if (y + ma_list->height >= ma_struct->base_grid)
		return (FALSE);
	while (++i < 4)
	{
		if (ma_struct->map[y + ma_list->toby[i]][x + ma_list->tobx[i]] != '.')
			check = FALSE;
		if (check == FALSE)
			break ;
	}
	if (check == TRUE)
		return (TRUE);
	return (FALSE);
}

static	void	putetri(t_stock *ma_list, t_struct *ma_struct, int y, int x)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		ma_struct->map[y + ma_list->toby[i]]
			[x + ma_list->tobx[i]] = 65 + ma_list->number_list;
	}
}

static	void	del_tetri(t_stock *ma_list, t_struct *ma_struct, int y, int x)
{
	ma_struct->map[y + ma_list->toby[0]][x + ma_list->tobx[0]] = '.';
	ma_struct->map[y + ma_list->toby[1]][x + ma_list->tobx[1]] = '.';
	ma_struct->map[y + ma_list->toby[2]][x + ma_list->tobx[2]] = '.';
	ma_struct->map[y + ma_list->toby[3]][x + ma_list->tobx[3]] = '.';
}

int				placement(t_stock *ma_list, t_struct *ma_struct, int y, int x)
{
	if (ma_list == NULL)
		return (TRUE);
	if (y == ma_struct->base_grid)
		return (FALSE);
	if (ma_struct->map[y][x] == '\n' && y < ma_struct->base_grid)
		return (placement(ma_list, ma_struct, y + 1, 0));
	if (ft_check(ma_list, ma_struct, y, x) == TRUE)
	{
		putetri(ma_list, ma_struct, y, x);
		if (placement(ma_list->next, ma_struct, 0, 0) == TRUE)
			return (TRUE);
		del_tetri(ma_list, ma_struct, y, x);
	}
	return (placement(ma_list, ma_struct, y, x + 1));
}
