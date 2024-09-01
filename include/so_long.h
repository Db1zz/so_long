/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 05:29:47 by gonische          #+#    #+#             */
/*   Updated: 2024/09/01 14:43:50 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdbool.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

/*
	Macroses
*/
# define C_BORDER '1'
# define C_EXIT	'E'
# define C_LOOT	'C'
# define C_PLAYER 'P'
# define C_EMPTY '0'

# define TEXTURE_W 80
# define TEXTURE_H 80

/*
	Structs
*/

typedef struct t_rect
{
	int	w;
	int	h;
}	t_rect;

typedef struct t_game
{
	char	**map;
	void	*textures[5];
	t_rect	textures_rect;
	t_rect	map_rect;
	void	*mlx;
	void	*mlx_win;
	t_rect	win_rect;
}	t_game;

/*
	parser.c
*/
t_game	*init_game(const char *map_path);

/*
	render.c
*/
void	get_textures(t_game *data);
void	render_map(t_game *data);

/*

	error.c
*/
void	display_error(const char *err);
void	fatal_error(const char *err);

/*
	map_checker.c
*/
bool	check_borders(const char **map, const t_rect *rect);

/*
	utils.c
*/
void	free_2dmatrix(char **matrix);
void	destroy_data(t_game *data);


#endif // SO_LONG_H