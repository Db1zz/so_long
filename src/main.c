/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 05:29:01 by gonische          #+#    #+#             */
/*   Updated: 2024/09/04 14:42:08 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	exit_program(t_game *data)
{
	destroy_data(data);
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*data;

	if (argc == 2)
	{
		data = init_game(argv[1]);
		mlx_hook(data->mlx_win, 2, 1, user_input_handler, data);
		mlx_hook(data->mlx_win, 17, 1L << 17, exit_program, data);
		mlx_loop(data->mlx);
	}
	return (0);
}
