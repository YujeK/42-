/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 11:11:29 by ghtouman          #+#    #+#             */
/*   Updated: 2018/05/16 17:54:58 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdio.h>
# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# define FALSE 0
# define TRUE 1

typedef struct		s_struct
{
	int				base_grid;
	int				tetri_number;
	char			**map;
}					t_struct;

typedef struct		s_stock
{
	char			*content;
	int				number_list;
	int				tobx[4];
	int				toby[4];
	int				height;
	struct s_stock	*next;
}					t_stock;

void				ft_lstpush_back(t_stock **begin_list,
					char *content, int number);
void				ft_zaap(t_stock *ma_list);
void				ft_get_coord(t_stock *ma_list, int i, int x, int y);
void				ft_height(t_stock *ma_list);
void				free_tab(t_struct *ma_struct);

int					check_error(t_stock *ma_list);
int					placement(t_stock *ma_list,
					t_struct *ma_struct, int y, int x);

char				**tab_map(t_struct *ma_struct);
char				**ft_solve(t_stock *ma_list, t_struct *ma_struct);

t_stock				*ft_create_elem(void *content);

#endif
