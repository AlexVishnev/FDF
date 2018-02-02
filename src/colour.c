/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:35:52 by avishnev          #+#    #+#             */
/*   Updated: 2018/02/02 15:36:05 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char **get_colour_factor(char **tab, t_coord *p)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (ft_isdigit(tab[i][j]))
			{
				if (ft_atoi(tab[i][j]) > 0 && ft_atoi(tab[i][j]) <= 9)
					(*p)->clr = ft_atoi_base("5", 16);
				else if (t_atoi(tab[i][j]) > 10 && ft_atoi(tab[i][j]) <= 15)
					(*p)->clr = ft_atoi_base("10", 16);	
				else if (t_atoi(tab[i][j]) > 16 && ft_atoi(tab[i][j]) <= 20)
					(*p)->clr = ft_atoi_base("15", 16);
				else
					(*p)->clr = ft_atoi_base("64", 16);
			}
			j++;
		}
		i++;
	}
	return (tab);
}