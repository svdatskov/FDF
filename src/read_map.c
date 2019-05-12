/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:26:55 by sdatskov          #+#    #+#             */
/*   Updated: 2019/04/07 15:26:57 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				atoi_hex(char *str)
{
	int		byte;
	int		result;
	int		counter;
	char	*tmp;

	result = 0;
	byte = 0;
	if (str == NULL)
		return (16777215);
	tmp = str;
	tmp = tmp + 2;
	counter = ft_strlen(str + 2);
	while (counter > 0)
	{
		if (*tmp >= '0' && *tmp <= '9')
			byte = *tmp - 48;
		if (*tmp >= 'A' && *tmp <= 'F')
			byte = *tmp - 55;
		if (*tmp >= 'a' && *tmp <= 'f')
			byte = *tmp - 87;
		result += ((int)pow(16, --counter) * byte);
		tmp++;
	}
	return (result);
}

static void		write_map(t_mlx_param *map, char **second_split, int w, int h)
{
	int color;

	color = (!(second_split[1]) ? 0xFFFFFF : atoi_hex(second_split[1]));
	map->map[h][w].x = w + 1;
	map->map[h][w].y = h + 1;
	map->map[h][w].z = ft_atoi(second_split[0]);
	map->map[h][w].color = color;
}

void			read_map(t_mlx_param *map, char *arg, int fd, t_valid i)
{
	char	*line;
	char	**split_line;
	char	**second_split;
	int		width;
	int		height;

	i.counter = 0;
	height = 0;
	fd = open(arg, O_RDONLY);
	map->map = (t_coord**)malloc(sizeof(t_coord) * i.height);
	while (get_next_line(fd, &line) == 1)
	{
		split_line = ft_strsplit(line, ' ');
		map->map[height] = (t_coord*)malloc(sizeof(t_coord) * i.width);
		width = 0;
		while (split_line[i.counter])
		{
			second_split = ft_strsplit(split_line[i.counter], ',');
			write_map(map, second_split, width, height);
			width++;
			i.counter++;
		}
		i.counter = 0;
		height++;
	}
}
