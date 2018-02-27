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

t_cord			cord_new_cordinate(char *s, int x, int y)
{
	t_cord	cord;

	cord.x = x;
	cord.y = y;
	cord.z = ft_atoi(s);
	cord.hgz = ft_atoi(s);
	cord.col = ft_atoi_base(kostyl(s), 16);
	return (cord);
}

void			cord_mid_cordinate(t_map *map)
{
	int	ln_x;
	int	ln_y;

	ln_x = map->x - 1;
	ln_y = map->y - 1;
	map->mid->x = (map->tab[ln_x][ln_y].x + map->tab[0][0].x) / 2;
	map->mid->y = (map->tab[ln_x][ln_y].y + map->tab[0][0].y) / 2;
}
