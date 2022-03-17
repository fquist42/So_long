/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_init_map_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:17:42 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 22:20:10 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_map_struct(t_data *data, t_map *map)
{
	int		img_width;
	int		img_height;
	t_img	*img;

	data->map = map;
	img = malloc(sizeof(t_img));
	if (!img)
		malloc_error("img");
	data->img = img;
	data->img->background = mlx_xpm_file_to_image(data->mlx,
			"./textures/world/floor.xpm", &img_width, &img_height);
	data->img->wall = mlx_xpm_file_to_image(data->mlx,
			"./textures/world/wall.xpm", &img_width, &img_height);
}
