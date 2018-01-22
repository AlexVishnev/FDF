/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 13:18:09 by avishnev          #+#    #+#             */
/*   Updated: 2018/01/11 13:31:04 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include "../libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>

# define STEP 20
# define WD 1200
# define HG 800

typedef	struct	s_cord
{
	double		x;
	double		y;
	double		z;
	double		col;
}				t_cord;

typedef	struct	s_img
{
	void	*point;
	char	*data;
	int		size;
	int		bits;
	int		end;
}				t_img;

typedef	struct s_map
{
	t_img	img;
	t_cord	*mid;
	t_cord	**tab;
	size_t	x;
	size_t	y;
	void	*mlx;
	void	*win;
}				t_map;

typedef	struct 	s_line
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;	
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		err2;
	int		clr;
	
}				t_line;

void			move_mid(t_map *map);
void			move_abs(t_map *map, int step);
void			move_ord(t_map *map, int step);
void			create_window(t_map *store);
void			map_err(void);
void			draw_img(t_map *src);
void			error_imput(void);
void			build_image(t_map *fill);
void			valide(char **s);
void			make_pxl(t_line ln, t_img *img);
void			draw_ln(t_map *map, t_cord x1, t_cord x2);
void			mid_cord(t_map *map);
void			redraw(t_map *map);
void			get_data(t_map *field);
void			init_image(t_map *store);
void			zoom_map(t_map *map, double zoom);
void			key_zoom(int key, t_map *map);

int				check_size(char **s);
int				redr_f(t_map *map);
int				key_hold(int key, t_map *map);

size_t			size_fill(char *s);
size_t			cnt_rows(char **s);
size_t			cnt_clms(char *s);

char 			**rfile(char *s);
char			**split_arr(char *str);

t_cord			new_cord(char *s, int x, int y);
t_map			*map_alloc(size_t x, size_t y);
t_map			*create_map(char **tab, size_t x, size_t y);
t_line			line_param(t_cord c_1 , t_cord c_2);

#endif
