/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_init_enemy_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 20:33:47 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 22:20:17 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_enemy_textures(t_data *data);
static void	init_enemy_textures2(t_data *data, int x, int y);

void	init_enemy_struct(t_data *data)
{
	t_enemy		*enemy;

	enemy = malloc(sizeof(t_enemy));
	if (!enemy)
		malloc_error("enemy");
	data->enemy = enemy;
	init_enemy_textures(data);
}

static void	init_enemy_textures(t_data *data)
{
	int		y;
	int		x;

	data->enemy->e_l = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy/e_left.xpm", &x, &y);
	data->enemy->e_r = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy/e_right.xpm", &x, &y);
	data->enemy->e_u1 = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy/e_u1.xpm", &x, &y);
	data->enemy->e_u2 = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy/e_u2.xpm", &x, &y);
	data->enemy->e_u3 = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy/e_u3.xpm", &x, &y);
	data->enemy->e_u4 = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy/e_u4.xpm", &x, &y);
	data->enemy->e_u5 = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy/e_u5.xpm", &x, &y);
	data->enemy->e_u6 = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy/e_u6.xpm", &x, &y);
	init_enemy_textures2(data, x, y);
}

static void	init_enemy_textures2(t_data *data, int x, int y)
{
	data->enemy->e_r1 = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy/e_r1.xpm", &x, &y);
	data->enemy->e_r2 = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy/e_r2.xpm", &x, &y);
	data->enemy->e_r3 = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy/e_r3.xpm", &x, &y);
	data->enemy->e_r4 = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy/e_r4.xpm", &x, &y);
	data->enemy->e_r5 = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy/e_r5.xpm", &x, &y);
	data->enemy->e_r6 = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy/e_r6.xpm", &x, &y);
	data->enemy->e_l1 = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy/e_l1.xpm", &x, &y);
	data->enemy->e_l2 = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy/e_l2.xpm", &x, &y);
	data->enemy->e_l3 = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy/e_l3.xpm", &x, &y);
	data->enemy->e_l4 = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy/e_l4.xpm", &x, &y);
	data->enemy->e_l5 = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy/e_l5.xpm", &x, &y);
	data->enemy->e_l6 = mlx_xpm_file_to_image(data->mlx,
			"./textures/enemy/e_l6.xpm", &x, &y);
}
