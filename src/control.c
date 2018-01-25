/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:13:19 by avishnev          #+#    #+#             */
/*   Updated: 2018/01/17 18:13:20 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		redr_f(t_map *map)
{
	redraw(map);
	return (0);
}

void	key_move(int key, t_map *map)
{
	if (key == 123)
		move_abs(map, -STEP);
	if (key == 124) 
		move_abs(map, STEP);
	if (key == 126)
		move_ord(map, -STEP);
	if (key == 125)
		move_ord(map, STEP);
}

void	rotate(t_map *map, int key)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			if (key == 10)
				map->tab[i][j] = rot_x(&map->tab[i][j], map->mid, 10);
			else if (key == 12)
				map->tab[i][j] = rot_x(&map->tab[i][j], map->mid, -10);
			else if (key == 13)
				map->tab[i][j] = rot_y(&map->tab[i][j], map->mid, 10);
			else if (key == 14)
				map->tab[i][j] = rot_y(&map->tab[i][j], map->mid, -10);
			else if (key == 15)
				map->tab[i][j] = rot_z(&map->tab[i][j], map->mid, 10);
			else if (key == 16)
				map->tab[i][j] = rot_z(&map->tab[i][j], map->mid, -10);
			j++;
		}
		i++;
	}
}

void	key_rot(int key, t_map *map)
{
	rotate(map, key);
}

int		key_hold(int key, t_map *map)
{
	mid_cord(map);
	if (key == 53)
	{
		mlx_destroy_image(map->mlx, map->img.point);
		exit(0);
	}
	key_rot(key, map);
	key_move(key, map);
	key_zoom(key, map);
	redraw(map);
	return (0);
}

void	key_zoom(int key, t_map *map)
{
	static size_t	i;

	if (key == 69)
	{
		zoom_map(map, 2);
		i++;
	}
	else if (key == 78 && i > 0)
	{
		zoom_map(map, 0.5);
		i--;
	}
}