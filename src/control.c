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
	fdf_redraw_image(map, 0);
	return (0);
}

void	key_move(int key, t_map *map)
{
	if (key == 123 || key == 124)
		image_move_abs(map, STEP, key);
	if (key == 126 || key == 125)
		image_move_ord(map, STEP, key);
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
				MATRIX_ = image_rotation_x(&MATRIX_, map->mid, 2, key);
			else if (key == 88 || key == 86)
				MATRIX_ = image_rotation_y(&MATRIX_, map->mid, 2, key);
			else if (key == 85 || key == 83)
				MATRIX_ = image_rotation_z(&MATRIX_, map->mid, 2, key);
			else if (key == 34 || key == 31)
				MATRIX_ = fdf_color_fun(&MATRIX_, key);
			j++;
		}
		i++;
	}
}

void	image_colour(t_map *map, int key)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			if (key == 8)
				MATRIX_ = image_new_cord_colour(MATRIX_, key);
			j++;
		}
		i++;
	}
}

void	key_rot_color(int key, t_map *map)
{
	fdf_set_projection(map, key);
	image_colour(map, key);
}

int		key_hold(int key, t_map *map)
{
	cord_mid_cord(map);
	if (key == 53)
	{
		free_data(map);
		mlx_destroy_image(map->mlx, map->win);
		mlx_clear_window(map->mlx, map->win);
		system("leaks -q fdf");
		exit(1);
	}
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
		zoom_map(map, 1.5);
		i++;
	}
	else if (key == 78 && i > 0)
	{
		zoom_map(map, 0.5);
		i--;
	}
}
