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

void	zoom_map(t_map *map, double zoom)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			map->tab[i][j].x = (map->tab[i][j].x - map->mid->x)
			 	* zoom + map->mid->x;
			map->tab[i][j].y = (map->tab[i][j].y - map->mid->y) 
				* zoom + map->mid->y;
			map->tab[i][j].z = map->tab[i][j].z * zoom;
			j++;
		}
		i++;
	} 
}

t_cord	rot_x(t_cord *p, t_cord *mid, int var)
{
	t_cord	tmp;
	double	corner;

	p->x -= mid->x;
	p->y -= mid->y;
	corner = var * 3.14159 / 180;
	tmp.x = p->x;
	tmp.y = p->y * cos(corner) + p->z * sin(corner);
	tmp.z = (-(p->y) * sin(corner)) + p->z * cos(corner);
	tmp.col = p->col;
	tmp.x += mid->x;
	tmp.y += mid->y;
	return (tmp);
}

t_cord	rot_y(t_cord *p, t_cord *mid, int var)
{
	t_cord	tmp;
	double	corner;

	p->x -= mid->x;
	p->y -= mid->y;
	corner = var * 3.14159 / 180;
	tmp.x = p->x * cos(corner) + p->z * sin(corner);
	tmp.y = p->y;
	tmp.z = (-(p->x) * sin(corner)) + p->z * cos(corner);
	tmp.col = p->col;
	tmp.x += mid->x;
	tmp.y += mid->y;
	return (tmp);
}

t_cord	rot_z(t_cord *p, t_cord *mid, int var)
{
	t_cord	tmp;
	double	corner;

	p->x -= mid->x;
	p->y -= mid->y;
	corner = var * 3.14159 / 180;
	tmp.x = p->x * cos(corner) - p->y * sin(corner);
	tmp.y = p->x * sin(corner) + p->y * cos(corner);
	tmp.z = p->z;
	tmp.col = p->col;
	tmp.x += mid->x;
	tmp.y += mid->y;
	return (tmp);
}

