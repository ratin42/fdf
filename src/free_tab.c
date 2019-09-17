/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 17:13:42 by ratin             #+#    #+#             */
/*   Updated: 2019/02/24 00:05:14 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	free_double_int(int **array, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_double_char(char **array)
{
	int i;

	i = 0;
	while (array[i] != 0)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int		handle_mouse(int x, int y, void *mlx)
{
	((t_mlx *)mlx)->input.mouse_x = x;
	((t_mlx *)mlx)->input.mouse_y = y;
	return (0);
}

int		invalid_file(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr("0123456789 -xABCDEFabcdef,", str[i]) == NULL)
			return (1);
		i++;
	}
	return (0);
}

void	do_the_close(int fd, char *line)
{
	if ((close(fd) < 0) || line == NULL)
	{
		free(line);
		exit(1);
	}
}
