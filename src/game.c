/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 05:33:16 by gonische          #+#    #+#             */
/*   Updated: 2024/09/03 16:59:07 by gonische         ###   ########.fr       */
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
