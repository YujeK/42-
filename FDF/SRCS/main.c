/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 16:50:42 by asamir-k          #+#    #+#             */
/*   Updated: 2018/09/17 17:16:23 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		deal_key(int key, void *param)
{
	(void) key;
	(void) param;
	ft_putstr("keyinput");
	return (0);
}

int		deal_mouse(int button, void *param)
{
	(void) button;
	(void) param;
	ft_putstr("mouseinput");
	return (0);
}
int		main(void)
{

	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1000, 800, "mlx 42");
	mlx_key_hook(win_ptr, deal_key, (void*)0);
	line_draw(mlx_ptr, win_ptr, 400, 400, 0, 0, 0xFFFFFF);
	line_draw(mlx_ptr, win_ptr, 400, 800, 400, 0, 0xFFFFFF);
	line_draw(mlx_ptr, win_ptr, 400, 400, 0, 800, 0xFFFFFF);
	line_draw(mlx_ptr, win_ptr, 400, 400, 800, 400, 0xFFFFFF);
	line_draw(mlx_ptr, win_ptr, 400, 400, 800, 800, 0xFFFFFF);
	line_draw(mlx_ptr, win_ptr, 400, 400, 400, 800, 0xFFFFFF);
	line_draw(mlx_ptr, win_ptr, 400, 400, 0, 400, 0xFFFFFF);
	line_draw(mlx_ptr, win_ptr, 400, 400, 800, 0, 0xFFFFFF);
	mlx_mouse_hook(win_ptr, deal_mouse, (void*)0);
	mlx_loop(mlx_ptr);
}