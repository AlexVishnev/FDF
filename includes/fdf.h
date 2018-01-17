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
# define WD 1000
# define HG 1000

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
	t_cord	*middle;
	t_cord	**tab;
	int		x;
	int		y;
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

void			create_window(t_map *store);
void			map_err(void);
void			draw_img(t_map *src);
void			error_imput(void);
void			build_image(t_map *fill);
void			valide(char **s);
void			make_pxl(t_line ln, t_img *img);

int				cnt_rows(char **s);
int				cnt_clms(char *s);
int				check_size(char **s);
int				size_fill(char *s);

char 			**rfile(char *s, int size);
char			**split_arr(char *str);

t_cord			new_cord(int j, int i, char *s);
t_map			*map_alloc(int x, int y);
t_map			*create_map(char **tab, int x, int y);
t_line			line_param(t_cord c_1 , t_cord c_2);

#endif
