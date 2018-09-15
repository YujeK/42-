/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhite.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/14 05:43:40 by asamir-k          #+#    #+#             */
/*   Updated: 2018/04/17 12:06:06 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_iswhite(char *str)
{
	if (*str == ' ' || *str == '\t' || *str == '\n')
		return (1);
	else
		return (0);
}