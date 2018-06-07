/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asamir-k <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:26:05 by asamir-k          #+#    #+#             */
/*   Updated: 2018/06/07 17:33:51 by asamir-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int			reid;
	int			len;
	char		readance[BUFF_SIZE + 1];
	static char	*str;

	len = 0;
	if (line == NULL || fd < 0 || fd > 10240 || BUFF_SIZE < 1)
		return (-1);
	if (str == NULL)
		if ((str = ft_strnew(0)) == NULL)
			return (-1);
	while (ft_strchr(str, '\n') == NULL && 
			(reid = read(fd, readance, BUFF_SIZE)) > 0)
	{
		readance[reid] = '\0';
		if ((str = ft_strjoin(str, readance)) == NULL)
			return (0);
	}
	if (reid == -1)
		return (-1);
	while (str[len] && str[len] != '\n')
		len++;
	*line = ft_strsub(str, 0, len);
	reid = ft_strlen(str);
	str = &str[len + 1];
	return (reid == 0) ? 0 : 1;
}
