/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 05:33:16 by gonische          #+#    #+#             */
/*   Updated: 2024/09/03 01:31:06 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_character_pos(t_game *data)
{	
	int	i;
	int	j;

	if (!data)
		return ;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == C_PLAYER)
			{
				data->char_pos.x = j;
				data->char_pos.y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}
