/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_zoom_rot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:40:46 by avishnev          #+#    #+#             */
/*   Updated: 2018/01/22 13:40:47 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	image_zoom_map(t_map *map, float zoom)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			_MATRIX_.x = (_MATRIX_.x - _MATRIX_MID_->x)
				* zoom + _MATRIX_MID_->x;
			_MATRIX_.y = (_MATRIX_.y - _MATRIX_MID_->y)
				* zoom + _MATRIX_MID_->y;
			_MATRIX_.z = _MATRIX_.z * zoom;
			j++;
		}
		i++;
	}
}

t_cord	image_rotation_x(t_cord *p, t_cord *mid, int var, int key)
{
	t_cord	tmp;

	p->x -= mid->x;
	p->y -= mid->y;
	tmp.hgz = p->hgz;
	tmp.x = p->x;
	if (key == 91)
	{
		tmp.y = p->y * cos(var * RADIAN) + p->z * sin(var * RADIAN);
		tmp.z = (-(p->y) * sin(var * RADIAN)) + p->z * cos(var * RADIAN);
	}
	else if (key == 84)
	{
		tmp.y = p->y * cos(-var * RADIAN) + p->z * sin(-var * RADIAN);
		tmp.z = (-(p->y) * sin(-var * RADIAN)) + p->z * cos(-var * RADIAN);
	}
	tmp.col = p->col;
	tmp.x += mid->x;
	tmp.y += mid->y;
	return (tmp);
}

t_cord	image_rotation_y(t_cord *p, t_cord *mid, int var, int key)
{
	t_cord	tmp;

	p->x -= mid->x;
	p->y -= mid->y;
	tmp.hgz = p->hgz;
	if (key == 88)
	{
		tmp.x = p->x * cos(var * RADIAN) + p->z * sin(var * RADIAN);
		tmp.z = (-(p->x) * sin(var * RADIAN)) + p->z * cos(var * RADIAN);
	}
	else if (key == 86)
	{
		tmp.x = p->x * cos(-var * RADIAN) + p->z * sin(-var * RADIAN);
		tmp.z = (-(p->x) * sin(-var * RADIAN)) + p->z * cos(-var * RADIAN);
	}
	tmp.y = p->y;
	tmp.col = p->col;
	tmp.x += mid->x;
	tmp.y += mid->y;
	return (tmp);
}

t_cord	image_rotation_z(t_cord *p, t_cord *mid, int var, int key)
{
	t_cord	tmp;

	p->x -= mid->x;
	p->y -= mid->y;
	tmp.hgz = p->hgz;
	if (key == 85)
	{
		tmp.x = p->x * cos(var * RADIAN) - p->y * sin(var * RADIAN);
		tmp.y = p->x * sin(var * RADIAN) + p->y * cos(var * RADIAN);
	}
	else if (key == 83)
	{
		tmp.x = p->x * cos(-var * RADIAN) - p->y * sin(-var * RADIAN);
		tmp.y = p->x * sin(-var * RADIAN) + p->y * cos(-var * RADIAN);
	}
	tmp.z = p->z;
	tmp.col = p->col;
	tmp.x += mid->x;
	tmp.y += mid->y;
	return (tmp);
}
