/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 09:56:35 by ratin             #+#    #+#             */
/*   Updated: 2019/02/20 22:41:00 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			put_horizon(t_point *point, t_mlx *mlx, int x, int y)
{
	double	cste;

	cste = 0.8;
	point[1].x = point[0].x + (mlx->map.size + mlx->input.zoom);
	point[1].y = point[0].y;
	point[1].x = point[1].x + cste * mlx->map.map[y][x + 1];
	point[1].y = point[1].y + (cste / 2) * mlx->map.map[y][x + 1];
	print_lines(&point[0], &point[1], mlx);
	return (0);
}

int			put_verti(t_point *point, t_mlx *mlx, int x, int y)
{
	double	cste;

	cste = 0.8;
	point[1].x = point[0].x;
	point[1].y = point[0].y + (mlx->map.size + mlx->input.zoom);
	point[1].x = point[1].x + cste * mlx->map.map[y + 1][x];
	point[1].y = point[1].y + (cste / 2) * mlx->map.map[y + 1][x];
	print_lines(&point[0], &point[1], mlx);
	return (0);
}

void		put_map(t_point *point, t_mlx *mlx)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	if (mlx->input.projection == 1)
		tile_size_para(point, mlx);
	else
		tile_size(point, mlx);
	while (y < mlx->map.height)
	{
		x = -1;
		while (++x < mlx->map.width - 1)
		{
			print_lines(&point[i], &point[i + 1], mlx);
			if (y < mlx->map.height - 1)
				print_lines(&point[i], &point[(mlx->map.width) + i], mlx);
			i++;
		}
		if (y < mlx->map.height - 1)
			print_lines(&point[i], &point[(mlx->map.width) + i], mlx);
		i++;
		y++;
	}
}
