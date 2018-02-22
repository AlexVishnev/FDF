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

int	main(int ac, char **av)
{
	char		**tmp;
	size_t		x;
	size_t		y;
	t_map		*map;

	if (ac == 2)
	{
		tmp = read_file(av[1]);
		x = cnt_rows(tmp);
		y = cnt_clms(tmp[0]);
		map = create_map(tmp, x, y);
		free(tmp);	
		create_window(map);
		mid_cord(map);
		move_mid(map);
		draw_img(map);
		mlx_destroy_image(map->mlx, map->img.point);
		mlx_expose_hook(map->win, redr_f, map);
		mlx_hook(map->win, 2, 3, key_hold, map);
		mlx_loop(map->mlx);
	}
	else
		error_imput();
	return (0);
}
