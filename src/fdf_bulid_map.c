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

t_map			*map_alloc(size_t x, size_t y)
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

t_map			*create_map(char **field, size_t x, size_t y)
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
