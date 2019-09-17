/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 22:03:33 by ratin             #+#    #+#             */
/*   Updated: 2019/02/20 23:47:11 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	line1(t_point *point1, t_point *point2, t_mlx *mlx)
{
	int		x;
	int		y;
	t_line	line;

	x = point1->x;
	y = point1->y;
	line.dp = 2 * (point2->y - point1->y) - (point2->x - point1->x);
	line.delta_e = 2 * (point2->y - point1->y);
	line.delta_ne = 2 * ((point2->y - point1->y) - (point2->x - point1->x));
	ft_put_pixel(mlx, x, y, give_color(mlx));
	while (x < point2->x)
	{
		if (line.dp <= 0)
			line.dp = line.dp + line.delta_e;
		else
		{
			line.dp = line.dp + line.delta_ne;
			y++;
		}
		x++;
		ft_put_pixel(mlx, x, y, give_color(mlx));
	}
	return (0);
}

static int	line2(t_point *point1, t_point *point2, t_mlx *mlx)
{
	int		x;
	int		y;
	t_line	line;

	x = point1->x;
	y = point1->y;
	line.dp = 2 * (point2->x - point1->x) - (point2->y - point1->y);
	line.delta_e = 2 * (point2->x - point1->x);
	line.delta_ne = 2 * ((point2->x - point1->x) - (point2->y - point1->y));
	ft_put_pixel(mlx, x, y, give_color(mlx));
	if (x == point2->x)
		vertical_limit(point1, point2, mlx);
	while (x < point2->x)
	{
		if (line.dp <= 0)
			line.dp = line.dp + line.delta_e;
		else
		{
			line.dp = line.dp + line.delta_ne;
			x++;
		}
		y++;
		ft_put_pixel(mlx, x, y, give_color(mlx));
	}
	return (0);
}

static int	line3(t_point *point1, t_point *point2, t_mlx *mlx)
{
	int		x;
	int		y;
	t_line	line;

	x = point1->x;
	y = point1->y;
	line.dp = 2 * (point2->y - point1->y) - (point1->x - point2->x);
	line.delta_e = 2 * (point2->y - point1->y);
	line.delta_ne = 2 * ((point2->y - point1->y) - (point1->x - point2->x));
	ft_put_pixel(mlx, x, y, give_color(mlx));
	while (x > point2->x)
	{
		if (line.dp <= 0)
			line.dp = line.dp + line.delta_e;
		else
		{
			line.dp = line.dp + line.delta_ne;
			y++;
		}
		x--;
		ft_put_pixel(mlx, x, y, give_color(mlx));
	}
	return (0);
}

static int	line4(t_point *point1, t_point *point2, t_mlx *mlx)
{
	int		x;
	int		y;
	t_line	line;

	x = point1->x;
	y = point1->y;
	line.dp = 2 * (point1->x - point2->x) - (point2->y - point1->y);
	line.delta_e = 2 * (point1->x - point2->x);
	line.delta_ne = 2 * ((point1->x - point2->x) - (point2->y - point1->y));
	ft_put_pixel(mlx, x, y, give_color(mlx));
	while (x > point2->x)
	{
		if (line.dp <= 0)
			line.dp = line.dp + line.delta_e;
		else
		{
			line.dp = line.dp + line.delta_ne;
			x--;
		}
		y++;
		ft_put_pixel(mlx, x, y, give_color(mlx));
	}
	return (0);
}

int			put_line(t_point *point1, t_point *point2, t_mlx *mlx)
{
	if (point2->x >= point1->x)
	{
		if ((point2->x - point1->x) >= (point2->y - point1->y))
			line1(point1, point2, mlx);
		if ((point2->x - point1->x) < (point2->y - point1->y))
			line2(point1, point2, mlx);
	}
	if (point2->x < point1->x)
	{
		if ((point1->x - point2->x) >= (point2->y - point1->y))
			line3(point1, point2, mlx);
		if ((point1->x - point2->x) <= (point2->y - point1->y))
			line4(point1, point2, mlx);
	}
	return (0);
}
