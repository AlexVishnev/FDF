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

# define STEP 5
# define WD 2000
# define HG 2000
# define RADIAN 2 * 3.14159265359 / 180
# define BLUE 0x0000FF
# define GREEN 0x00FF00
# define BROWN 0x8B451
# define WHITE "0xFFFFFF"
# define MATRIX_ map->tab[i][j]
# define MATRIX_MID_ map->mid

typedef	struct	s_cord
{
	float				x;
	float				y;
	float				z;
	int					hgz;
	unsigned long long	col;
}				t_cord;

typedef struct	s_hgcol
{
	int		min_hg;
	int		mid_hg;
	int		max_hg;
}				t_hgcol;

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


t_hgcol		sorting(t_map *map, t_hgcol p);

void			fdf_info(t_map *map, int key, int flag);
t_cord			fdf_color_fun(t_cord *p, int key);
void			fdf_draw_img(t_map *src);
void			fdf_set_projection(t_map *map, int key);
void			fdf_redraw_image(t_map *map, int key);

/*
**
**/
void			image_colour(t_map *map, int key);
t_cord			image_rotation_x(t_cord *p, t_cord *mid, int var, int key);
t_cord			image_rotation_y(t_cord *p, t_cord *mid, int var, int key);
t_cord			image_rotation_z(t_cord *p, t_cord *mid, int var, int key);
t_cord			image_new_cord_colour(t_map *map, t_cord c, int key);

void			cord_mid_cord(t_map *map);
t_cord			cord_new_cord(char *s, int x, int y);

void			free_data(t_map *map);
void			key_colour(t_cord *c, int key);

void			key_zoom_image(int key, t_map *map);
void			move_mid(t_map *map);
void			image_move_abs(t_map *map, int step, int key);
void			image_move_ord(t_map *map, int step, int key);
void			create_window(t_map *store);
void			map_error(void);

void			error_imput(void);

void			valide(char **s);
void			make_pxl(t_line ln, t_img *img);
void			draw_ln(t_map *map, t_cord x1, t_cord x2);


void			fdf_brezenham(t_map *field);
void			init_image(t_map *store);
void			zoom_map(t_map *map, float zoom);
void			key_zoom(int key, t_map *map);


void			error_imput1(void);

int				check_size(char **s);
int				redr_f(t_map *map);
int				key_hold(int key, t_map *map);
void 			key_rot_color(int key, t_map *map);

int				size_fill(char *s);
size_t			cnt_rows(char **s);
size_t			cnt_clms(char *s);

char			**read_file(char *field);



t_map			*map_alloc(size_t x, size_t y);
t_map			*create_map(char **tab, size_t x, size_t y);
t_line			line_param(t_cord c_1 , t_cord c_2);

#endif
