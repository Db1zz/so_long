/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 05:35:26 by gonische          #+#    #+#             */
/*   Updated: 2024/09/04 15:06:30 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	move_character(int x, int y, t_game *data)
{
	static int	movement = 0;

	if (data->map[y][x] == C_BORDER || (data->map[y][x] == C_EXIT
		&& data->char_loot != data->map_loot))
		return ;
	if (data->map[y][x] == C_EXIT && data->map_loot == data->char_loot)
		exit_program(data);
	else if (data->map[y][x] == C_LOOT)
	{
		data->map[y][x] = C_EMPTY;
		render_texture(x, y, data->textures[4], data);
		data->char_loot++;
	}
	render_texture(data->char_pos.x, data->char_pos.y, data->textures[4], data);
	render_texture(x, y, data->textures[3], data);
	data->char_pos.x = x;
	data->char_pos.y = y;
	ft_printf("counter: %d\n", ++movement);
}

int	user_input_handler(int key, t_game *data)
{
	if (key == K_W)
		move_character(data->char_pos.x, data->char_pos.y - 1, data);
	else if (key == K_A)
		move_character(data->char_pos.x - 1, data->char_pos.y, data);
	else if (key == K_S)
		move_character(data->char_pos.x, data->char_pos.y + 1, data);
	else if (key == K_D)
		move_character(data->char_pos.x + 1, data->char_pos.y, data);
	else if (key == K_ESC)
		exit_program(data);
	return (0);
}
