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
	char	**tmp;
	int		x;
	int		y;
	int		size;
	t_map	*map;

	if (ac == 2)
	{
		size = size_fill(av[1]);
		tmp = rfile(av[1], size);
		x = cnt_rows(tmp);
		y = cnt_clms(tmp[0]);
		create_window(map);
		draw_img(map);
		mlx_expose_hook(map->win, exp_func, map);
		mlx_hook(map->win, 2, 3, keyfunc, map);
		mlx_loop(map->mlx);	
	}
	else
		error_imput();
	return(0);
}
