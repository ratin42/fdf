/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 09:52:51 by ratin             #+#    #+#             */
/*   Updated: 2019/02/22 19:43:09 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	give_color(t_mlx *mlx)
{
	if (mlx->input.color == 1)
		return (0x2E2EFE);
	if (mlx->input.color == 2)
		return (0xFF0000);
	if (mlx->input.color == 3)
		return (0xFFFF00);
	if (mlx->input.color == 4)
		return (0x00FF00);
	return (0xffffff);
}

int	quit_fdf(void *mlx)
{
	mlx_clear_window(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->win_ptr);
	mlx_destroy_window(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->win_ptr);
	exit(1);
	return (0);
}

int	key_bis2(int key, void *mlx)
{
	if (key == 36)
	{
		if (((t_mlx *)mlx)->input.mouse == 0)
		{
			((t_mlx *)mlx)->input.mouse = 1;
			((t_mlx *)mlx)->input.mouse_x_save = ((t_mlx *)mlx)->input.mouse_x;
			((t_mlx *)mlx)->input.mouse_y_save = ((t_mlx *)mlx)->input.mouse_y;
		}
		else
			((t_mlx *)mlx)->input.mouse = 0;
	}
	else if (key == 8)
	{
		if (((t_mlx *)mlx)->input.color == 5)
			((t_mlx *)mlx)->input.color = 0;
		else
			((t_mlx *)mlx)->input.color++;
	}
	else if (key == 14)
		((t_mlx *)mlx)->input.hight_extend++;
	else if (key == 2)
		((t_mlx *)mlx)->input.hight_extend--;
	return (0);
}

int	key_bis(int key, void *mlx)
{
	if (key == 35)
	{
		if (((t_mlx *)mlx)->input.projection == 0)
			((t_mlx *)mlx)->input.projection = 1;
		else
			((t_mlx *)mlx)->input.projection = 0;
	}
	else if (key == 17)
	{
		if (((t_mlx *)mlx)->input.menu == 0)
			((t_mlx *)mlx)->input.menu = 1;
		else
			((t_mlx *)mlx)->input.menu = 0;
	}
	key_bis2(key, mlx);
	return (0);
}

int	handle_key(int key, void *mlx)
{
	if (key == 53)
		quit_fdf(mlx);
	else if (key == 3)
		((t_mlx *)mlx)->input.zoom -= 5;
	else if (key == 15)
		((t_mlx *)mlx)->input.zoom += 5;
	else if (key == 4)
		((t_mlx *)mlx)->input.x_position -= 8 + abs(((t_mlx *)mlx)->input.zoom);
	else if (key == 37)
		((t_mlx *)mlx)->input.x_position += 8 + abs(((t_mlx *)mlx)->input.zoom);
	else if (key == 38)
		((t_mlx *)mlx)->input.y_position += 8 + abs(((t_mlx *)mlx)->input.zoom);
	else if (key == 40)
		((t_mlx *)mlx)->input.y_position -= 8 + abs(((t_mlx *)mlx)->input.zoom);
	else if (key == 123)
		((t_mlx *)mlx)->input.z_rotation -= 0.1;
	else if (key == 124)
		((t_mlx *)mlx)->input.z_rotation += 0.1;
	else if (key == 45)
		((t_mlx *)mlx)->input.z_extend += 28 + abs(((t_mlx *)mlx)->input.zoom);
	else if (key == 34)
		((t_mlx *)mlx)->input.z_extend -= 28 + abs(((t_mlx *)mlx)->input.zoom);
	key_bis(key, mlx);
	return (0);
}
