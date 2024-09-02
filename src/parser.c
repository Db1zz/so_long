/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 05:33:19 by gonische          #+#    #+#             */
/*   Updated: 2024/09/02 22:58:37 by gonische         ###   ########.fr       */
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
		if (data->map_rect.w == 0)
			data->map_rect.w = line_lenght;
		if (data->map_rect.w > line_lenght
			|| data->map_rect.w < line_lenght)
		{
			destroy_data(data);
			fatal_error("Lines are of different width.");
		}
		data->map_rect.h++;
		line = get_next_line(fd);
	}
	close(fd);
}

static void	load_map(t_game *data, const char *map_path)
{
	int		fd;
	int		i;

	get_map_size(data, map_path);
	if (!data->map_rect.h|| !data->map_rect.w)
		fatal_error("parse_map incorrect map size.");
	fd = open(map_path, O_RDONLY);
	data->map = ft_calloc(data->map_rect.h + 1, sizeof(char *));
	if (!data->map)
	{
		destroy_data(data);
		fatal_error("parse_map ft_calloc() failed to allocate memory.");	
	}
	i = 0;
	while (i < data->map_rect.h)
		data->map[i++] = get_next_line(fd);
	close(fd);
}

static bool	is_map_valid(t_game *data)
{
	// Check borders
	// if (!check_borders((const char **)data->map, &data->map_rect))
	// 	return (false);
	// Check gates
	
	// Check loot

	// Check path to the door and loot

	// Check size
	return (true);
}

static void	parse_map(t_game *data, const char *map_path)
{
	// TODO: Init rect variable.
	if (!data)
		fatal_error("parse_map data is NULL.");
	load_map(data, map_path);
	if (!is_map_valid(data))
	{
		destroy_data(data);
		fatal_error("Map is not valid.");
	}
	data->win_rect.w = data->map_rect.w * TEXTURE_W;
	data->win_rect.h = data->map_rect.h * TEXTURE_H;
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
	// TODO: Calculate the width and height size of the window by map size * texture size
	data->mlx_win = mlx_new_window(data->mlx, data->win_rect.w, data->win_rect.h, "so_long");
	// Render Whole map
	render_map(data);
	// Install comrade hook
	mlx_key_hook(data->mlx_win, &user_input_handler, data);
	// mlx_hook(data->mlx_win, 2, 1, );
	// Put everythin in the mlx loop
	mlx_loop(data->mlx);
	return (data);
}
