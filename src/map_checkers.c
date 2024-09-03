/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 08:29:55 by gonische          #+#    #+#             */
/*   Updated: 2024/09/03 19:13:25 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	check_borders(const char **map, const t_pos *size)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (!(x >= size->x && y >= size->y))
	{
		if (x < size->x
			&& (map[0][x] != C_BORDER || map[size->y - 1][x] != C_BORDER))
			return (false);
		if (y < size->y
			&& (map[y][0] != C_BORDER || map[y][size->x - 1] != C_BORDER))
			return (false);
		x++;
		y++;
	}
	return (true);
}

bool	get_items(int *loot, int *exit, char **map)
{
	int		x;
	int		y;

	if (!map)
		return (false);
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == C_LOOT)
				(*loot)++;
			else if (map[y][x] == C_EXIT)
				(*exit)++;
			x++;
		}
		y++;
	}
	if (*loot > 0 && *exit == 1)
		return (true);
	return (false);
}

static void	dfs(int x, int y, t_pos map_size, char **map)
{
	if ((x <= 0 || y <= 0) || (x >= map_size.x || y >= map_size.y)
		|| map[y][x] == C_BORDER)
		return ;
	if (map[y][x] == C_EXIT)
	{
		map[y][x] = C_BORDER;
		return ;
	}
	map[y][x] = C_BORDER;
	dfs(x + 1, y, map_size, map);
	dfs(x - 1, y, map_size, map);
	dfs(x, y + 1, map_size, map);
	dfs(x, y - 1, map_size, map);
}

bool	are_objectives_reachable(t_game *data)
{
	char	**map_copy;
	int		loot;
	int		exit;

	loot = 0;
	exit = 0;
	map_copy = cpy_2dmatrix(data->map);
	if (!map_copy)
	{
		destroy_data(data);
		fatal_error(ERROR_MALLOC);
	}
	dfs(data->char_pos.x, data->char_pos.y, data->map_size, map_copy);
	get_items(&loot, &exit, map_copy);
	free_2dmatrix(map_copy);
	return (loot == 0 && exit == 0);
}
