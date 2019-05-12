/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 12:34:49 by sdatskov          #+#    #+#             */
/*   Updated: 2019/04/20 12:35:00 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int			check_color(char *str)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (*str != '0')
		return (0);
	if (*(str + 1) != 'x')
		return (0);
	str = str + 2;
	while (*str)
	{
		if ((*str >= 'A' && *str <= 'F') || (*str >= '0' && *str <= '9')
			|| (*str >= 'a' && *str <= 'f'))
			i--;
		str++;
		i++;
		j++;
	}
	if (i != 0 || j > 6 || j < 1)
		return (0);
	return (1);
}

static	int			check_column(char *str)
{
	int		i;
	int		j;
	char	**second_split;

	i = 0;
	j = 0;
	second_split = ft_strsplit(str, ',');
	if (!*second_split)
		ft_error(4);
	while (second_split[i])
		i++;
	while (second_split[0][j])
	{
		if (ft_isdigit(second_split[0][j]) == 0 && second_split[0][0] != '-')
			ft_error(4);
		j++;
	}
	if (i > 2)
		return (0);
	if (second_split[1] == NULL)
		return (1);
	else
		return (check_color(second_split[1]));
}

static t_valid		read_validation(t_valid valid, int fd)
{
	while (get_next_line(fd, &valid.line) == 1)
	{
		valid.read_error = 1;
		valid.width = 0;
		valid.split_line = ft_strsplit(valid.line, ' ');
		if (!(*valid.split_line))
			ft_error(4);
		while (valid.split_line[valid.width])
			++valid.width;
		if (valid.height == 0)
			valid.base_width = valid.width;
		else if (valid.width != valid.base_width)
			ft_error(4);
		valid.height++;
		while (valid.split_line[valid.counter])
		{
			if (check_column(valid.split_line[valid.counter++]) == 0)
				ft_error(4);
		}
		valid.counter = 0;
	}
	return (valid);
}

t_valid				validation(int fd)
{
	t_valid valid;

	valid.height = 0;
	valid.base_width = 0;
	valid.counter = 0;
	valid.read_error = 0;
	valid = read_validation(valid, fd);
	if (valid.read_error == 0)
		ft_error(4);
	close(fd);
	return (valid);
}
