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
t_cord	zoom_image(t_cord *p, t_cord *mid, int var)
{
	t_cord	tmp;
	float	radian;

	p->x -= mid->x;
	p->y -= mid->y;
	radian = var * 3.14159265359 / 180;
	tmp.x = p->x;
	tmp.y = p->y;
	tmp.z = p->z ;
	printf("tmp.hgz[[%d]]\n", tmp.hgz );
	if (tmp.col > 0)
		tmp.col = p->col - (p->col >> 1);
	if (tmp.col <= 1)
		tmp.col = 16777182;
	printf("%d\n", tmp.col );
	tmp.x += mid->x;
	tmp.y += mid->y;
	return (tmp);

}

t_cord	rot_x(t_cord *p, t_cord *mid, int var)
{
	t_cord	tmp;
	float	radian;

	p->x -= mid->x;
	p->y -= mid->y;
	radian = var * 3.14159265359 / 180;
	tmp.x = p->x;
	tmp.y = p->y * cos(RADIAN) + p->z * sin(RADIAN);
	tmp.z = (-(p->y) * sin(RADIAN)) + p->z * cos(RADIAN);
	tmp.col = p->col;
	tmp.x += mid->x;
	tmp.y += mid->y;
	return (tmp);
}

t_cord	rot_y(t_cord *p, t_cord *mid, int var)
{
	t_cord	tmp;
	float	radian;

	p->x -= mid->x;
	p->y -= mid->y;
	radian = var * 3.14159265359 / 180;
	tmp.x = p->x * cos(RADIAN) + p->z * sin(RADIAN);
	tmp.y = p->y;
	tmp.z = (-(p->x) * sin(RADIAN)) + p->z * cos(RADIAN);
	tmp.col = p->col;
	tmp.x += mid->x;
	tmp.y += mid->y;
	return (tmp);
}

t_cord	rot_z(t_cord *p, t_cord *mid, int var)
{
	t_cord	tmp;
	float	radian;

	p->x -= mid->x;
	p->y -= mid->y;
	radian = var * 3.14159265359 / 180;
	tmp.x = p->x * cos(RADIAN) - p->y * sin(RADIAN);
	tmp.y = p->x * sin(RADIAN) + p->y * cos(RADIAN);
	tmp.z = p->z;
	tmp.col = p->col;
	tmp.x += mid->x;
	tmp.y += mid->y;
	return (tmp);
}

