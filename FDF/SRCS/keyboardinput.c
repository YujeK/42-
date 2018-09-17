/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboardinput.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 20:54:01 by asamir-k          #+#    #+#             */
/*   Updated: 2018/09/17 21:01:26 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

int	    key_manager(int key, void *param)
{
	if (key == 53)
		exit(0);
	(void) param;
	ft_putstr("keyinput :");
	ft_putnbr(key);
    ft_putchar('\n');
	return (0);
}

int		mouse_manager(int button, void *param)
{
	(void) param;
	ft_putstr("mouseinput :");
    ft_putnbr(button);
    ft_putchar('\n'); 
	return (0);
}