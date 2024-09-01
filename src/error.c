/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 07:40:02 by gonische          #+#    #+#             */
/*   Updated: 2024/08/31 13:42:47 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	display_error(const char *err)
{
	write(STDERR_FILENO, "So_long Error: ", 7);
	write(STDERR_FILENO, err, ft_strlen(err));
	write(STDERR_FILENO, "\n", 1);
}

void	fatal_error(const char *err)
{
	display_error(err);
	exit(EXIT_FAILURE);
}
