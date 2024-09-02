/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 05:35:26 by gonische          #+#    #+#             */
/*   Updated: 2024/09/02 23:06:27 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	get_direction_object(int key, t_game *data)
{
	
}

int user_input_handler(int key, t_game *data)
{
	if (key == K_W)
		ft_printf("W\n");
	else if (key == K_A)
		ft_printf("A\n");
	else if (key == K_S)
		ft_printf("S\n");
	else if (key == K_D)
		ft_printf("D\n");
}
