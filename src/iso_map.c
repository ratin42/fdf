/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 04:40:32 by ratin             #+#    #+#             */
/*   Updated: 2019/02/22 19:55:29 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		dtoiso(t_point *point, t_mlx *mlx)
{
	double	u;
	double	v;
	double	cste;
	double	cste2;

	cste = 0.5;
	cste2 = 0.7;
	u = (cste * point->x) - (cste2 * point->y);
	v = ((-point->z + mlx->input.z_extend) / 7 * mlx->input.hight_extend)
	+ ((cste / 2)
	* point->x) + ((cste2 / 2) * point->y);
	point->x = u;
	point->y = v;
}

void		dtopara(t_point *point, t_mlx *mlx)
{
	double	u;
	double	v;
	double	cste;
	double	cste2;

	cste = 0.5;
	cste2 = 0.7;
	u = point->x + (cste * (-point->z + mlx->input.z_extend) / 7
	* mlx->input.hight_extend);
	v = point->y + ((cste / 2) * (-point->z + mlx->input.z_extend) / 7
	* mlx->input.hight_extend);
	point->x = u;
	point->y = v;
}

t_point		*iso_map(t_mlx *mlx)
{
	t_point	*point;
	int		x;
	int		y;
	int		i;

	if (!(point = (t_point *)malloc(sizeof(t_point) * (mlx->map.width
	* mlx->map.height))))
		return (0);
	i = 0;
	y = 0;
	while (y < mlx->map.height)
	{
		x = 0;
		while (x < mlx->map.width)
		{
			point[i].x = x;
			point[i].y = y;
			point[i].z = mlx->map.map[y][x];
			x++;
			i++;
		}
		y++;
	}
	return (point);
}
