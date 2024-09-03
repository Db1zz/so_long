/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 05:35:26 by gonische          #+#    #+#             */
/*   Updated: 2024/09/03 20:22:32 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	move_character(int x, int y, t_game *data)
{
	if (data->map[y][x] == C_BORDER || (data->map[y][x] == C_EXIT
		&& data->char_loot != data->map_loot))
		return ;
	if (data->map[y][x] == C_EXIT && data->map_loot == data->char_loot)
	{
		destroy_data(data);
		exit(EXIT_SUCCESS);
	}
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
}

int	user_input_handler(int key, t_game *data)
{
	ft_printf("x: %d y: %d\n", data->char_pos.x, data->char_pos.y);
	ft_printf("%d\n", data->char_loot);
	if (key == K_W)
		move_character(data->char_pos.x, data->char_pos.y - 1, data);
	else if (key == K_A)
		move_character(data->char_pos.x - 1, data->char_pos.y, data);
	else if (key == K_S)
		move_character(data->char_pos.x, data->char_pos.y + 1, data);
	else if (key == K_D)
		move_character(data->char_pos.x + 1, data->char_pos.y, data);
	else if (key == K_ESC)
	{
		destroy_data(data);
		exit(EXIT_SUCCESS);
	}
	return (0);
}
