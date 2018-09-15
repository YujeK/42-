/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 11:07:18 by ghtouman          #+#    #+#             */
/*   Updated: 2018/05/15 15:09:12 by ghtouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_min(int x, int y)
{
	return (x > y) ? y : x;
}