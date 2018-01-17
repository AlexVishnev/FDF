/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:51:32 by avishnev          #+#    #+#             */
/*   Updated: 2018/01/16 17:30:26 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		cnt_rows(char **s)
{
	int	cnt;

	cnt = 0;
	while (s[cnt])
		cnt++;
	return (cnt);
}

int		cnt_clms(char *s)
{
	char 	**tmp;
	int		clms;
	
	tmp = ft_strsplit(s, ' ');
	clms = 0;
	while (tmp[clms])
	{
		free(tmp[clms]);
		clms++;
	}
	free(tmp);
	return (clms);
}

int	check_size(char **s)
{
	int	i;
	int	s0;
	int	s1;

	i = 0;
	s0 = cnt_clms(s[0]);
	while (s[i])
	{
		s1 = cnt_clms(s[i]);
		if (s1 < s0)
			return (1);
		i++;
	}
	return (0);
}


void	valide(char **s)
{
	if (check_size(s))
		map_err();
}

void	init_image(t_map *store)
{
	t_img	*img;

	img = &(store->img);
	img->point = mlx_new_image(store->mlx, WD, HG);
	img->data = mlx_get_data_addr(img->point, 
						&(img->bits), &(img->size), &(img->end));
}
