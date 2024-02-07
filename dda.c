/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:01:43 by momihamm          #+#    #+#             */
/*   Updated: 2024/02/07 23:01:09 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void    dda(t_cub3d *usef, t_ray *strahl, t_play *parzival)
{
	(void) usef;
	(void) strahl;
	int	destX;
	int	destY;
	double	mayl;
	// int	newX;
	// int	newY;

	// destX = parzival->x_play + (cos(parzival->rotation_ang) * 10);
	// destY = parzival->y_play + (sin(parzival->rotation_ang) * 10);
	destX = parzival->x_play + 10;
	destY = parzival->y_play + 10;
	mayl = 0;
	printf ("X<%d>Y<%d>\t%f\nrot$$$$$$$$$$$$>>%f\n",destX, destY, mayl, parzival->rotation_ang);
	mayl = (destX - parzival->x_play) / (destY - parzival->y_play);
	if (mayl == 1)
	{
		strahl->rad = 1;
		printf ("increment by 1\n");
	}
	else if (mayl < 1 )
	{
		strahl->rad = 0;
		printf ("small\n");
	}
	else if (mayl > 1)
	{
		strahl->rad = 2;
		printf ("BIG\n");
	}
}