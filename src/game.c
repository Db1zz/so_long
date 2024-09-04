/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 05:33:16 by gonische          #+#    #+#             */
/*   Updated: 2024/09/04 14:37:55 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_character_pos(t_game *data)
{
	int	x;
	int	y;

	if (!data)
		return ;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == C_PLAYER)
			{
				data->char_pos.x = x;
				data->char_pos.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

t_game	*init_game(const char *map_path)
{
	t_game	*data;

	data = ft_calloc(1, sizeof(t_game));
	if (!data)
		fatal_error("init_game ft_calloc() failed to allocate memory.");
	parse_map(data, map_path);
	data->mlx = mlx_init();
	get_textures(data);
	data->mlx_win = mlx_new_window(data->mlx, data->win_rect.w,
			data->win_rect.h, "so_long");
	render_map(data);
	return (data);
}
