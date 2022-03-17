/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:30:10 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 22:19:55 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_map	map;

	(void)argc;
	create_window(&data, argv);
	map.map = ft_calloc(data.s_y + 1, sizeof(char *));
	if (!map.map)
		malloc_error("map");
	data.mlx = mlx_init();
	if (!data.mlx)
		malloc_error("mlx");
	init_map_struct(&data, &map);
	init_player_struct(&data);
	init_enemy_struct(&data);
	parser(&data, argv, argc);
	data.win = mlx_new_window(data.mlx, data.s_x, data.s_y, "~* S0 L0NG *~");
	init_background(&data);
	create_map(&data);
	render_next_frame(&data);
	mlx_loop(data.mlx);
	perror("\e[0;31mError\nFailed to sustain mlx loop.\e[0m\n");
	exit(EXIT_FAILURE);
	return (0);
}

int	render_next_frame(t_data *data)
{
	mlx_hook(data->win, 2, 1L << 0, player_key_hook, data);
	mlx_hook(data->win, 3, 1L << 3, key_hook_release, data);
	mlx_hook(data->win, 17, 1L << 0, esc_exit, data);
	mlx_loop_hook(data->mlx, animate_hook_up_down, data);
	return (0);
}
