/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 05:37:35 by gonische          #+#    #+#             */
/*   Updated: 2024/09/04 19:58:44 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_textures(t_game *data)
{
	int			i;
	const char	*paths[TEXTURE_BUFFER_SIZE] = {
		"textures/Border.xpm", "textures/Exit.xpm", "textures/Loot.xpm",
		"textures/Player.xpm", "textures/Empty.xpm"};

	data->textures_rect.w = TEXTURE_W;
	data->textures_rect.h = TEXTURE_H;
	i = 0;
	while (i < 5)
	{
		data->textures[i] = mlx_xpm_file_to_image(data->mlx, (char *)paths[i],
				&data->textures_rect.w, &data->textures_rect.h);
		if (!data->textures[i])
		{
			destroy_data(data);
			fatal_error("Cannot load texture, check your path");
		}
		i++;
	}
}

void	render_texture(int x, int y, void *texture, t_game *data)
{
	mlx_put_image_to_window(data->mlx, data->mlx_win, texture,
		x * TEXTURE_W, y * TEXTURE_H);
}

void	*map_char_to_img(t_game *data, char c)
{
	if (c == C_BORDER)
		return (data->textures[0]);
	if (c == C_EXIT)
		return (data->textures[1]);
	if (c == C_LOOT)
		return (data->textures[2]);
	if (c == C_PLAYER)
		return (data->textures[3]);
	if (c == C_EMPTY)
		return (data->textures[4]);
	destroy_data(data);
	fatal_error("Found invalid character");
	return (NULL);
}

void	render_map(t_game *data)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			img = map_char_to_img(data, data->map[y][x]);
			render_texture(x, y, img, data);
			x++;
		}
		y++;
	}
}
