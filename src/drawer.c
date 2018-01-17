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

void	init_image(t_map *store)
{
	t_img	*img;

	img = &(store->img);
	img->point = mlx_new_image(store->mlx, WD, HG);
	img->data = mlx_get_data_addr(img->point, 
						&(img->bits), &(img->size), &(img->end));
}

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


void	draw_img(t_map *src)
{
	init_image(src);
	
	mlx_put_image_to_window(src->mlx, src->win, src->img.point, 0, 0); // how last params works ?

}