/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/01 14:43:02 by ghtouman          #+#    #+#             */
/*   Updated: 2018/05/17 16:21:33 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		size_error(char *str)
{
	int i;
	int point;
	int cross;

	i = -1;
	point = 0;
	cross = 0;
	while (str[++i])
	{
		if (str[i] == '.')
			point++;
		if (str[i] == '#')
			cross++;
	}
	if (cross != 4 || point != 12)
		return (FALSE);
	return (TRUE);
}

static	int		ntreturn_error(char *str)
{
	int i;
	int nreturn;

	i = 4;
	nreturn = 0;
	while (str[i] && i < 21)
	{
		if (str[i] == '\n')
			nreturn++;
		else
			return (FALSE);
		i = i + 5;
	}
	if ((nreturn == 4 && str[20] == '\n' && str[21] == '\0') ||
			((nreturn == 4 && str[20] == '\n' && str[21] == '\n')))
		return (TRUE);
	return (FALSE);
}

static	int		link_error(char *str)
{
	int i;
	int link;

	i = -1;
	link = 0;
	while (str[++i])
	{
		if (str[i] == '#')
		{
			if (str[i + 1] == '#' && str[i + 1])
				link++;
			if (str[i + 5] == '#' && str[i + 5])
				link++;
			if (str[i - 1] == '#' && str[i - 1])
				link++;
			if (str[i - 5] == '#' && str[i - 5])
				link++;
		}
	}
	if (link == 6 || link == 8)
		return (TRUE);
	return (FALSE);
}

int				check_error(t_stock *ma_list)
{
	t_stock *before;

	while (ma_list)
	{
		link_error(ma_list->content);
		if (((size_error(ma_list->content) == FALSE)
					&& (ntreturn_error(ma_list->content) == FALSE))
				|| link_error(ma_list->content) == FALSE)
		{
			ft_putstr_fd("error\n", 1);
			return (FALSE);
		}
		else
		{
			before = ma_list;
			ma_list = ma_list->next;
		}
	}
	if (before->content[20] == '\n')
	{
		ft_putstr_fd("error\n", 1);
		return (FALSE);
	}
	return (TRUE);
}
