/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avishnev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:03:41 by avishnev          #+#    #+#             */
/*   Updated: 2018/01/30 17:03:43 by avishnev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_error(void)
{
	ft_putendl("Error: You trying to parse invalid map!");
	ft_putendl("Usage: ./fdf /map/example.fdf");
	exit(1);
}

void	error_imput(void)
{
	perror("Error");
	exit(1);
}

void	error_imput1(void)
{
	ft_putendl("Error: Multithreading are not supports");
	exit(1);
}
