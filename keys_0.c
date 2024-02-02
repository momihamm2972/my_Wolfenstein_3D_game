/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:28:57 by momihamm          #+#    #+#             */
/*   Updated: 2024/02/01 11:45:20 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	close_the_win(void)
{
	exit (0);
}

// void	set_zero(t_play *werda)
// {
// 	werda->turn_d = 0;
// 	werda->walk_d = 0;
// }

int	ft_move(int events, t_play *parzival)
{
	parzival->turn_d = 0;
	parzival->walk_d = 0;
	if (events == 53)
		close_the_win ();
	else if (events == 124 || events == 2)
		parzival->turn_d = 1;
	else if (events == 123 || events == 0)
		parzival->turn_d = -1;
	else if (events == 126 || events == 13)
		parzival->walk_d = 1;
	else if (events == 125 || events == 1)
		parzival->walk_d = -1;
	parzival->turn_d = 0;
	parzival->walk_d = 0;
	return (0);
}

void	derictions(t_play *parzival, t_ray *obje, t_cub3d *usef)
{
	(void) usef;
	mlx_hook (obje->window, 2, 0, ft_move, parzival);
	mlx_hook (obje->window, 17, 0, close_the_win, NULL);
}
