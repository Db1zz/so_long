/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 05:37:37 by gonische          #+#    #+#             */
/*   Updated: 2024/09/03 19:03:31 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	free_textures(t_game *data)
{
	int	i;

	if (!data)
		fatal_error("free_textures: t_game * is NULL");
	i = 0;
	while (data->textures[i])
		mlx_destroy_image(data->mlx, data->textures[i++]);
}

void	free_2dmatrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}

void	destroy_data(t_game *data)
{
	if (!data)
		fatal_error("Tried to free t_game which was not allocated.");
	if (data->map)
		free_2dmatrix(data->map);
	free_textures(data);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data);
}

static size_t	get_2dmatrix_size(char **matrix)
{
	size_t	i;

	i = 0;
	while (matrix[i])
		i++;
	return (i);
}

char	**cpy_2dmatrix(char **to_copy)
{
	char	**result;
	size_t	result_size;
	size_t	i;

	if (!to_copy)
		return (NULL);
	result_size = get_2dmatrix_size(to_copy);
	result = ft_calloc(result_size + 1, sizeof(char *));
	i = 0;
	while (i < result_size)
	{
		result[i] = ft_strdup(to_copy[i]);
		if (!result[i])
		{
			free_2dmatrix(result);
			return (NULL);
		}
		i++;
	}
	return (result);
}
