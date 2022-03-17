/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   8_create_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:13:47 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 22:20:20 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_player(t_data *data);
static void	init_enemy(t_data *data);
static void	init_object(t_data *data, char *relative_path);

void	create_map(t_data *data)
{
	data->map->x = 0;
	data->map->y = 0;
	while (data->map->y < (data->s_y / IMG_HEIGHT))
	{
		if (data->map->map[data->map->y][data->map->x] == 'P')
			init_player(data);
		else if (data->map->map[data->map->y][data->map->x] == '2')
			init_enemy(data);
		else if (data->map->map[data->map->y][data->map->x] == '1')
			init_object(data, "./textures/world/wall.xpm");
		else if (data->map->map[data->map->y][data->map->x] == 'C')
			init_object(data, "./textures/objects/collectable.xpm");
		else if (data->map->map[data->map->y][data->map->x] == 'E')
			init_object(data, "./textures/objects/exit.xpm");
		if (data->map->x < (data->s_x / IMG_WIDTH))
			data->map->x++;
		else
		{
			data->map->y++;
			data->map->x = 0;
		}
	}
}

static void	init_player(t_data *data)
{
	data->p_x = data->map->x;
	data->p_y = data->map->y;
	data->old_x = data->p_x;
	data->old_y = data->p_y;
	data->is_moving = false;
}

static void	init_enemy(t_data *data)
{
	data->e_x = data->map->x;
	data->e_y = data->map->y;
	data->old_e_x = data->e_x;
	data->old_e_y = data->e_y;
	data->e_is_moving = false;
}

static void	init_object(t_data *data, char *relative_path)
{
	int	img_width;
	int	img_height;

	data->map->object = mlx_xpm_file_to_image(data->mlx, relative_path,
			&img_width, &img_height);
	mlx_put_image_to_window(data->mlx, data->win, data->map->object,
		(data->map->x * IMG_WIDTH), (data->map->y * IMG_HEIGHT));
}

void	init_background(t_data *data)
{
	int		y;
	int		x;

	y = 0;
	while (y < data->s_y)
	{
		x = 0;
		while (x < data->s_x)
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->img->background, x, y);
			x += IMG_WIDTH;
		}
		y += IMG_HEIGHT;
	}
}
