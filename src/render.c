/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 05:37:35 by gonische          #+#    #+#             */
/*   Updated: 2024/09/02 16:51:57 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	get_textures(t_game *data)
{
	char *paths[5] = {
		"/home/gonische/Desktop/projects/so_long/textures/Coat.xpm",
		"/home/gonische/Desktop/projects/so_long/textures/Dirt.xpm",
		"/home/gonische/Desktop/projects/so_long/textures/Glass.xpm",
		"/home/gonische/Desktop/projects/so_long/textures/Stone.xpm",
		"/home/gonische/Desktop/projects/so_long/textures/Wood.xpm"
	};
	int	i;

	data->textures_rect.w = TEXTURE_W;
	data->textures_rect.h = TEXTURE_H;
	i = 0;
	while (i < 5)
	{
		data->textures[i] = mlx_xpm_file_to_image(data->mlx, paths[i],
			&data->textures_rect.w, &data->textures_rect.h);
		if (!data->textures[i])
		{
			destroy_data(data);
			fatal_error("Cannot load texture, check your path");
		}
		i++;
	}
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
	fatal_error("Did you check your map lol");
	return (NULL);
}

void	render_map(t_game *data)
{
	int		x;
	int 	y;
	int		i;
	int		j;
	void	*img;

	i = 0;
	y = 0;
	while (data->map[i])
	{
		j = 0;
		x = 0;
		while (data->map[i][j])
		{
			img = map_char_to_img(data, data->map[i][j++]);
			mlx_put_image_to_window(data->mlx, data->mlx_win, img, x, y);
			x += TEXTURE_W;
		}
		i++;
		y += TEXTURE_H;
	}
}
