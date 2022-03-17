/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   14_win_or_lose.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:02:27 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 22:20:41 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_win_condition(t_data *data)
{
	if (data->map->collectable - data->collected != 0)
	{
		printf("\e[0;35mYou are not leaving without my tapes!\e[0m\n"
			"\e[0;37m%3d tapes\e[0m \e[0;35mare still lost!\e[0m\n",
			(data->map->collectable - data->collected));
		data->p_x = data->old_x;
		data->p_y = data->old_y;
	}
	else
		player_won(data);
}

void	player_won(t_data *data)
{
	printf("\e[0;32mYou won!\e[0m\n");
	printf("\e[0;32mCongratulations, "
		"you found all the lost tapes and the exit. Me like mucho!\e[0m\n");
	printf("\e[0;32mBut are \e[0;37m%d moves\e[0m \e[0;32mthe best you can do?"
		"\e[0m\n", data->counter);
	exit(EXIT_SUCCESS);
}

void	player_lose(t_data *data)
{
	if (data->p_x == data->e_x && data->p_y == data->e_y)
	{
		printf("\e[0;35mOh no! The Biker got you! Unfortunately i won't pay your"
			" hospital bill...\e[0m\n");
		if (data->collected != data->map->collectable)
		{
			printf("\e[0;37m\n%3d tapes\e[0m \e[0;35mare still lost!\e[0m\n",
				(data->map->collectable - data->collected));
		}
		exit(EXIT_SUCCESS);
	}
}
