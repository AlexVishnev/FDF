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

size_t		cnt_rows(char **s)
{
	size_t	x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

size_t		cnt_clms(char *s)
{
	char 	**tmp;
	size_t	y;
	
	tmp = ft_split_arr(s, ' ');
	y = 0;
	while (tmp[y])
	{
		free(tmp[y]);
		y++;
	}
	free(tmp);
	return (y);
}

int	check_size(char **s)
{
	size_t	i;
	size_t	s0;
	size_t	s1;

	i = 1;
	s0 = cnt_clms(s[0]);
	printf("s0 = [%zu]\n", s0);
	while (s[i])
	{
		printf("s1[%zu] = [%zu]\n", i,  s1);
		s1 = cnt_clms(s[i]);
		if (s1 < s0)
			return (1);
		i++;
	}
	return (0);
}

int 	check_store(char **s)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (s[i][j] != '\0')
	{
		while (s[i][j] != '\n')
		{
			if (s[i][j] == ' ' || s[i][j] == '-')
				j++;
			if (ft_isdigit(s[i][j]))
				j++;
			if (s[i][j] == '\0' && ((s[i][j - 1] == '\n') || ft_isdigit(s[i][j - 1])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
void	valide(char **s)
{
	if (check_size(s) || check_store(s))
		map_error();
}

void	init_image(t_map *store)
{
	t_img	*img;

	img = &(store->img);
	img->point = mlx_new_image(store->mlx, WD, HG);
	img->data = mlx_get_data_addr(img->point, 
						&(img->bits), &(img->size), &(img->end));
}
