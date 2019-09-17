/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 00:49:09 by ratin             #+#    #+#             */
/*   Updated: 2019/02/21 00:03:45 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	if (y < HEIGHT && y > 0 && x < WIDTH && x > 0)
		mlx->img.data[y * WIDTH + x] = color;
	return (0);
}

int			print_lines(t_point *point1, t_point *point2, t_mlx *mlx)
{
	if (point1->y <= point2->y)
		put_line(point1, point2, mlx);
	else
		put_line(point2, point1, mlx);
	return (0);
}

/*
** print vertical lines for print_lines
*/

void		vertical_limit(t_point *point1, t_point *point2, t_mlx *mlx)
{
	int		y;

	y = point1->y;
	while (y < point2->y)
	{
		ft_put_pixel(mlx, point1->x, y, give_color(mlx));
		y++;
	}
}

/*
** add size of tiles to every points
*/

void		tile_size(t_point *point, t_mlx *mlx)
{
	int		i;

	i = 0;
	while (i < mlx->map.width * mlx->map.height)
	{
		point[i].x = point[i].x * (mlx->map.size + (mlx->input.zoom))
		+ (HEIGHT - (mlx->input.zoom * 8)) + mlx->input.x_position;
		point[i].y = point[i].y * (mlx->map.size + (mlx->input.zoom))
		- (mlx->input.zoom * 4) + mlx->input.y_position;
		point[i].z = point[i].z * (mlx->map.size + (mlx->input.zoom));
		dtoiso(&point[i], mlx);
		if (mlx->input.mouse == 1)
		{
			point[i].x += mlx->input.mouse_x - mlx->input.mouse_x_save;
			point[i].y += mlx->input.mouse_y - mlx->input.mouse_y_save;
		}
		i++;
	}
}

void		tile_size_para(t_point *point, t_mlx *mlx)
{
	int		i;

	i = 0;
	while (i < mlx->map.width * mlx->map.height)
	{
		point[i].x = point[i].x * (mlx->map.size + (mlx->input.zoom))
		- ((mlx->input.zoom * 9)) + mlx->input.x_position;
		point[i].y = point[i].y * (mlx->map.size + (mlx->input.zoom))
		+ (WIDTH / 6 - (mlx->input.zoom * 5)) + mlx->input.y_position;
		point[i].z = point[i].z * (mlx->map.size + (mlx->input.zoom));
		dtopara(&point[i], mlx);
		i++;
	}
}
