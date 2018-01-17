/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 13:53:08 by avishnev          #+#    #+#             */
/*   Updated: 2018/01/17 13:53:11 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_ln(t_map *map, t_cord x1, t_cord x2)
{
	t_line ln;

	ln = line_param(x1, x2);
	while (9)
	{
		make_pxl(ln, &(map->img));
		if (ln.x1 == ln.x2 && ln.y1 == ln.y2)
			break ;
		ln.err2 = ln.err * 2;
		if (ln.dx > ln.err2)
		{
			ln.err += ln.dx;
			ln.y1 += ln.sy;
		}
		if (ln.dy < ln.err2)
		{
			ln.err += ln.dx;
			ln.y1 += ln.sy;
		}
	}
}

t_line	line_param(t_cord c_1 , t_cord c_2)
{
	t_line ln;

	ln.x1 = c_1.x;
	ln.x2 = c_2.x;
	ln.y1 = c_1.y;
	ln.y2 = c_2.y;
	ln.dx = abs(ln.x2 - ln.x1);
	ln.dy = -abs(ln.y2 - ln.y1);
	ln.sx = ln.x1 < ln.x2 ? 1 : -1;
	ln.sy = ln.y1 < ln.y2 ? 1 : -1;
	ln.err = ln.dx + ln.dy;
	ln.clr = c_2.col;
	return (ln);
}
