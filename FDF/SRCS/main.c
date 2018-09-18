/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/15 16:50:42 by asamir-k          #+#    #+#             */
/*   Updated: 2018/09/18 16:56:16 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../INCLUDES/fdf.h"

int		main(void)
{
	t_env *env;

	if (!(env = ft_memalloc(sizeof(t_env))))
		return (1);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, Xenvdim, Yenvdim, "mlx 42");
	mlx_key_hook(env->win, key_manager, (void*)0);
	mlx_mouse_hook(env->win, mouse_manager, (void*)0);
	line_drawer(env, 400, 400, 0, 0, PINK);
	line_drawer(env, 400, 800, 400, 0, CYAN);
	line_drawer(env, 400, 400, 0, 800, YELLOW);
	line_drawer(env, 400, 400, 800, 400, WHITE);
	line_drawer(env, 400, 400, 800, 800, RED);
	line_drawer(env, 400, 400, 400, 800, PURPLE);
	line_drawer(env, 400, 400, 0, 400, ORANGE);
	line_drawer(env, 400, 400, 800, 0, GREEN);
	mlx_loop(env->mlx);
}
