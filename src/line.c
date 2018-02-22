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

void	draw_ln(t_map *map, t_cord cordinate1, t_cord cordinate2)
{
	t_line line;

	line = line_param(cordinate1, cordinate2);
	while (1)
	{
		make_pxl(line, &(map->img));
		if (line.x1 == line.x2 && line.y1 == line.y2)
			break ;
		line.err2 = line.err * 2;
		if (line.dy < line.err2)
		{
			line.err += line.dy;
			line.x1 += line.sx;
		}
		if (line.dx > line.err2)
		{
			line.err += line.dx;
			line.y1 += line.sy;
		}
	}
}

t_line	line_param(t_cord x_1 , t_cord x_2)
{
	t_line line;

	line.x1 = x_1.x;
	line.y1 = x_1.y;
	line.x2 = x_2.x;
	line.y2 = x_2.y;
	line.dx = abs(line.x2 - line.x1);
	line.dy = -abs(line.y2 - line.y1);
	line.sx = line.x1 < line.x2 ? 1 : -1;
	line.sy = line.y1 < line.y2 ? 1 : -1;
	line.err = line.dx + line.dy;
	line.clr = x_1.col;
	return (line);
}

void	make_pxl(t_line line, t_img *img)
{
	int	size;
	int	byte;

	size = 4 * WD * HG;
	byte = (line.y1) * img->size + (line.x1) * 4;

	if ( byte <= 0 || byte >= size || line.x1 > WD - 1 || line.x1 < 0)
		return ;
	img->data[byte] = line.clr;
	img->data[++byte] = line.clr >> 8;
	img->data[++byte] = line.clr >> 16;
}
