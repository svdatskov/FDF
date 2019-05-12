/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_center.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:26:55 by sdatskov          #+#    #+#             */
/*   Updated: 2019/04/07 15:26:57 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_center		ft_make_center(int wdt, int hgh)
{
	t_center	a;
	int			menu;

	a.st = 10;
	menu = 300;
	if (wdt * a.st > WIDTH - menu - 400 || hgh * a.st > HEIGHT - 400)
	{
		while (wdt * a.st > WIDTH - menu - 400 || hgh * a.st > HEIGHT - 400)
			a.st--;
	}
	else if (wdt * a.st < WIDTH - menu - 800 || hgh * a.st < HEIGHT - 800)
	{
		while (wdt * a.st < WIDTH - menu - 800 && hgh * a.st < HEIGHT - 800)
			a.st++;
	}
	if (a.st <= 1)
		a.st = 1;
	a.s_l = ((WIDTH + menu - (wdt * a.st)) / 2) - a.st / 2;
	a.s_u = ((HEIGHT - (hgh * a.st)) / 2) - a.st / 2;
	return (a);
}

t_center		calculate_center(int width, int height, t_center c)
{
	c.s_l = ((WIDTH - (width * c.st)) / 2) - c.st / 2;
	c.s_u = ((HEIGHT - (height * c.st)) / 2) - c.st / 2;
	return (c);
}
