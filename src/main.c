/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:26:55 by sdatskov          #+#    #+#             */
/*   Updated: 2019/04/07 15:26:57 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		key_release(int keycode, void *param)
{
	static int key;

	if (keycode == 18 || keycode == 19)
		key = choose_proection(keycode, param);
	if (keycode == 53)
		exit(0);
	if (keycode == 27 || keycode == 24)
		ft_zoom(keycode, param, key);
	if (keycode == 29)
		ft_zoom_base(param, key);
	if (keycode == 13 || keycode == 1)
		ft_rotate_y(keycode, param, key);
	if (keycode == 0 || keycode == 2)
		ft_rotate_x(keycode, param, key);
	return (0);
}

static int		ft_exit(void *param)
{
	(void)param;
	exit(0);
}

static void		fdf_mlx_manipulation(t_mlx_param *map)
{
	mlx_hook(map->win_ptr, 17, 0, ft_exit, (void *)0);
	mlx_hook(map->win_ptr, 2, 0, key_release, (void *)map);
}

int				choose_proection(int keycode, t_mlx_param *param)
{
	if (keycode == 18)
	{
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		param->center = ft_make_center(param->width, param->height);
		print_map(param, param->map, param->center);
		print_menu(param);
	}
	if (keycode == 19)
	{
		mlx_clear_window(param->mlx_ptr, param->win_ptr);
		param->center = ft_make_center(param->width, param->height);
		param->center.s_u -= param->height / 6 * param->center.st;
		param->center.s_l += param->width / 3 * param->center.st;
		print_map(param, param->mapiso, param->center);
		print_menu(param);
	}
	return (keycode);
}

int				main(int argc, char **argv)
{
	int				fd;
	t_mlx_param		*map;
	t_valid			i;

	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) < 1)
			ft_error(2);
		i = validation(fd);
		map = mlx_initial();
		map->width = i.width;
		map->height = i.height;
		read_map(map, argv[1], fd, i);
		map->center = ft_make_center(map->width, map->height);
		print_map(map, map->map, map->center);
		print_menu(map);
		map = iso(map);
		fdf_mlx_manipulation(map);
		mlx_loop(map->mlx_ptr);
	}
	else
		ft_error(1);
	return (0);
}
