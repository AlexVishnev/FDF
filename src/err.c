/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:03:41 by avishnev          #+#    #+#             */
/*   Updated: 2018/01/30 17:03:43 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	valide_map()
{

}

void	map_err(void)
{
	ft_putendl("Error: You trying to parse crash map!");
	ft_putendl("Dont do that, please!");
	exit(1);
}

void	error_imput(void)
{
	perror("Error");
	exit(1);
}
