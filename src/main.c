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
	t_map	*fill;
	if (ac == 2)
	{
		size = size_fill(av[1]);
		tmp = rfile(av[1], size);
		build_image(fill);
	}
	else
		error_imput();
	return(0);
}
