/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rfile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:26:20 by avishnev          #+#    #+#             */
/*   Updated: 2018/01/11 15:42:35 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t		size_fill(char *s)
{
	int		fd;
	char	*line;
	size_t	i;

	i = 0;
	fd = open(s, O_RDONLY);
	while (ft_next_line(fd, &line) > 0)
		i++;
	close(fd);
	free(line);
	return (i);
}

char 	**rfile(char *s)
{
	char	**buff;
	int		fd;
	char	*line;
	size_t	size;
	size_t	i;

	size = size_fill(s);
	i = 0;
	fd = open(s, O_RDONLY);
	buff = (char**)malloc(sizeof(char*) * size + 1);
	while (ft_next_line(fd, &line) > 0)
	{
		buff[i] = ft_strdup(line);
		i++;
	}
	buff[i] = NULL;
	close(fd);
	valide(buff);
	return (buff);
}
