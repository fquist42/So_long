/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:49:49 by fquist            #+#    #+#             */
/*   Updated: 2022/03/17 20:59:17 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ************************************************************************** */
/* STANDARD INCLUDES														  */
/* ************************************************************************** */
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <time.h>
# include "../libs/libft/include/libft.h"
# include "../mlx/mlx.h"

/* ************************************************************************** */
/* DEFINES																	  */
/* ************************************************************************** */
# define IMG_WIDTH 64
# define IMG_HEIGHT 64
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP -1
# define DOWN 1
# define LEFT -1
# define RIGHT 1

/* ************************************************************************** */
/* STRUCTURES																  */
/* ************************************************************************** */
typedef struct s_map
{
	char	**map;
	void	*object;
	int		x;
	int		y;
	int		collectable;
}				t_map;

typedef struct s_img
{
	void	*wall;
	void	*background;
}				t_img;

typedef struct s_player
{
	void	*p_l;
	void	*p_r;
	void	*p_u1;
	void	*p_u2;
	void	*p_u3;
	void	*p_u4;
	void	*p_u5;
	void	*p_u6;
	void	*p_r1;
	void	*p_r2;
	void	*p_r3;
	void	*p_r4;
	void	*p_r5;
	void	*p_r6;
	void	*p_l1;
	void	*p_l2;
	void	*p_l3;
	void	*p_l4;
	void	*p_l5;
	void	*p_l6;
}				t_player;

typedef struct s_enemy
{
	void	*e_u1;
	void	*e_u2;
	void	*e_u3;
	void	*e_u4;
	void	*e_u5;
	void	*e_u6;
	void	*e_r;
	void	*e_l;
	void	*e_r1;
	void	*e_r2;
	void	*e_r3;
	void	*e_r4;
	void	*e_r5;
	void	*e_r6;
	void	*e_l1;
	void	*e_l2;
	void	*e_l3;
	void	*e_l4;
	void	*e_l5;
	void	*e_l6;
}				t_enemy;

typedef struct s_data
{
	t_player	*player;
	t_enemy		*enemy;
	t_map		*map;
	t_img		*img;
	void		*mlx;
	void		*win;
	int			s_x;
	int			s_y;
	int			p_x;
	int			p_y;
	int			e_x;
	int			e_y;
	int			counter;
	int			collected;
	int			key;
	int			old_x;
	int			old_y;
	int			old_e_x;
	int			old_e_y;
	bool		is_moving;
	bool		e_is_moving;
	bool		key_press_W;
	bool		key_press_A;
	bool		key_press_S;
	bool		key_press_D;
	bool		timer;
	int			i;
	clock_t		then;
	clock_t		now;
}				t_data;

/* ************************************************************************** */
/* CREATE WINDOW															  */
/* ************************************************************************** */
void	create_window(t_data *data, char **argv);

/* ************************************************************************** */
/* ERRORS AND EXITS															  */
/* ************************************************************************** */
void	error_exit(void);
void	malloc_error(char *error_obj);
void	time_calc(t_data *data);
int		esc_exit(t_data *data);
void	input_error(int argc);
void	error(char *error_message);

/* ************************************************************************** */
/* INIT STRUCTS																  */
/* ************************************************************************** */
void	init_map_struct(t_data *data, t_map *map);
void	init_player_struct(t_data *data);
void	init_enemy_struct(t_data *data);

/* ************************************************************************** */
/* PARSER																	  */
/* ************************************************************************** */
void	parser(t_data *data, char **argv, int argc);

/* ************************************************************************** */
/* CREATE MAP																  */
/* ************************************************************************** */
void	init_background(t_data *data);
void	create_map(t_data *data);
int		render_next_frame(t_data *data);

/* ************************************************************************** */
/* MOVEMENT																	  */
/* ************************************************************************** */
void	move_player(t_data *data, char pos, int dir);
void	move_enemy(t_data *data, char pos, int dir);
void	collect(t_data *data);
int		print_moves(t_data *data, t_img *img);

/* ************************************************************************** */
/* HOOKS																	  */
/* ************************************************************************** */
int		player_key_hook(int keycode, t_data *data);
int		player_key_hook2(int keycode, t_data *data);
int		key_hook_release(int keycode, t_data *data);

/* ************************************************************************** */
/* ANIMATIONS																  */
/* ************************************************************************** */
void	refresh_background(t_data *data);
int		animate_hook_up_down(t_data *data);
int		animate_hook_left_right(t_data *data);
void	put_image_to_window(t_data *data, void *p_xpm, void *e_xpm);

/* ************************************************************************** */
/* WIN_LOSE																	  */
/* ************************************************************************** */
void	check_win_condition(t_data *data);
void	player_won(t_data *data);
void	player_lose(t_data *data);

#endif
