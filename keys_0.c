/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:28:57 by momihamm          #+#    #+#             */
/*   Updated: 2024/02/11 04:10:32 by momihamm         ###   ########.fr       */
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

void	makeValus(t_play *blanka)
{
	blanka->rotation_speed = 2 * (M_PI / 180);
	blanka->rotation_ang += blanka->turn_d * blanka->rotation_speed;
}

int	ft_move(int events, t_ray *obj)
{
	(void) obj;
	obj->playstation->turn_d = 0;
	obj->playstation->walk_d = 0;
	// parzival->walk_d = 0;
	if (events == 53)
		close_the_win ();
	else if (events == 124 || events == 2)
	{
		obj->playstation->turn_d = 1;
		printf ("1\n");
	}
	else if (events == 123 || events == 0)
		obj->playstation->turn_d = -1;
	else if (events == 126 || events == 13)
		obj->playstation->walk_d = 1;
	else if (events == 125 || events == 1)
		obj->playstation->walk_d = -1;
	// Update
	printf ("seg\n");
	makeValus(obj->playstation);
	printf ("seg0000 ===== \n");
	printf("p1 >>>>>>>>>> [%p]\n", obj->myImage);
	printf("p2 >>>>>>>>>> [%p]\n", obj->myImage->mlxImage);
	// exit(1);
	if (obj->myImage->mlxImage == NULL)
		printf ("werda\n");
	else
		printf ("kani m\n");
	mlx_destroy_image (obj->start, obj->myImage->mlxImage);
	printf ("seg1111111\n");
	return (0);
}

void	derictions(t_play *parzival, t_ray *obje, t_cub3d *usef)
{
	(void) usef;
	mlx_hook (obje->window, 2, 0, ft_move, parzival);
	mlx_hook (obje->window, 17, 0, close_the_win, NULL);
}
