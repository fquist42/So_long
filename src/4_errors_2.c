/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_errors_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 23:38:36 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 22:20:08 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	input_error(int	argc)
{
	if (argc != 2)
	{
		error("\e[0;31mError\nUsage  >>  $./SO_LONG MAP_PATH/MAP_NAME.ber'\e[0m\n");
		exit(EXIT_FAILURE);
	}
}

void	error(char *error_message)
{
	printf("%s", error_message);
	exit(EXIT_FAILURE);
}
