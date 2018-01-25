/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_map.c                                            :+:      :+:    :+:   */
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
	t_map	*map;
	size_t		i;

	i = 0;
	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	map->x = x;
	map->y = y;
	map->tab = (t_cord **)malloc(sizeof(t_cord *) * x);
	while (i < x)
	{
		map->tab[i] = (t_cord*)malloc(sizeof(t_cord) * y);
		i++;
	}
	return (map);
}

t_map			*create_map(char **tab, size_t x, size_t y)
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
		buff = ft_split_arr(tab[i], ' ');
		while (j < y)
		{
			map->tab[i][j] = new_cord(buff[j], i, j);
			j++;
		}
		i++;
	}
	return (map);
}

