/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brazenhem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 12:38:50 by sdatskov          #+#    #+#             */
/*   Updated: 2019/04/20 12:38:52 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_line(t_mlx coord, void *mlx_ptr, void *win_ptr)
{
	t_brazen brazen;

	brazen.dx = abs(coord.x2 - coord.x1);
	brazen.dy = abs(coord.y2 - coord.y1);
	brazen.sx = (coord.x1 < coord.x2) ? 1 : -1;
	brazen.sy = (coord.y1 < coord.y2) ? 1 : -1;
	brazen.error = brazen.dx - brazen.dy;
	mlx_pixel_put(mlx_ptr, win_ptr, coord.x2, coord.y2, coord.color);
	while (coord.x1 != coord.x2 || coord.y1 != coord.y2)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, coord.x1, coord.y1, coord.color);
		brazen.error2 = brazen.error * 2;
		if (brazen.error2 > -brazen.dy)
		{
			brazen.error -= brazen.dy;
			coord.x1 += brazen.sx;
		}
		if (brazen.error2 < brazen.dx)
		{
			brazen.error += brazen.dx;
			coord.y1 += brazen.sy;
		}
	}
}
