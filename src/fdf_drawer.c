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
	if (src->win)
		mlx_clear_window(src->mlx, src->win);
	src->win = mlx_new_window(src->mlx, WD, HG, "Fdf");

}

void	fdf_brezenham(t_map *map)
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

void	fdf_draw_img(t_map *src)
{
	init_image(src);
	fdf_brezenham(src);
	mlx_put_image_to_window(src->mlx, src->win, src->img.point, 0, 0);
}

void	fdf_info(t_map *map, int key, int flag)
{
	char	*info;
	int		text_color;

	text_color = GREEN;
	if (key == 4)
		text_color = 0;
	else if (key == 1 || flag == 0 || key == 0)
		text_color = GREEN;
	mlx_string_put(map->mlx, map->win, 10, 10, text_color >> 8, "@avishnev");
	mlx_string_put(map->mlx, map->win, 10, 30, text_color, "USAGE FDF: ");
	mlx_string_put(map->mlx, map->win, 115, 50, text_color, "Arrows to move");
	info = "Numpad keys to rotate, & set projection";
	mlx_string_put(map->mlx, map->win, 115, 70, text_color, info);
	mlx_string_put(map->mlx, map->win, 115, 90, text_color, "+/- ZOOM");
	mlx_string_put(map->mlx, map->win, 115, 110, text_color, "ESC to exit");
	info = "I/O Disko mod |8-) C - set default";
	mlx_string_put(map->mlx, map->win, 115, 130, text_color, info);
	info = "S show this message";
	mlx_string_put(map->mlx, map->win, 115, 150, text_color, info);
}

void	fdf_redraw_image(t_map *src, int key)
{
	static	int 	flag;

	mlx_clear_window(src->mlx, src->win);
	init_image(src);
	fdf_draw_img(src);
	mlx_destroy_image(src->mlx, src->img.point);
	if (flag == 0)
	{
		fdf_info(src, 0, flag);
		flag++;
	}
	if (key == 4 || key == 1)
		fdf_info(src, key, flag);
}

















