/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 08:29:55 by gonische          #+#    #+#             */
/*   Updated: 2024/09/03 13:09:50 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	check_borders(const char **map, const t_rect *rect)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (!(i >= rect->w && j >= rect->h))
	{
		// Check top and bottom
		if (i < rect->w && (map[0][i] != C_BORDER || map[rect->h - 1][i] != C_BORDER))
			return (false);
		// Check sides
		if (j < rect->h && (map[j][0] != C_BORDER || map[j][rect->w - 1] != C_BORDER))
			return (false);
		i++;
		j++;
	}
	return (true);
}

bool	check_items(t_game *data)
{
	int		x;
	int		y;
	int		exit;

	y = 0;
	exit = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == C_LOOT)
				data->map_loot++;
			else if (data->map[y][x] == C_EXIT)
				exit++;
			x++;
		}
		y++;
	}
	if (data->map_loot > 0 && exit == 1)
		return (true);
	return (false);
}

void	flood_fill()
{
	
}
