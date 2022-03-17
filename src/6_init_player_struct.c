/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_init_player_struct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:11:51 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 22:20:14 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_player_textures(t_data *data);
static void	init_player_textures2(t_data *data, int x, int y);

void	init_player_struct(t_data *data)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		malloc_error("player");
	data->player = player;
	init_player_textures(data);
	data->key = D;
	data->i = 1;
	data->timer = 1;
	data->counter = 0;
	data->collected = 0;
}

static void	init_player_textures2(t_data *data, int x, int y)
{
	data->player->p_r1 = mlx_xpm_file_to_image(data->mlx,
			"./textures/player/p_r1.xpm", &x, &y);
	data->player->p_r2 = mlx_xpm_file_to_image(data->mlx,
			"./textures/player/p_r2.xpm", &x, &y);
	data->player->p_r3 = mlx_xpm_file_to_image(data->mlx,
			"./textures/player/p_r3.xpm", &x, &y);
	data->player->p_r4 = mlx_xpm_file_to_image(data->mlx,
			"./textures/player/p_r4.xpm", &x, &y);
	data->player->p_r5 = mlx_xpm_file_to_image(data->mlx,
			"./textures/player/p_r5.xpm", &x, &y);
	data->player->p_r6 = mlx_xpm_file_to_image(data->mlx,
			"./textures/player/p_r6.xpm", &x, &y);
	data->player->p_l1 = mlx_xpm_file_to_image(data->mlx,
			"./textures/player/p_l1.xpm", &x, &y);
	data->player->p_l2 = mlx_xpm_file_to_image(data->mlx,
			"./textures/player/p_l2.xpm", &x, &y);
	data->player->p_l3 = mlx_xpm_file_to_image(data->mlx,
			"./textures/player/p_l3.xpm", &x, &y);
	data->player->p_l4 = mlx_xpm_file_to_image(data->mlx,
			"./textures/player/p_l4.xpm", &x, &y);
	data->player->p_l5 = mlx_xpm_file_to_image(data->mlx,
			"./textures/player/p_l5.xpm", &x, &y);
	data->player->p_l6 = mlx_xpm_file_to_image(data->mlx,
			"./textures/player/p_l6.xpm", &x, &y);
}

static void	init_player_textures(t_data *data)
{
	int		y;
	int		x;

	data->player->p_l = mlx_xpm_file_to_image(data->mlx,
			"./textures/player/player_left.xpm", &x, &y);
	data->player->p_r = mlx_xpm_file_to_image(data->mlx,
			"./textures/player/player_right.xpm", &x, &y);
	data->player->p_u1 = mlx_xpm_file_to_image(data->mlx,
			"./textures/player/p_u1.xpm", &x, &y);
	data->player->p_u2 = mlx_xpm_file_to_image(data->mlx,
			"./textures/player/p_u2.xpm", &x, &y);
	data->player->p_u3 = mlx_xpm_file_to_image(data->mlx,
			"./textures/player/p_u3.xpm", &x, &y);
	data->player->p_u4 = mlx_xpm_file_to_image(data->mlx,
			"./textures/player/p_u4.xpm", &x, &y);
	data->player->p_u5 = mlx_xpm_file_to_image(data->mlx,
			"./textures/player/p_u5.xpm", &x, &y);
	data->player->p_u6 = mlx_xpm_file_to_image(data->mlx,
			"./textures/player/p_u6.xpm", &x, &y);
	init_player_textures2(data, x, y);
}
