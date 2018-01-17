/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:52:57 by avishnev          #+#    #+#             */
/*   Updated: 2018/01/11 17:36:21 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_window(t_map *store)
{
	store->mlx = mlx_init();
	store->win = mlx_new_window(store->mlx, WD, HG, "Fdf");
}

void	make_pxl(t_line ln, t_img *img)
{
	int	size;
	int	byte;

	size = 4 * WD * HG;
	byte = (ln.y1) * img->size + (ln.x1) * 4;

	if (byte >= size || ln.x1 > WD - 1 || ln.x1 < 0)
		return ;
	img->data[byte] = ln.clr;
	byte++;
	img->data[byte] = ln.clr >> 8;
	byte++;
	img->data[byte] = ln.clr >> 16;
}

void	get_data(t_map *field)
{
	int	i;
	int	j;

	i = 0;
	while (i < field->x)
	{
		j = 0;
		while (j < field->y)
		{
			if (j < field->y - 1)
				draw_ln(field, field->tab[i][j], field->tab[i][j + 1]);
			if (i < field->x - 1)
				draw_ln(field, field->tab[i][j], field->tab[i + 1][j]);
			j++;
		}
		i++;
	}
}

void	draw_img(t_map *src)
{
	init_image(src);
	get_data(src);	
	mlx_put_image_to_window(src->mlx, src->win, src->img.point, 0, 0); // how last params works ?
}

void	redraw(t_map *map)
{
	t_img *image;

	image = &(map->img);
	image->point = mlx_new_image(map->mlx, WD, HG);
	image->data = mlx_get_data_addr(image->point, &(image->bits),
										 &(image->size), &(image->end));
	draw_img(map);
	mlx_put_image_to_window(map->mlx, map->win, map->img.point, 0, 0);
	mlx_destroy_image(map->mlx, map->img.point); 
}