/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:18:14 by avishnev          #+#    #+#             */
/*   Updated: 2018/01/17 16:18:15 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move_abs(t_map *map, int step)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			map->tab[i][j].x = map->tab[i][j].x + step;
	//		map->tab[i][j].y = map->tab[i][j].y;
	//		map->tab[i][j].z = map->tab[i][j].z;
			j++;
		}
		i++;
	}
}

void	move_ord(t_map *map, int step)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
		//	map->tab[i][j].x = map->tab[i][j].x;
			map->tab[i][j].y = map->tab[i][j].y + step;
		//	map->tab[i][j].z = map->tab[i][j].z;
			j++;
		}
		i++;
	}
}

void	move_mid(t_map *map)
{
	size_t	i;
	size_t	j;

	j = HG / 2 - map->mid->y;
	i = WD / 2 - map->mid->x;
	move_abs(map, j);
	move_ord(map, i); 
}
