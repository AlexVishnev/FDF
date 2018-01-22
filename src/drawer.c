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

	if ( byte <= 0 || byte >= size || ln.x1 > WD - 1 || ln.x1 < 0)
		return ;
	img->data[byte] = ln.clr;
	img->data[++byte] = ln.clr >> 8;
	img->data[++byte] = ln.clr >> 16;
}

void	get_data(t_map *map)
{
	size_t	i;
	size_t	j;

	double tmp, tmp1, tmp3;
	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			if (j < map->y - 1)
			{
				draw_ln(map, map->tab[i][j], map->tab[i][j + 1]);
				tmp = map->tab[i][j].x;
				printf("value = %f\n%s\n", tmp,"xLINE WAS drawed");
			}
			if (i < map->x - 1)
			{
				draw_ln(map, map->tab[i][j], map->tab[i + 1][j]);
				tmp1 = map->tab[i][j].y;
				tmp3 = map->tab[i][j].z;
				printf("Z____cord = %f\nvalue = %f\n%s\n",tmp3, tmp1,"yLINE WAS drawed");
			}
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

void	redraw(t_map *src)
{
	t_img *image;

	image = &(src->img);
	image->point = mlx_new_image(src->mlx, WD, HG);
	image->data = mlx_get_data_addr(image->point, &(image->bits),
										 &(image->size), &(image->end));
	draw_img(src);
	mlx_put_image_to_window(src->mlx, src->win, src->img.point, 0, 0);
	mlx_destroy_image(src->mlx, src->img.point); 
}
