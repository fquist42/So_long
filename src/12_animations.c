/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_animations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 22:43:36 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 22:20:33 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	animate_player_left(t_data *data, int timer);
static int	animate_player_right(t_data *data, int timer);
static int	animate_player_up(t_data *data, int timer);

int	animate_hook_up_down(t_data *data)
{
	refresh_background(data);
	if (data->then == 0)
		data->then = clock();
	animate_hook_left_right(data);
	if (data->key == W)
	{
		if (data->is_moving == true)
			animate_player_up(data, data->timer);
		else
			put_image_to_window(data, data->player->p_u1, data->enemy->e_u1);
	}
	else if (data->key == S)
	{
		if (data->is_moving == true)
			animate_player_up(data, data->timer);
		else
			put_image_to_window(data, data->player->p_u1, data->enemy->e_u1);
	}
	time_calc(data);
	return (0);
}

int	animate_hook_left_right(t_data *data)
{
	if (data->then == 0)
		data->then = clock();
	if (data->key == A)
	{
		if (data->is_moving == true)
			animate_player_left(data, data->timer);
		else
			put_image_to_window(data, data->player->p_l, data->enemy->e_l);
	}
	else if (data->key == D)
	{
		if (data->is_moving == true)
			animate_player_right(data, data->timer);
		else
			put_image_to_window(data, data->player->p_r, data->enemy->e_r);
	}
	time_calc(data);
	return (0);
}

static int	animate_player_left(t_data *data, int timer)
{
	if (data->i == 1)
		put_image_to_window(data, data->player->p_l1, data->enemy->e_l1);
	else if (data->i == 2)
		put_image_to_window(data, data->player->p_l2, data->enemy->e_l2);
	else if (data->i == 3)
		put_image_to_window(data, data->player->p_l3, data->enemy->e_l3);
	else if (data->i == 4)
		put_image_to_window(data, data->player->p_l4, data->enemy->e_l4);
	else if (data->i == 5)
		put_image_to_window(data, data->player->p_l5, data->enemy->e_l5);
	else if (data->i == 6)
	{
		put_image_to_window(data, data->player->p_l6, data->enemy->e_l6);
		if (timer)
			data->i = 0;
	}
	if (timer)
		data->i++;
	return (0);
}

static int	animate_player_right(t_data *data, int timer)
{
	if (data->i == 1)
		put_image_to_window(data, data->player->p_r1, data->enemy->e_r1);
	else if (data->i == 2)
		put_image_to_window(data, data->player->p_r2, data->enemy->e_r2);
	else if (data->i == 3)
		put_image_to_window(data, data->player->p_r3, data->enemy->e_r3);
	else if (data->i == 4)
		put_image_to_window(data, data->player->p_r4, data->enemy->e_r4);
	else if (data->i == 5)
		put_image_to_window(data, data->player->p_r5, data->enemy->e_r5);
	else if (data->i == 6)
	{
		put_image_to_window(data, data->player->p_r6, data->enemy->e_r6);
		if (timer)
			data->i = 0;
	}
	if (timer)
		data->i++;
	return (0);
}

static int	animate_player_up(t_data *data, int timer)
{
	if (data->i == 1)
		put_image_to_window(data, data->player->p_u1, data->enemy->e_u1);
	else if (data->i == 2)
		put_image_to_window(data, data->player->p_u2, data->enemy->e_u2);
	else if (data->i == 3)
		put_image_to_window(data, data->player->p_u3, data->enemy->e_u3);
	else if (data->i == 4)
		put_image_to_window(data, data->player->p_u4, data->enemy->e_u4);
	else if (data->i == 5)
		put_image_to_window(data, data->player->p_u5, data->enemy->e_u5);
	else if (data->i == 6)
	{
		put_image_to_window(data, data->player->p_u6, data->enemy->e_u6);
		if (timer)
			data->i = 0;
	}
	if (timer)
		data->i++;
	return (0);
}
