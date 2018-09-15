/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 14:03:54 by asamir-k          #+#    #+#             */
/*   Updated: 2018/09/12 16:24:51 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "mlx.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;
	i = 0;

	while(str[i])
		ft_putchar(str[i++]);
}
int		deal_key(int key, void *param)
{
	ft_putstr("keyinput");
	return (0);
}

void	line_draw(void *mlx_ptr,void *win_ptr, int x1,int y1, int x2, int y2, int color)
{
	int x,y,dx,dy,swap,temp,s1,s2,p,i;

	x = x1;
	y = y1;
	dx = x2 - x1;
	dy = y2 - y1;
	s1 = dx;
	s2 = dy;
	swap = 0;
	if(dy > dx)
	{
		temp = dx;
		dx = dy;
		dy= temp;
		swap = 1;
	}
	p = 2 * dy - dx;
	i = 0;
	while(i < dx)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x,y, 0xFFFFFF);
		while(p >= 0)
		{
			p = p - 2 * dx;
			if(swap)
				x += s1;
			else
				y += s2;
		}
		p = p + 2 * dy;
		if(swap)
			y += s2;
		else
			x += s1;
	i++;
	}
mlx_pixel_put(mlx_ptr,win_ptr, x, y, 0xFFFFFF);
}
int		deal_mouse(int button, void *param)
{
	ft_putstr("mouseinput");
	return (0);
}

int		main(void)
{

	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 2000, 2000, "mlx 42");
	mlx_key_hook(win_ptr, deal_key, (void*)0);
	line_draw(mlx_ptr, win_ptr, 500, 500, 0, 0, 0xFFFFFF);
	line_draw(mlx_ptr, win_ptr, 100, 500, 100, 0, 0xFFFFFF);
	line_draw(mlx_ptr, win_ptr, 100, 100, 0, 200, 0xFFFFFF);
	line_draw(mlx_ptr, win_ptr, 100, 100, 200, 100, 0xFFFFFF);
	line_draw(mlx_ptr, win_ptr, 100, 100, 200, 200, 0xFFFFFF);
	line_draw(mlx_ptr, win_ptr, 100, 100, 100, 200, 0xFFFFFF);
	line_draw(mlx_ptr, win_ptr, 100, 100, 0, 100, 0xFFFFFF);
	line_draw(mlx_ptr, win_ptr, 100, 100, 0, 200, 0xFFFFFF);
	mlx_mouse_hook(win_ptr, deal_mouse, (void*)0);
	mlx_loop(mlx_ptr);
}

/*	int		dx;
	int		dy;
	int		p;
	int		x;
	int		y;
	int		temp;

	dx = x1 - x0;
	dy = y1 - y0;

	x = x0;
	y = y0;


	if (dy > dx)
	{
	temp = dx;
	dx = dy;
	dy = temp;
	}
	p = 2 * dy - dx;
	while(x < x1)
	{
	if(p >= 0)
	{
	mlx_pixel_put(mlx_ptr, win_ptr,x,y,0xFFFFFF);
	y++;
	p = p + 2 * dy - 2 * dx;
	}
	else
	{
	mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0xFFFFFF);
	p = p + 2 * dy;
	}
	x++;
	}*/
