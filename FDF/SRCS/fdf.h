/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <asamir-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 12:27:56 by asamir-k          #+#    #+#             */
/*   Updated: 2018/09/17 17:02:42 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
#define FDF_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../INCLUDES/libft/libft.h"
#include "mlx.h"
# define sign(x) ((x > 0) ? 1 :((x < 0)? -1:0))
int		main(void);
void	line_draw(void *mlx_ptr,void *win_ptr, int x1,int y1, int x2, int y2, int color);
int     deal_key(int key, void *param);
int     deal_mouse(int button, void *param);
#endif
