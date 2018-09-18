/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 12:27:56 by asamir-k          #+#    #+#             */
/*   Updated: 2018/09/18 18:22:15 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "mlx.h"

# define Yenvdim 801
# define Xenvdim 801

/*
** Colors HEXDECIMAL :
*/
# define PINK       0xFD2BE6
# define BLUE       0x0012FD
# define RED        0xFD0000
# define CYAN       0x00F3FD
# define YELLOW     0xFDF800
# define GREEN      0x05FD00
# define BROWN      0x8C4629
# define ORANGE     0xF87C00
# define WHITE      0xFFFFFF
# define BLACK      0x000000
# define PURPLE     0x7400AC
# define GREY       0x9A9A9A

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
    int     swap;
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

int     signdetector(int x);
int		main(void);
void	line_drawer(void *mlx, void *win, int x1, int y1, int x2, int y2, int color);
int     key_manager(int key, void *param);
int     mouse_manager(int button, void *param);

#endif
