/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 17:40:57 by avishnev          #+#    #+#             */
/*   Updated: 2018/01/16 17:25:11 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map			*map_alloc(int x, int y)
{
	t_map	*map;
	int		i;

	i = 0;
	map = (t_map *)malloc(sizeof(t_map));
	map->x = x;
	map->y = y;
	map->tab = (t_cord **)malloc(sizeof(t_cord *) * x);
	while (y > i)
	{
		map->tab[i] = (t_cord*)malloc(sizeof(t_cord *) * y);
		i++;
	}
	return (map);
}

char			**split_arr(char *str)
{
	char	**s;

	s = ft_strsplit(str, ' ');
	return (s);
}

t_map			*create_map(char **tab, int x, int y)
{
	t_map	*map;
	int		i;
	int		j;
	char	**buff;

	i = 0;
	map = map_alloc(x, y);
	while (i < x)
	{
		j = 0;
		buff = split_arr(tab[i]);
		while (j < y)
		{
			map->tab[i][j] = new_cord(i, j, buff[i]);
			j++;
		}
		i++;
	}
	return (map);
}
