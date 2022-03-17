/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:49:05 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 22:21:17 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	*strjoin(char *s1, const char *s2);
static void	check_content(t_data *data);
static void	check_borders(t_data *data);

void	parser(t_data *data, char **argv, int argc)
{
	int		fd;
	int		i;
	int		bytes;
	char	buffer[2];

	input_error(argc);
	i = 0;
	bytes = 1;
	buffer[1] = '\0';
	fd = open(argv[1], O_RDONLY);
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes != 1)
			break ;
		if (buffer[0] != '\n' && buffer[0] != '\0')
			data->map->map[i] = strjoin(data->map->map[i], buffer);
		else
			i++;
	}
	check_content(data);
	check_borders(data);
}

static void	check_content(t_data *data)
{
	int	y;
	int	exit;
	int	player;
	int	enemy;

	exit = 0;
	player = 0;
	enemy = 0;
	data->map->collectable = 0;
	y = -1;
	while (data->map->map && data->map->map[++y])
	{
		exit += ft_count_c(data->map->map[y], 'E');
		player += ft_count_c(data->map->map[y], 'P');
		enemy += ft_count_c(data->map->map[y], '2');
		data->map->collectable += ft_count_c(data->map->map[y], 'C');
	}
	if (player != 1)
		error("\e[0;31mError\nThere is no or to many player(s) on the map.\e[0m\n");
	if (exit == 0)
		error("\e[0;31mError\nThere is no exit on the map.\e[0m\n");
	if (data->map->collectable == 0)
		error("\e[0;31mError\nThere is no collectable on the map\e[0m\n");
	if (enemy == 0)
		error("\e[0;31mError\nThere is no enemy on the map\e[0m\n");
}

static void	check_borders(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < (data->s_y / IMG_HEIGHT))
	{
		if ((int)ft_strlen(data->map->map[y]) != data->s_x / IMG_WIDTH)
			error("\e[0;31mError\nMap has to be rectangular.\e[0m\n");
		x = 0;
		while (x < (data->s_x / IMG_WIDTH))
		{
			if (data->map->map[y][x] != '0' && data->map->map[y][x] != '1' &&
				data->map->map[y][x] != 'C' && data->map->map[y][x] != 'P' &&
				data->map->map[y][x] != 'E' && data->map->map[y][x] != '2')
				error("\e[0;31mError.\nOnly '0','1','2','C','P','E'"
					" are valid.\e[0m\n");
			else if ((y == 0 || x == 0) && data->map->map[y][x] != '1')
				error("\e[0;31mError.\nMap has to be surrounded by walls.\e[0m\n");
			else if ((y == (data->s_y / IMG_HEIGHT - 1)
					|| x == (data->s_x / IMG_HEIGHT - 1))
				&& data->map->map[y][x] != '1')
				error("\e[0;31mError.\nMap has to be surrounded by walls.\e[0m\n");
			x++;
		}
	}
}

static char	*strjoin(char *s1, const char *s2)
{
	char	*c;
	int		i;
	int		i2;

	if (!s2)
		return (NULL);
	i = 0;
	i2 = 0;
	c = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (c == NULL)
		return (0);
	while (s1 && s1[i] != '\0')
	{
		c[i] = s1[i];
		i++;
	}
	while (s2[i2] != '\0')
		c[i++] = s2[i2++];
	c[i] = '\0';
	free(s1);
	s1 = NULL;
	return (c);
}
