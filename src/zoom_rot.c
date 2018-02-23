/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:40:46 by avishnev          #+#    #+#             */
/*   Updated: 2018/01/22 13:40:47 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_map(t_map *map, float zoom)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			MATRIX_.x = (MATRIX_.x - MATRIX_MID_->x)
			 	* zoom + MATRIX_MID_->x;
			MATRIX_.y = (MATRIX_.y - MATRIX_MID_->y) 
				* zoom + MATRIX_MID_->y;
			MATRIX_.z = MATRIX_.z * zoom;
			j++;
		}
		i++;
	} 
}

t_cord	fdf_color_fun(t_cord *p, int key)
{
	t_cord	tmp;

	tmp.x = p->x;
	tmp.y = p->y;
	tmp.z = p->z;
	tmp.hgz = p->hgz;
	printf("tmp.hgz = [%d]\n", tmp.hgz);
	if (key == 34)
	{	
		if (tmp.col > 0)
			tmp.col = (p->col +((p->col - (p->col >> 8))));
		if (tmp.col <= 2)
			tmp.col = 0xFFFFFFFFFFFFFFFF;
	}
	else if (key == 31)
	{
		if (tmp.col > 0)
			tmp.col = sqrt(p->col + (p->col - (p->col >> 8)));
		if (tmp.col <= 2)
			tmp.col = 0xFFFFFFFFFFFFFFFF;

	}
	return (tmp);
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
