/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 18:08:49 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 22:20:27 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_player(t_data *data, char pos, int dir)
{
	data->old_x = data->p_x;
	data->old_y = data->p_y;
	if (pos == 'x')
		data->p_x += dir;
	else
		data->p_y += dir;
	if (data->map->map[data->p_y][data->p_x] == '1')
	{
		data->p_x = data->old_x;
		data->p_y = data->old_y;
		return ;
	}
	if (data->map->map[data->p_y][data->p_x] == 'C')
		collect(data);
	if (data->map->map[data->p_y][data->p_x] == 'E')
		check_win_condition(data);
	player_lose(data);
	mlx_do_sync(data->mlx);
}

void	move_enemy(t_data *data, char pos, int dir)
{
	data->old_e_x = data->e_x;
	data->old_e_y = data->e_y;
	if (pos == 'y')
		data->e_y += dir;
	else
		data->e_x += dir;
	if ((!(data->map->map[data->e_y][data->e_x] == '0')
		&& !(data->map->map[data->e_y][data->e_x] == '2'))
		|| (data->p_x == data->e_x && data->p_y == data->e_y))
	{
		data->e_x = data->old_e_x;
		data->e_y = data->old_e_y;
	}
	mlx_do_sync(data->mlx);
}

void	collect(t_data *data)
{
	data->collected++;
	data->map->map[data->p_y][data->p_x] = '0';
	mlx_put_image_to_window(data->mlx, data->win, data->img->background,
		data->p_x * IMG_WIDTH, data->p_y * IMG_HEIGHT);
}

int	print_moves(t_data *data, t_img *img)
{
	char	*counter;

	counter = ft_itoa(++data->counter);
	mlx_put_image_to_window(data->mlx, data->win, img->wall, 0, 0);
	mlx_string_put(data->mlx, data->win, 14, 25, 16730068,
		"Moves");
	mlx_string_put(data->mlx, data->win, 25, 40, 16730068, counter);
	free(counter);
	return (0);
}
