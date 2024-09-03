/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 05:29:01 by gonische          #+#    #+#             */
/*   Updated: 2024/09/03 19:23:11 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_game	*data;

	if (argc == 2)
	{
		data = init_game(argv[1]);
		mlx_key_hook(data->mlx_win, &user_input_handler, data);
		mlx_loop(data->mlx);
	}
	return (0);
}
