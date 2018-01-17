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
	char	*color;

	color = "0xFFFFFF";
	if (!(a = ft_strchr(s, ',')))
		return (color);
	return (++a);
}

t_cord			new_cord(int x, int y, char *s)
{
	t_cord	c;

	c.col = ft_atoi_base(kostyl(s), 16);
	c.z = ft_atoi(s);
	c.x = x;
	c.y = y;
	return (c);
}
