/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 18:13:19 by avishnev          #+#    #+#             */
/*   Updated: 2018/01/17 18:13:20 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_move(int key, t_map *map)
{
	if (key == 123 || key == 124)
		image_move_abs(map, STEP * 2, key);
	if (key == 126 || key == 125)
		image_move_ord(map, STEP * 2, key);
}

void	fdf_set_projection(t_map *map, int key)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			if (key == 91 || key == 84)
				_MATRIX_ = image_rotation_x(&_MATRIX_, map->mid, STEP, key);
			else if (key == 88 || key == 86)
				_MATRIX_ = image_rotation_y(&_MATRIX_, map->mid, STEP, key);
			else if (key == 85 || key == 83)
				_MATRIX_ = image_rotation_z(&_MATRIX_, map->mid, STEP, key);
			else if (key == 34 || key == 31)
				_MATRIX_ = color_fun(&_MATRIX_, key);
			j++;
		}
		i++;
	}
}

void	key_rot_color(int key, t_map *map)
{
	colour_set(map, key);
	fdf_set_projection(map, key);
	image_colour(map, key);
}

int		key_hold(int key, t_map *map)
{
	cord_mid_cordinate(map);
	if (key == 53)
		exit(1);
	key_rot_color(key, map);
	key_move(key, map);
	key_zoom(key, map);
	fdf_redraw_image(map, key);
	return (0);
}

void	key_zoom(int key, t_map *map)
{
	static size_t i;

	if (key == 69)
	{
		image_zoom_map(map, 1.2);
		i++;
	}
	else if (key == 78 && i > 0)
	{
		image_zoom_map(map, 0.8);
		i--;
	}
}
