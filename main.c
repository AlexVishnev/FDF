/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 17:12:58 by avishnev          #+#    #+#             */
/*   Updated: 2017/12/29 14:49:47 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdlib.h>

#define STEP 5;
#define WD 400;
#define HG 500;

// typedef struct s_fdf
// {
// 	void	*mlx;
// 	void	*win;
// 	int		fd;
// 	int		press;
// 	int		color;
// }				t_fdf;

// typedef struct 	s_cord
// {
// 	int		x;
// 	int		y;
// 	int		z;
// }				t_cord;

// void	build_image(t_fdf *fill)
// {
// 	fill->mlx = mlx_init();
// 	fill->win = mlx_new_window(fill->mlx, WD, HG, "Landscape 8-)");
// //	mlx_key_hook(fill->win, fill_manip, fill);
// }
// int	closef(int keycode, void *p)
// {
// 	keycode == 53 ? exit(0) : printf("keycode = %d\n", keycode);
// 	return (0);
// }

// int	fill_manip(int keycode, t_fdf *oper, t_cord *cor)
// {
// 	if (keycode == 126) // arrowup
// 		cor->y -= STEP;
// 	if (keycode == 125)
// 		cor->y += STEP;	// down arr
// 	if (keycode == 123) // arrleft
// 		cor->x -= STEP;
//  	if (keycode == 124) // rigtharr
//  		cor->x += STEP;
// 	if (keycode == 67) // zoom - /
// 	{
// 		mlx_clear_window(oper->mlx, oper->win);
// 		cor->z -= STEP;
// 		//draw();
// 	}		

// 	if (keycode == 75) // zoom+ *
// 	{
// 		mlx_clear_window(mlx, win);
// 		cor->z += STEP;
// 		//draw();
// 	}
// 	if (keycode == 15)
// 		return_def_position;
// 	else
// 		ft_putendl("wrong usage. Look at info");
// 	return (0);
// }
int	main()
{
	void	*mlx;
	void	*wind;

	int		x;
	int		y;

	x = 30;
	mlx = mlx_init();
	wind = mlx_new_window(mlx, 400, 400, "title");
	while (x < 100)
	{
		y = 30;
		mlx_pixel_put(mlx, wind, x + 10, y + 10, 0xFFFF00);
		while (y < 135)
		{
			mlx_string_put(mlx, wind, 100, 200, 0xFFFF00, "42");
			y++;
		}
		x++;
	}
	mlx_key_hook(wind, closef, 0);
	mlx_loop(mlx);
}
