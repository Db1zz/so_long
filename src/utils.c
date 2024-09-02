/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 05:37:37 by gonische          #+#    #+#             */
/*   Updated: 2024/09/02 19:21:34 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_2dmatrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

static void	free_textures(t_game *data)
{
	int	i;

	if (!data)
		fatal_error("free_textures: t_game * is NULL");
	i = 0;
	while (data->textures[i])
		mlx_destroy_image(data->mlx, data->textures[i++]);
}

void	destroy_data(t_game *data)
{
	if (!data)
		fatal_error("Trying to free data which was not allocated.");
	if (data->map)
		free_2dmatrix(data->map);
	free_textures(data);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	#ifdef __linux__
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	#endif //__linux__
	free(data);
}
