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

int		size_fill(char *field)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open(field, O_RDONLY);
	while (ft_getline(fd, &str) > 0)
	{
		ft_memdel((void **)&str);
		i++;
	}
	ft_memdel((void **)&str);
	close(fd);
	return (i);
}

char 	**read_file(char *field)
{
	char	**buff;
	int		fd;
	int		size;
	int		i;

	size = size_fill(field);
	i = 0;
	fd = open(field, O_RDONLY);
	if (read(fd, field, 0) < 0)
		error_imput();
	if (!(buff = (char**)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	while (ft_getline(fd, &buff[i]))
		i++;
	buff[i] = NULL;
	close(fd);
	valide(buff);
	return (buff);
}

static void free_tab(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			MATRIX_.x = 0;
			MATRIX_.y = 0;
			MATRIX_.z = 0;
			MATRIX_.col = 0;
			j++;
		}
		i++;
	}
}

void	free_data(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			free_tab(map);
			j++; 
		}
		i++;
	}
}



