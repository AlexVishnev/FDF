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

void	init_image(t_fdf *fill)
{
	t_img	*img;

	img = &(fill->img);
	img->point = mxl_new_image(fill->mlx, WD, HG);
	img->data = mlx_get_data_addr(img->point, 
						&(img->bits), &(img->size), &(img->end));

}
void	init_window(t_fdf *fill)
{
	fill->mlx = mlx_init();
	fill->win = mlx_new_window(fill->mlx, WD, HG, "Fdf");
}
