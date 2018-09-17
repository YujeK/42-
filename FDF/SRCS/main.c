/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 16:50:42 by asamir-k          #+#    #+#             */
/*   Updated: 2018/09/17 18:55:25 by asamir-k         ###   ########.fr       */
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
	t_env *env;

	if (!(env = ft_memalloc(sizeof(t_env))))
		return (1);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, Xrenderdim, Yrenderdim, "mlx 42");
	mlx_key_hook(env->win, deal_key, (void*)0);
	line_draw(env->mlx, env->win, 400, 400, 0, 0, 0xFFFFFF);
	line_draw(env->mlx, env->win, 400, 800, 400, 0, 0xFFFFFF);
	line_draw(env->mlx, env->win, 400, 400, 0, 800, 0xFFFFFF);
	line_draw(env->mlx, env->win, 400, 400, 800, 400, 0xFFFFFF);
	line_draw(env->mlx, env->win, 400, 400, 800, 800, 0xFFFFFF);
	line_draw(env->mlx, env->win, 400, 400, 400, 800, 0xFFFFFF);
	line_draw(env->mlx, env->win, 400, 400, 0, 400, 0xFFFFFF);
	line_draw(env->mlx, env->win, 400, 400, 800, 0, 0xFFFFFF);
	mlx_mouse_hook(env->win, deal_mouse, (void*)0);
	mlx_loop(env->mlx);
}