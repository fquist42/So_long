/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   11_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:32:04 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 22:20:30 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	player_key_hook2(int keycode, t_data *data)
{
	if (keycode == A && !data->key_press_W && !data->key_press_D
		&& !data->key_press_S)
	{
		data->key_press_A = true;
		move_player(data, 'x', LEFT);
		move_enemy(data, 'x', LEFT);
	}
	else if (keycode == D && !data->key_press_A && !data->key_press_W
		&& !data->key_press_S)
	{
		data->key_press_D = true;
		move_player(data, 'x', RIGHT);
		move_enemy(data, 'x', RIGHT);
	}
	if (data->map->map[data->p_y][data->p_x] == 'E')
		player_won(data);
	if (keycode == A || keycode == S || keycode == D || keycode == W)
		data->key = keycode;
	return (0);
}

int	player_key_hook(int keycode, t_data *data)
{
	if (keycode == A || keycode == D || keycode == W || keycode == S)
		data->is_moving = true;
	print_moves(data, data->img);
	if (keycode == ESC)
		esc_exit(data);
	else if (keycode == W && !data->key_press_A && !data->key_press_D
		&& !data->key_press_S)
	{
		data->key_press_W = true;
		move_player(data, 'y', UP);
		move_enemy(data, 'y', UP);
	}
	else if (keycode == S && !data->key_press_A && !data->key_press_D
		&& !data->key_press_W)
	{
		data->key_press_S = true;
		move_player(data, 'y', DOWN);
		move_enemy(data, 'y', DOWN);
	}
	player_key_hook2(keycode, data);
	return (0);
}

int	key_hook_release(int keycode, t_data *data)
{
	if (keycode == A || keycode == S || keycode == D || keycode == W)
	{
		data->is_moving = false;
		data->key_press_W = false;
		data->key_press_A = false;
		data->key_press_S = false;
		data->key_press_D = false;
	}
	return (0);
}
