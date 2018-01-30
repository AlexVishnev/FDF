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
	char	*a;

	if (!(a = ft_strchr(s, ',')))
		return ("0xFFFFFF");
	return (++a);
}

t_cord			new_cord(char *s, int x, int y)
{
	t_cord	c;

	c.x = x;
	c.y = y;
	c.z = ft_atoi(s);
	c.col = ft_atoi_base(kostyl(s), 16);
	return (c);
}

void			mid_cord(t_map *map)
{
	int	ln_x;
	int	ln_y;

	// if(!(map->mid = (t_cord *)malloc(sizeof(t_cord))))
	// 	return ;
	ln_x = map->x - 1;
	ln_y = map->y - 1;
	map->mid = (t_cord *)malloc(sizeof(t_cord));
	map->mid->x = (map->tab[ln_x][ln_y].x + map->tab[0][0].x)/ 2;
	map->mid->y = (map->tab[ln_x][ln_y].y + map->tab[0][0].y)/ 2;
}
