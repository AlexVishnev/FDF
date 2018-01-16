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
# include "mlx.h"

# define STEP 5
# define WD 1000
# define HG 1000

typedef struct	s_fdf
{
	int		fd;
	int		key;
}				t_fdf;

typedef	struct	s_cord
{
	int		x;
	int		y;
	int		z;
	int		col;
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
	t_cord	middle;
	t_cord	**tab;
	int		x;
	int		y;
	void	*mlx;
	void	*win;
}				t_map;

int				closef(int keycode);
int				fill_manip(int keycode, t_fdf *oper, t_cord *cor);
void			build_image(t_fdf *fill);
char 			**rfile(char *s, int size);
void			map_err(void);
void			error_imput(void);
t_cord			new_cord(int j, int i, char *s);
t_map			*map_alloc(char **tab, int x, int y);
int				ft_atoi_base(char *str, int base);
int				size_fill(char *s);
char			**split_arr(char *str);
t_map			*create_map(char **tab, int x, int y);
int				cnt_rows(char **s);
int				cnt_clms(char *s);
int				check_size(char **s);
void			valide(char **s);

#endif
