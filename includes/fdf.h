/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 15:26:49 by sdatskov          #+#    #+#             */
/*   Updated: 2019/04/30 04:19:54 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>

# define WIDTH 2000
# define HEIGHT 1000

typedef struct		s_brazen
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				error;
	int				error2;
}					t_brazen;

typedef	struct		s_coord
{
	double			x;
	double			y;
	double			z;
	int				color;
}					t_coord;

typedef struct		s_center
{
	int				s_u;
	int				s_l;
	int				st;
}					t_center;

typedef struct		s_mlx_param
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				width;
	int				height;
	struct s_center center;
	struct s_coord	**map;
	struct s_coord	**mapiso;
}					t_mlx_param;

typedef struct		s_valid
{
	char			**split_line;
	char			*line;
	int				width;
	int				height;
	int				base_width;
	int				read_error;
	int				counter;
}					t_valid;

typedef struct		s_mlx
{
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				color;
}					t_mlx;

typedef struct		s_menu
{
	char			*str1;
	char			*str2;
	char			*str3;
	char			*str4;
	char			*str5;
	char			*str6;
}					t_menu;

void				ft_error(int err_num);
void				print_line(t_mlx coord, void *mlx_ptr, void *win_ptr);
void				read_map(t_mlx_param *map, char *arg, int fd, t_valid i);
void				print_map(t_mlx_param *param, t_coord **map, t_center ct);
void				ft_zoom(int keycode, t_mlx_param *param, int point);
void				ft_zoom_base(t_mlx_param *param, int point);
void				ft_rotate_y(int keycode, t_mlx_param *param, int point);
void				ft_rotate_x(int keycode, t_mlx_param *param, int point);
void				print_menu(t_mlx_param *param);
int					choose_proection(int keycode, t_mlx_param *param);
int					atoi_hex(char *str);
t_center			calculate_center(int width, int height, t_center center);
t_center			ft_make_center(int wdt, int hgh);
t_center			ft_make_centeriso(t_coord **map, int width, int height);
t_mlx_param			*mlx_initial(void);
t_valid				validation(int fd);
t_mlx_param			*iso(t_mlx_param *map);

#endif
