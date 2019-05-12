/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:26:55 by sdatskov          #+#    #+#             */
/*   Updated: 2019/04/07 15:26:57 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_zoom(int keycode, t_mlx_param *param, int point)
{
	t_coord **coord;

	param->center = calculate_center(param->width,
			param->height, param->center);
	coord = param->map;
	if (point == 19)
	{
		coord = param->mapiso;
		param->center.s_u -= param->height / 6 * param->center.st;
		param->center.s_l += param->width / 3 * param->center.st;
	}
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	if (keycode == 27)
		param->center.st--;
	else if (keycode == 24)
		param->center.st++;
	if (param->center.st <= 1)
		param->center.st = 1;
	print_map(param, coord, param->center);
}

void	ft_zoom_base(t_mlx_param *param, int point)
{
	t_coord **coord;

	param->center = ft_make_center(param->width, param->height);
	coord = param->map;
	if (point == 19)
	{
		coord = param->mapiso;
		param->center.s_u -= param->height / 6 * param->center.st;
		param->center.s_l += param->width / 3 * param->center.st;
	}
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	print_map(param, coord, param->center);
	print_menu(param);
}

void	ft_rotate_y(int keycode, t_mlx_param *param, int point)
{
	t_center	tmp;
	t_coord		**coord;

	coord = param->map;
	if (point == 19)
		coord = param->mapiso;
	tmp = ft_make_center(param->width, param->height);
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	if (keycode == 1)
		param->center.s_u = param->center.s_u + 10;
	else if (keycode == 13)
		param->center.s_u = param->center.s_u - 10;
	if (param->center.st == tmp.st)
	{
		print_menu(param);
		if (param->center.s_u < -param->center.st)
			param->center.s_u = -param->center.st;
		else if (param->center.s_u >
		HEIGHT - param->height * param->center.st)
			param->center.s_u =
					HEIGHT - param->height * param->center.st - 1;
	}
	print_map(param, coord, param->center);
}

void	ft_rotate_x(int keycode, t_mlx_param *param, int point)
{
	t_center	tmp;
	int			menu;
	t_coord		**coord;

	coord = param->map;
	if (point == 19)
		coord = param->mapiso;
	menu = 300;
	tmp = ft_make_center(param->width, param->height);
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	if (keycode == 0)
		param->center.s_l = param->center.s_l - 10;
	else if (keycode == 2)
		param->center.s_l = param->center.s_l + 10;
	if (param->center.st == tmp.st)
	{
		print_menu(param);
		if (param->center.s_l - menu < -param->center.st)
			param->center.s_l = -param->center.st + menu;
		else if (param->center.s_l >
		WIDTH - param->width * param->center.st)
			param->center.s_l =
					WIDTH - param->width * param->center.st - 1;
	}
	print_map(param, coord, param->center);
}
