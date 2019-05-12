/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:26:55 by sdatskov          #+#    #+#             */
/*   Updated: 2019/04/07 15:26:57 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(int err_num)
{
	if (err_num == 1)
	{
		ft_putendl("Usage: ./fdf MAP_FILE");
		exit(1);
	}
	if (err_num == 2)
	{
		ft_putendl("Wrong MAP File!");
		exit(2);
	}
	if (err_num == 3)
	{
		ft_putendl("File Read Error!");
		exit(3);
	}
	if (err_num == 4)
	{
		ft_putendl("Validation Error");
		exit(4);
	}
}
