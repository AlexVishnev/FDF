/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cordinates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:57:41 by avishnev          #+#    #+#             */
/*   Updated: 2018/01/17 13:57:42 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	char	*kostyl(char *s)
{
	char	*colour;

	if (!(colour = ft_strchr(s, ',')))
		return (WHITE);
	return (++colour);
}

t_cord			cord_new_cord(char *s, int x, int y)
{
	t_cord	cord;

	cord.x = x;
	cord.y = y;
	cord.z = ft_atoi(s);
	cord.hgz = ft_atoi(s);
	cord.col = ft_atoi_base(kostyl(s), 16);
	return (cord);
}

t_hgcol		sorting(t_map *map, t_hgcol p)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y - 1)
		{
			if (map->tab[i][j].hgz > map->tab[i][j + 1].hgz)
				p.max_hg = map->tab[i][j].hgz;
			else if (map->tab[i][j].hgz < map->tab[i][j + 1].hgz)
				p.min_hg = map->tab[i][j].hgz;
			j++;
		}
		i++;
	}
	p.mid_hg = (p.max_hg - p.min_hg) / 2;
	return (p);
}

t_cord			image_new_cord_colour(t_map *map, t_cord cord, int key)
{
	t_hgcol		sort;

	sort.max_hg = 0;
	sort.mid_hg = 0;
	sort.min_hg = 0;
	sort = sorting(map, sort);
	if (key == 7)
		cord.col = ft_atoi_base(WHITE, 16);
	else if (key == 8)
	{
		if (cord.hgz == sort.min_hg)
		{
			cord.col = GREEN;
			if (cord.hgz < -2)
				cord.col = BLUE << 2;
		}
		if (cord.hgz > sort.min_hg)
		{
			if (cord.hgz <= sort.mid_hg - 1)
				cord.col = GREEN;
			if (cord.hgz >= sort.mid_hg - 2 && cord.hgz <= sort.mid_hg + 2)
				cord.col = BROWN;
			if (cord.hgz <= sort.max_hg && cord.hgz >= sort.max_hg - 2)
				cord.col = ft_atoi_base(WHITE, 16);
		}
	}
	return (cord);
}

void			cord_mid_cord(t_map *map)
{
	int	ln_x;
	int	ln_y;

	if (!(map->mid = (t_cord *)malloc(sizeof(t_cord))))
		return ;
	ft_bzero(map->mid, (sizeof(t_cord)));
	ln_x = map->x - 1;
	ln_y = map->y - 1;
	map->mid->x = (map->tab[ln_x][ln_y].x + map->tab[0][0].x) / 2;
	map->mid->y = (map->tab[ln_x][ln_y].y + map->tab[0][0].y) / 2;
}
