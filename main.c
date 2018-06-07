/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 11:16:20 by asamir-k          #+#    #+#             */
/*   Updated: 2018/06/07 11:16:22 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char*line;

	line = NULL;
	fd = open(av[ac -1], O_RDONLY);
	while ((ret = get_next_line(fd, &line) > 0))
	{
		ft_putstr(line);
		ft_putstr("\033[32;1m|---> \033[0m");
		ft_putstr("\033[35;1m");
		ft_putnbr(ret);
		ft_putstr("\033[0m");
		ft_putstr("\n");
	}
	ft_putstr("\n\n");
	ft_putstr("\033[31;1mFINAL RET = [\033[0m");
	ft_putstr("\033[35;1m");
	ft_putnbr(ret);
	ft_putstr("\033[0m");
	ft_putstr("\033[31;1m]\n\n\033[0m");
	return (0);
}
