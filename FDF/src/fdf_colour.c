/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colour.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 14:20:21 by avishnev          #+#    #+#             */
/*   Updated: 2018/02/27 14:20:22 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		norminettte_func(t_hgcol sort, t_cord cord)
{
	if (cord.hgz <= (sort.mid_hg + 2))
		cord.col = GREEN;
}

void			image_colour(t_map *map, int key)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			if (key == 8 || key == 9)
				_MATRIX_ = cord_new_cord_colour(map, _MATRIX_, key);
			j++;
		}
		i++;
	}
}

t_cord			cord_new_cord_colour(t_map *map, t_cord cord, int key)
{
	t_hgcol		sort;

	sort.flag = 1;
	if (map->x < 200)
		sort = sorting(map, sort);
	sort.flag++;
	if (key == 9)
		cord.col = ft_atoi_base(WHITE, 16);
	else if (key == 8)
	{
		if (cord.hgz == sort.min_hg)
		{
			cord.col = BLUE;
			if (cord.hgz < 0 || cord.hgz == sort.min_hg)
				cord.col = BLUE;
		}
		if (cord.hgz > sort.min_hg)
			norminettte_func(sort, cord);
		if (cord.hgz == sort.max_hg)
			cord.col = BROWN;
		if (cord.hgz > sort.max_hg - sort.mid_hg)
			cord.col = BROWN;
	}
	return (cord);
}

t_hgcol			sorting(t_map *map, t_hgcol p)
{
	size_t	i;
	size_t	j;

	p.max_hg = map->tab[0][0].hgz;
	p.min_hg = map->tab[0][0].hgz;
	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			if (_MATRIX_.hgz > p.max_hg)
				p.max_hg = _MATRIX_.hgz;
			else
			{
				if (p.min_hg > _MATRIX_.hgz)
					p.min_hg = _MATRIX_.hgz;
			}
			j++;
		}
		i++;
	}
	p.mid_hg = (p.max_hg - p.min_hg) / 2;
	return (p);
}

t_cord			color_fun(t_cord *p, int key)
{
	t_cord	tmp;

	tmp.x = p->x;
	tmp.y = p->y;
	tmp.z = p->z;
	tmp.hgz = p->hgz;
	if (key == 34)
	{
		if (tmp.col > 0)
			tmp.col = (p->col + ((p->col - (p->col >> 4))));
		if (tmp.col <= 2)
			tmp.col = 0xFFFFFFFFFFFFFFFF;
	}
	else if (key == 31)
	{
		if (tmp.col > 0)
			tmp.col = sqrt(p->col + (p->col - (p->col >> 4)));
		if (tmp.col <= 2)
			tmp.col = 0xFFFFFFFFFFFFFFFF;
	}
	return (tmp);
}
