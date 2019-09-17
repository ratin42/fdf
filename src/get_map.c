/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ratin <ratin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 03:42:17 by ratin             #+#    #+#             */
/*   Updated: 2019/02/24 00:33:47 by ratin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	open_file(char *str)
{
	int		fd;

	if ((fd = open(str, O_RDONLY)) == -1)
		exit(1);
	return (fd);
}

char		*read_file(char *str)
{
	char	*line;
	char	*map;
	int		i;
	int		fd;

	i = 0;
	line = NULL;
	if (!(map = (char *)malloc(sizeof(char))))
		return (0);
	strcpy(map, "");
	fd = open_file(str);
	while ((get_next_line(fd, &line)) == 1)
	{
		if (invalid_file(line) == 1)
		{
			free(line);
			exit(1);
		}
		if (!(map = ft_strjoin_free(map, line, 3)))
			return (0);
		if (!(map = ft_strjoin_free(map, "\n", 1)))
			return (0);
	}
	do_the_close(fd, line);
	return (map);
}

char		**make_tab(char *str)
{
	char	*map;
	char	**tab;

	if (!(map = read_file(str)))
		return (0);
	if (!(tab = ft_strsplit((const char *)map, '\n')))
		return (0);
	free(map);
	return (tab);
}

/*
** malloc mlx.map.map
*/

int			fill_map(int i, char **line, t_mlx *mlx)
{
	int		j;

	j = 0;
	if (!(mlx->map.map[i] = (int *)malloc(sizeof(int) * mlx->map.width)))
		return (0);
	while (j < mlx->map.width)
	{
		mlx->map.map[i][j] = ft_atoi(line[j]);
		j++;
	}
	return (1);
}

int			make_map(char *str, t_mlx *mlx)
{
	char	**line;
	char	**tab;
	int		i;

	i = 0;
	if (!(tab = make_tab(str)))
		return (0);
	mlx->map.height = ft_count_words_tables(tab);
	if (!(mlx->map.map = (int **)malloc(sizeof(int *) * mlx->map.height)))
		return (0);
	mlx->map.size = 64;
	while (tab[i] != '\0')
	{
		if (!(line = ft_strsplit((const char *)tab[i], ' ')))
			return (0);
		mlx->map.width = ft_count_words_tables(line);
		if (!(fill_map(i, line, mlx)))
			return (0);
		free_double_char(line);
		i++;
	}
	free_double_char(tab);
	return (1);
}
