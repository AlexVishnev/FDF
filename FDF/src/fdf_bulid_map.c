/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_build_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:40:57 by avishnev          #+#    #+#             */
/*   Updated: 2018/01/17 18:34:39 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	colour_set(t_map *map, int key)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			if (key == 35 || key == 37 || key == 40)
				_MATRIX_ = color_flick(&_MATRIX_, key, i, j);
			j++;
		}
		i++;
	}
}

t_map	*map_alloc(size_t x, size_t y)
{
	t_map		*map;
	size_t		i;

	i = 0;
	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->x = x;
	map->y = y;
	map->tab = (t_cord **)ft_memalloc(sizeof(t_cord *) * x);
	while (i < x)
	{
		map->tab[i] = (t_cord*)ft_memalloc(sizeof(t_cord) * y);
		i++;
	}
	map->mid = (t_cord *)ft_memalloc(sizeof(t_cord));
	return (map);
}

t_map	*create_map(char **field, size_t x, size_t y)
{
	t_map		*map;
	size_t		i;
	size_t		j;
	char		**buff;

	i = 0;
	map = map_alloc(x, y);
	while (i < x)
	{
		j = 0;
		buff = ft_split_arr(field[i], ' ');
		free(field[i]);
		while (j < y)
		{
			_MATRIX_ = cord_new_cordinate(buff[j], i, j);
			free(buff[j]);
			j++;
		}
		free(buff);
		i++;
	}
	return (map);
}
