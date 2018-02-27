/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:18:14 by avishnev          #+#    #+#             */
/*   Updated: 2018/01/17 16:18:15 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	image_move_abs(t_map *map, int step, int key)
{
	size_t	i;
	size_t	j;

	step *= (key == 124) ? 1 : -1;
	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			_MATRIX_.x += step;
			j++;
		}
		i++;
	}
}

void	image_move_ord(t_map *map, int step, int key)
{
	size_t	i;
	size_t	j;

	step *= (key == 125) ? 1 : -1;
	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			_MATRIX_.y += step;
			j++;
		}
		i++;
	}
}

void	image_move_mid(t_map *map)
{
	size_t	i;
	size_t	j;

	j = HG / 2 - _MATRIX_MID_->y;
	i = WD / 2 - _MATRIX_MID_->x;
	image_move_abs(map, j, 124);
	image_move_ord(map, i, 125);
}
