/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISO.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:26:55 by sdatskov          #+#    #+#             */
/*   Updated: 2019/04/07 15:26:57 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx_param		*iso(t_mlx_param *map)
{
	int i;
	int j;

	i = 0;
	map->mapiso = (t_coord**)malloc(sizeof(t_coord) * map->height);
	while (i < map->height)
	{
		j = 0;
		map->mapiso[i] = (t_coord*)malloc(sizeof(t_coord) * map->width);
		while (j < map->width)
		{
			map->mapiso[i][j].x = ((map->map[i][j].x -
					map->map[i][j].y) * cos(0.523599));
			map->mapiso[i][j].y = ((-map->map[i][j].z +
					(map->map[i][j].x + map->map[i][j].y)) * sin(0.523599));
			map->mapiso[i][j].color = map->map[i][j].color;
			j++;
		}
		i++;
	}
	return (map);
}
