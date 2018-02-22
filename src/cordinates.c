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

t_cord			new_cord(char *s, int x, int y)
{
	t_cord	cord;

	cord.x = x;
	cord.y = y;
	cord.z = ft_atoi(s);
	if (!cord.hgz)
		cord.hgz = ft_atoi(s);
	printf("color cord = [%d]\n", cord.hgz );
	cord.col = ft_atoi_base(kostyl(s), 16);
	return (cord);
}

t_cord			new_cord_colour(t_cord cord)
{
	if (cord.hgz < 0)
	{
		cord.col = ft_atoi_base(BLUE, 16);
		if (cord.hgz < -2)
			cord.col = cord.col << 2;
	}
	if (cord.hgz >= 0)
	{	
	 	if (cord.hgz <= 3)
			cord.col = ft_atoi_base(GREEN, 16);
	 	if (cord.hgz < 5 && cord.hgz > 3)
	 		cord.col = ft_atoi_base(BROWN, 16);
	 	if (cord.hgz >= 5)
	 		cord.col = ft_atoi_base(WHITE, 16);
	}
	return (cord);
}

void			mid_cord(t_map *map)
{
	int	ln_x;
	int	ln_y;

	if (!(map->mid = (t_cord *)malloc(sizeof(t_cord))))
		return ;
	ft_bzero(map->mid, (sizeof(t_cord)));
	ln_x = map->x -1;
	ln_y = map->y -1;

	map->mid->x = (map->tab[ln_x][ln_y].x + map->tab[0][0].x)/ 2;
	map->mid->y = (map->tab[ln_x][ln_y].y + map->tab[0][0].y)/ 2;
}
