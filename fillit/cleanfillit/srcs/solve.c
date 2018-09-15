/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 18:09:20 by ghtouman          #+#    #+#             */
/*   Updated: 2018/05/16 17:27:59 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_solve(t_stock *ma_list, t_struct *ma_struct)
{
	t_stock *tmp;

	tmp = ma_list;
	while (placement(tmp, ma_struct, 0, 0) == FALSE)
	{
		ma_struct->base_grid++;
		tab_map(ma_struct);
		tmp = ma_list;
	}
	return (ma_struct->map);
}
