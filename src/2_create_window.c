/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_create_window.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:39:28 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 22:19:59 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	count_line_length(int fd);
static int	count_lines(int fd, int x, int img_width);

void	create_window(t_data *data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		error("\e[0;31mError\nMap not found. Please check your input.\e[0m\n");
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		error("\e[0;31mError\nInput datatype is expected to be '.ber'\e[0m\n");
	data->s_x = (count_line_length(fd) * IMG_WIDTH);
	data->s_y = count_lines(fd, data->s_x, IMG_WIDTH) * IMG_HEIGHT;
}

static int	count_line_length(int fd)
{
	char	buffer[1];
	int		len;
	int		bytes;

	buffer[0] = '\0';
	bytes = 1;
	len = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			len++;
		else
			break ;
	}
	return (len);
}

static int	count_lines(int fd, int x, int img_width)
{
	char	buffer[1];
	int		linecount;
	int		bytes;
	int		i;

	i = 0;
	buffer[0] = '\0';
	linecount = 1;
	bytes = 1;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (bytes != 1 && i != (x / img_width))
			error_exit();
		if (i == (x / img_width))
		{
			linecount++;
			i = 0;
		}
		else
			i++;
	}
	return (linecount);
}
