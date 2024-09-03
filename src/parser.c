/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 05:33:19 by gonische          #+#    #+#             */
/*   Updated: 2024/09/03 20:16:48 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	get_map_size(t_game *data, const char *map_path)
{
	char	*line;
	int		fd;
	int		line_lenght;

	if (!data)
		fatal_error("get_map_size data is NULL.");
	fd = open(map_path, O_RDONLY, 0644);
	if (fd < 0)
		fatal_error("Map cannot be opened or it does not exist.");
	line = get_next_line(fd);
	while (line)
	{
		line_lenght = ft_strlen(line);
		free(line);
		if (data->map_size.x == 0)
			data->map_size.x = line_lenght;
		if (data->map_size.x > line_lenght || data->map_size.x < line_lenght)
		{
			destroy_data(data);
			fatal_error("Lines are of different lenght.");
		}
		data->map_size.y++;
		line = get_next_line(fd);
	}
	close(fd);
}

static void	load_map(t_game *data, const char *map_path)
{
	int		fd;
	int		i;

	get_map_size(data, map_path);
	if (!data->map_size.y || !data->map_size.x)
		fatal_error("parse_map incorrect map size.");
	fd = open(map_path, O_RDONLY);
	data->map = ft_calloc(data->map_size.y + 1, sizeof(char *));
	if (!data->map)
	{
		destroy_data(data);
		fatal_error("parse_map ft_calloc() failed to allocate memory.");
	}
	i = 0;
	while (i < data->map_size.y)
		data->map[i++] = get_next_line(fd);
	close(fd);
}

static bool	is_map_valid(t_game *data)
{
	int	exit;	

	exit = 0;
	if (!check_borders((const char **)data->map, &data->map_size))
		return (false);
	if (!get_items(&data->map_loot, &exit, data->map))
		return (false);
	if (!are_objectives_reachable(data))
		return (false);
	return (true);
}

void	parse_map(t_game *data, const char *map_path)
{
	if (!data)
		fatal_error("parse_map data is NULL.");
	load_map(data, map_path);
	get_character_pos(data);
	data->win_rect.w = data->map_size.x * TEXTURE_W;
	data->win_rect.h = data->map_size.y * TEXTURE_H;
	if (!is_map_valid(data))
	{
		destroy_data(data);
		fatal_error("Map is not valid.");
	}
}
