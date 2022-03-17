/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   13_animation_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:31:26 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 22:20:37 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_image_to_window(t_data *data, void *p_xpm, void *e_xpm)
{
	mlx_put_image_to_window(data->mlx, data->win, p_xpm,
		data->p_x * IMG_WIDTH, data->p_y * IMG_HEIGHT);
	mlx_put_image_to_window(data->mlx, data->win, e_xpm,
		data->e_x * IMG_WIDTH, data->e_y * IMG_HEIGHT);
}

void	refresh_background(t_data *data)
{
	data->map->x = 0;
	data->map->y = 0;
	while (data->map->y < (data->s_y / IMG_HEIGHT))
	{
		if (data->map->map[data->map->y][data->map->x] == '0'
			|| data->map->map[data->map->y][data->map->x] == 'P'
			|| data->map->map[data->map->y][data->map->x] == '2')
			mlx_put_image_to_window(data->mlx, data->win,
				data->img->background, data->map->x * IMG_WIDTH,
				data->map->y * IMG_HEIGHT);
		if (data->map->x < (data->s_x / IMG_WIDTH))
			data->map->x++;
		else
		{
			data->map->y++;
			data->map->x = 0;
		}
	}
}
