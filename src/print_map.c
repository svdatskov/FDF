/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:26:55 by sdatskov          #+#    #+#             */
/*   Updated: 2019/04/30 04:21:02 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_map(t_mlx_param *param, t_coord **map, t_center ct)
{
	t_mlx		line;
	size_t		x;
	size_t		y;

	y = UINT64_MAX;
	while (++y < (size_t)param->height && (x = UINT64_MAX))
		while (++x < (size_t)param->width)
		{
			line.x1 = (int)((map[y][x].x) * ct.st + ct.s_l);
			line.y1 = (int)((map[y][x].y) * ct.st + ct.s_u);
			line.color = map[y][x].color;
			if (x < (size_t)param->width - 1)
			{
				line.x2 = (int)((map[y][x + 1].x) * ct.st + ct.s_l);
				line.y2 = (int)((map[y][x + 1].y) * ct.st + ct.s_u);
				print_line(line, param->mlx_ptr, param->win_ptr);
			}
			if (y < (size_t)param->height - 1)
			{
				line.x2 = (int)((map[y + 1][x].x) * ct.st + ct.s_l);
				line.y2 = (int)((map[y + 1][x].y) * ct.st + ct.s_u);
				print_line(line, param->mlx_ptr, param->win_ptr);
			}
		}
}

void	print_menu(t_mlx_param *param)
{
	t_menu	menu;
	t_mlx	coord;
	int		color;

	menu.str1 = "Configuration Buttons:";
	menu.str2 = "ZOOM: + / - buttons";
	menu.str3 = "X - rotate: a / d - buttons";
	menu.str4 = "Y - rotate: w / s - buttons";
	menu.str5 = "Back to Default: 0 - button";
	menu.str6 = "Default/ISO: 1 / 2 - buttons";
	color = 0xFFFFFF;
	mlx_string_put(param->mlx_ptr, param->win_ptr, 15, 100, color, menu.str1);
	mlx_string_put(param->mlx_ptr, param->win_ptr, 15, 140, color, menu.str2);
	mlx_string_put(param->mlx_ptr, param->win_ptr, 15, 180, color, menu.str3);
	mlx_string_put(param->mlx_ptr, param->win_ptr, 15, 220, color, menu.str4);
	mlx_string_put(param->mlx_ptr, param->win_ptr, 15, 260, color, menu.str5);
	mlx_string_put(param->mlx_ptr, param->win_ptr, 15, 300, color, menu.str6);
	coord.y1 = 0;
	coord.x1 = 299;
	coord.x2 = 299;
	coord.y2 = HEIGHT;
	coord.color = color;
	print_line(coord, param->mlx_ptr, param->win_ptr);
}
