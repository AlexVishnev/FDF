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

void	fdf_create_window(t_map *src)
{
	src->mlx = mlx_init();
	if (src->win)
		mlx_clear_window(src->mlx, src->win);
	src->win = mlx_new_window(src->mlx, WD, HG, "Fdf");
}

int		fdf_redr_f(t_map *map)
{
	fdf_redraw_image(map, 0);
	return (0);
}

void	fdf_draw_img(t_map *src)
{
	image_init(src);
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
	mlx_string_put(map->mlx, map->win, 115, 90, text_color, "[+]/[-] Zoom");
	mlx_string_put(map->mlx, map->win, 115, 110, text_color, "[ESC] to exit");
	info = "[I]/[O] Disko mod O_o C - heigt color   V- set default";
	mlx_string_put(map->mlx, map->win, 115, 130, text_color, info);
	info = "Any key to hide this message";
	mlx_string_put(map->mlx, map->win, 115, 150, text_color, info);
	info = "[S] show this message";
	mlx_string_put(map->mlx, map->win, 115, 170, text_color, info);
}

void	fdf_redraw_image(t_map *src, int key)
{
	static	int		flag;

	mlx_clear_window(src->mlx, src->win);
	image_init(src);
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
