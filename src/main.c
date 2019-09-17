/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 08:07:11 by ratin             #+#    #+#             */
/*   Updated: 2019/02/24 00:35:43 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		menu_bis(t_mlx *mlx)
{
	mlx_string_put(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->win_ptr, 10,
	100, 0xffffff, "K : UP TRANSLATION");
	mlx_string_put(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->win_ptr, 10,
	120, 0xffffff, "L : RIGHT TRANSLATION");
	mlx_string_put(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->win_ptr, 10,
	140, 0xffffff, "I : Z TRANSLATION +");
	mlx_string_put(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->win_ptr, 10,
	160, 0xffffff, "N : Z TRANSLATION -");
	mlx_string_put(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->win_ptr, 10,
	180, 0xffffff, "P : PROJECTION");
	mlx_string_put(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->win_ptr, 10,
	200, 0xffffff, "C : COLOR");
	mlx_string_put(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->win_ptr, 10,
	220, 0xffffff, "E : HEIGHT +");
	mlx_string_put(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->win_ptr, 10,
	240, 0xffffff, "D : HEIGHT -");
	mlx_string_put(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->win_ptr, 10,
	260, 0xffffff, "ENTER : MOUSE MOVE");
}

int			print_menu(t_mlx *mlx)
{
	if (mlx->input.menu == 1)
	{
		mlx_string_put(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->win_ptr, 10,
		0, 0xffffff, "T : CLOSE MENU");
		mlx_string_put(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->win_ptr, 10,
		20, 0xffffff, "R : ZOOM +");
		mlx_string_put(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->win_ptr, 10,
		40, 0xffffff, "F : ZOOM -");
		mlx_string_put(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->win_ptr, 10,
		60, 0xffffff, "H : LEFT TRANSLATION");
		mlx_string_put(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->win_ptr, 10,
		80, 0xffffff, "J : DOWN TRANSLATION");
		menu_bis(mlx);
	}
	else
		mlx_string_put(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->win_ptr, 10, 0,
		0xffffff, "T : MENU");
	return (0);
}

int			draw(void *mlx)
{
	t_point	*point;

	mlx_clear_window(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->win_ptr);
	mlx_destroy_image(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->img.img_ptr);
	((t_mlx *)mlx)->img.img_ptr = mlx_new_image(((t_mlx *)mlx)->mlx_ptr, WIDTH,
	HEIGHT);
	((t_mlx *)mlx)->img.data = (int *)mlx_get_data_addr(
	((t_mlx *)mlx)->img.img_ptr, &((t_mlx *)mlx)->img.bpp,
	&((t_mlx *)mlx)->img.size_l, &((t_mlx *)mlx)->img.endian);
	if (!(point = iso_map((t_mlx *)mlx)))
		return (0);
	put_map(point, (t_mlx *)mlx);
	free(point);
	mlx_put_image_to_window(((t_mlx *)mlx)->mlx_ptr, ((t_mlx *)mlx)->win_ptr,
	((t_mlx *)mlx)->img.img_ptr, 0, 0);
	print_menu((t_mlx *)mlx);
	return (0);
}

int			init_mlx(t_mlx *mlx)
{
	if (!(mlx->mlx_ptr = mlx_init()))
		return (0);
	mlx->input.mouse_x = 0;
	mlx->input.mouse_y = 0;
	mlx->input.projection = 0;
	mlx->input.zoom = -10;
	mlx->input.menu = 0;
	mlx->input.hight_extend = 1;
	mlx->input.z_extend = 0;
	mlx->input.color = 0;
	mlx->input.x_position = 0;
	mlx->input.y_position = 0;
	mlx->input.z_rotation = 0;
	return (1);
}

int			main(int ac, char **av)
{
	t_mlx	mlx;

	if (ac != 2)
		return (0);
	if (!(make_map(av[1], &mlx)))
		return (0);
	if (!(init_mlx(&mlx)))
		return (0);
	if (!(mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, "FDF")))
		return (0);
	if (!(mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIDTH, HEIGHT)))
		return (0);
	mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp,
	&mlx.img.size_l, &mlx.img.endian);
	mlx_hook(mlx.win_ptr, KeyPress, PointerMotionMask, handle_key,
	(void *)&mlx);
	mlx_hook(mlx.win_ptr, MotionNotify, PointerMotionMask, handle_mouse,
	(void *)&mlx);
	mlx_hook(mlx.win_ptr, DestroyNotify, PointerMotionMask, quit_fdf,
	(void *)&mlx);
	mlx_loop_hook(mlx.mlx_ptr, draw, &mlx);
	mlx_loop(mlx.mlx_ptr);
	free_double_int(mlx.map.map, mlx.map.height);
	return (0);
}
