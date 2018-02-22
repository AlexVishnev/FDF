/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rfile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:26:20 by avishnev          #+#    #+#             */
/*   Updated: 2018/01/11 15:42:35 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		size_fill(char *field)
{
	int		fd;
	char	*str;
	int		i;

	i = 0;
	fd = open(field, O_RDONLY);
	while (ft_getline(fd, &str) > 0)
	{
		ft_memdel((void **)&str);
		i++;
	}
	ft_memdel((void **)&str);
	close(fd);
	return (i);
}

char 	**read_file(char *field)
{
	char	**buff;
	int		fd;
	int		size;
	int		i;

	size = size_fill(field);
	i = 0;
	fd = open(field, O_RDONLY);
	if (read(fd, field, 0) < 0)
		error_imput();
	if (!(buff = (char**)malloc(sizeof(char*) * size + 1)))
		return (NULL);
	while (ft_getline(fd, &buff[i]))
		i++;
	buff[i] = NULL;
	close(fd);
	valide(buff);
	return (buff);
}
static void free_tab(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			map->tab[i][j].x = 0;
			map->tab[i][j].y = 0;
			map->tab[i][j].z = 0;
			map->tab[i][j].col = 0;
			j++;
		}
		i++;
	}
}

void	free_data(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	free((void*)map->mid);
	printf("LOOK UP ON mid after free mid =%f\n", map->mid->x);
	while (i < map->x)
	{
		j = 0;
		while (j < map->y)
		{
			// printf("LOOK UP ON FREE x[%zu] =%f\n", j, map->tab[i][j].x);
			// printf("LOOK UP ON FREE y[%zu] =%f\n", j, map->tab[i][j].y);
			// printf("LOOK UP ON FREE z[%zu] =%f\n", j, map->tab[i][j].z);
			// printf("LOOK UP ON FREE col[%zu]=%f\n",  j,map->tab[i][j].col);

			free_tab(map);

			// printf("LOOK UP ON FREE x after free[%zu] =%f\n", j, map->tab[i][j].x);
			// printf("LOOK UP ON FREE y after free[%zu]=%f\n",  j,map->tab[i][j].y);
			// printf("LOOK UP ON FREE z after free[%zu] =%f\n", j, map->tab[i][j].z);
			// printf("LOOK UP ON FREE col after free[%zu]=%f\n",  j,map->tab[i][j].col);
			j++; 
		}
		i++;
	}
	//	if (!(map->mid = (t_cord *)malloc(sizeof(t_cord))))
	//	if (!(map = (t_map *)malloc(sizeof(t_map))))
	//	if (!(map->tab = (t_cord **)malloc(sizeof(t_cord *) * x)))
	//	if (!(map->tab[i] = (t_cord*)malloc(sizeof(t_cord) * y))) 
}











