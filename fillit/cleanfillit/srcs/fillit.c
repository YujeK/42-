/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghtouman <ghtouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 11:09:12 by ghtouman          #+#    #+#             */
/*   Updated: 2018/05/17 18:20:34 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void		ft_control(t_stock ma_list, t_struct *ma_struct)
{
	ma_struct->map = NULL;
	if (check_error(&ma_list) == FALSE)
		return ;
	ma_struct->base_grid = ft_sqrt(ma_struct->tetri_number * 4);
	tab_map(ma_struct);
	ft_get_coord(&ma_list, -1, 0, 0);
	ft_zaap(&ma_list);
	ft_height(&ma_list);
	ft_solve(&ma_list, ma_struct);
	while (*ma_struct->map)
		ft_putstr(*ma_struct->map++);
}

static	void		ft_read(const char *name)
{
	int				ret;
	int				fd;
	char			*buf;
	t_stock			*ma_list;
	t_struct		ma_struct;

	fd = open(name, O_RDONLY);
	ma_list = NULL;
	ma_struct.tetri_number = 0;
	buf = ft_strnew(21);
	if (fd != -1)
	{
		while ((ret = read(fd, buf, 21)))
		{
			buf[ret] = '\0';
			ft_lstpush_back(&ma_list, ft_strdup(buf), ma_struct.tetri_number++);
		}
	}
	close(fd);
	if (ma_struct.tetri_number == 0 || ma_struct.tetri_number > 26)
	{
		ft_putstr("error\n");
		return ;
	}
	ft_control(*ma_list, &ma_struct);
}

int					main(int argc, char const *argv[])
{
	if (argc != 2)
		ft_putstr("Un fichier a la fois");
	else
		ft_read(argv[1]);
	return (0);
}
