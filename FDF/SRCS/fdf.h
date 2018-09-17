/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 12:27:56 by asamir-k          #+#    #+#             */
/*   Updated: 2018/09/17 18:56:44 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../INCLUDES/libft/libft.h"
#include "mlx.h"

# define Yrenderdim 800
# define Xrenderdim 800

int     signdetector(int x);
int		main(void);
void	line_draw(void *mlx_ptr,void *win_ptr, int x1,int y1, int x2, int y2, int color);
int     deal_key(int key, void *param);
int     deal_mouse(int button, void *param);
#endif

typedef struct      s_env
{
    void    *mlx;
    void    *win;
    int     dx;
    int     dy;
    int     x;
    int     y;
    int     x1;
    int     x2;
    int     y1;
    int     y2;
}                   t_env;

typedef struct      s_line
{
    int     x;
    int     y;
    int     d;
    int     x1;
    int     y1;
    int     x2;
    int     y2;
    int     dx;
    int     dy;
    int     s1;
    int     s2;
    int     color;
}                   t_line;