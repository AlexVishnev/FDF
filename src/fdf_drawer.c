/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_drawer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:52:57 by avishnev          #+#    #+#             */
/*   Updated: 2018/01/11 17:36:21 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_window(t_map *src)
{
	src->mlx = mlx_init();
	src->win = mlx_new_window(src->mlx, WD, HG, "Fdf");
}

void	get_data(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			if (i < map->x - 1)
				draw_ln(map, map->tab[i][j], map->tab[i + 1][j]);
			if (j < map->y - 1)
				draw_ln(map, map->tab[i][j], map->tab[i][j + 1]);
			j++;
		}
		i++;
	}
}

void	draw_img(t_map *src)
{
	init_image(src);
	get_data(src);
	mlx_put_image_to_window(src->mlx, src->win, src->img.point, 0, 0);
}

void	fdf_info(t_map *map)
{
	char	*info;
	char	*info2;

	info = "Arrows to move";
	info2 = "Numpad keys to rotate, & set projection";
	mlx_string_put(map->mlx, map->win, 10, 10, 0x0FF96FF, "@avishnev");
	mlx_string_put(map->mlx, map->win, 10, 30, 0x0FFFFFF, "USAGE FDF: ");
	mlx_string_put(map->mlx, map->win, 115, 50, 0x0FFFF33, info);
	mlx_string_put(map->mlx, map->win, 115, 70, 0x0FF3F33, info2);
	mlx_string_put(map->mlx, map->win, 115, 90, 0x0FF9F33, "+/- ZOOM");
	mlx_string_put(map->mlx, map->win, 115, 110, 0x0FFAFFF, "ESC to exit");
	mlx_string_put(map->mlx, map->win, 115, 130, 0x3399FF, "C to change colour");
}

void	redraw(t_map *src)
{
	t_img *image;

	image = &(src->img);
	image->point = mlx_new_image(src->mlx, WD, HG);
	image->data = mlx_get_data_addr(image->point, &(image->bits),
										 &(image->size), &(image->end));
	mlx_clear_window(src->mlx, src->win);
	draw_img(src);
	mlx_put_image_to_window(src->mlx, src->win, src->img.point, 0, 0);
	mlx_destroy_image(src->mlx, src->img.point);
	fdf_info(src);
}
