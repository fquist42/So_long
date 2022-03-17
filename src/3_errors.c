/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_errors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:44:39 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 22:20:05 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	error_exit(void)
{
	printf("\e[0;31mError\nInvalid map dimensions.\e[0m\n");
	exit(EXIT_FAILURE);
}

int	esc_exit(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	printf("\e[0;31mPlayer left early. Bad impression.\e[0m\n");
	printf("\e[0;31mI'am sad and i'll exit now...\e[0m\n");
	exit(EXIT_SUCCESS);
}

void	malloc_error(char *error_obj)
{
	perror("\e[0;31mError\e[0m\nLocation: main.c\n");
	printf("\e[0;31mMemory allocation for '%s' failed.\e[0m\n", error_obj);
	exit(EXIT_FAILURE);
}

void	time_calc(t_data *data)
{
	data->timer = 0;
	data->now = clock();
	if (data->now - data->then > (clock_t)40 * (CLOCKS_PER_SEC / 10000))
	{
		data->then = 0;
		data->timer = 1;
	}
}
