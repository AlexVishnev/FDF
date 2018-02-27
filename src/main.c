/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 17:12:58 by avishnev          #+#    #+#             */
/*   Updated: 2018/01/11 16:02:27 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_run(char *av)
{
	char		**tmp;
	size_t		x;
	size_t		y;
	t_map		*map;

	tmp = read_file(av);
	x = get_value_x(tmp);
	y = get_value_y(tmp[0]);
	map = create_map(tmp, x, y);
	free(tmp);
	fdf_create_window(map);
	cord_mid_cordinate(map);
	image_move_mid(map);
	fdf_draw_img(map);
	mlx_destroy_image(map->mlx, map->img.point);
	mlx_expose_hook(map->win, fdf_redr_f, map);
	mlx_hook(map->win, 2, 3, key_hold, map);
	mlx_loop(map->mlx);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		fdf_run(av[1]);
	if (ac > 2 && ac < 256)
		error_imput1();
	else
		error_imput();
	return (0);
}
