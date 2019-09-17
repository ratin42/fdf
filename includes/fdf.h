/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 08:07:58 by ratin             #+#    #+#             */
/*   Updated: 2019/02/24 00:36:00 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 2050
# define HEIGHT 1960
# include <mlx.h>
# include <X.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <math.h>

typedef	struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
}				t_img;

typedef struct	s_input
{
	int			mouse_x;
	int			mouse_y;
	int			zoom;
	int			x_position;
	int			y_position;
	int			projection;
	int			menu;
	int			color;
	int			mouse;
	int			mouse_x_save;
	int			mouse_y_save;
	int			z_extend;
	int			hight_extend;
	double		z_rotation;
}				t_input;

typedef struct	s_point
{
	int		x;
	int		y;
	int		z;
}				t_point;

typedef struct	s_line
{
	int			dx;
	int			dy;
	int			dp;
	int			delta_e;
	int			delta_ne;
}				t_line;

typedef struct	s_map
{
	int			width;
	int			height;
	int			**map;
	int			size;
}				t_map;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_input	input;
	t_map	map;
}				t_mlx;

t_point			*iso_map(t_mlx *mlx);
int				handle_key(int key, void *mlx);
int				quit_fdf(void *mlx);
int				ft_put_pixel(t_mlx *mlx, int x, int y, int color);
int				print_lines(t_point *point1, t_point *point2, t_mlx *mlx);
int				put_line(t_point *point1, t_point *point2, t_mlx *mlx);
int				make_map(char *str, t_mlx *mlx);
int				give_color(t_mlx *mlx);
int				handle_mouse(int x, int y, void *mlx);
int				invalid_file(char *str);
char			*read_file(char *str);
char			**make_tab(char *str);
void			put_map(t_point *point, t_mlx *mlx);
void			print_map(t_mlx *mlx);
void			vertical_limit(t_point *point1, t_point *point2, t_mlx *mlx);
void			tile_size(t_point *point, t_mlx *mlx);
void			dtoiso(t_point *point, t_mlx *mlx);
void			dtopara(t_point *point, t_mlx *mlx);
void			tile_size_para(t_point *point, t_mlx *mlx);
void			free_double_char(char **array);
void			free_double_int(int **array, int size);
void			do_the_close(int fd, char *line);

#endif
