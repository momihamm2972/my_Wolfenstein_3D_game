/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:28:57 by momihamm          #+#    #+#             */
/*   Updated: 2024/02/12 02:02:22 by momihamm         ###   ########.fr       */
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
	int	moveStep;

	// printf ("every day00\n");
	// printf ("***{%p}***\n", blanka);
	blanka->rotation_speed = 2 * (M_PI / 180);
	// printf ("every day22\n");
	blanka->rotation_ang += blanka->turn_d * blanka->rotation_speed;
	// printf ("every day33\n");
	printf ("wach %d wesel %d lhna\n", blanka->x_play, blanka->y_play);
	moveStep = blanka->walk_d * blanka->move_speed;
	printf ("dolly %d  ** %d *** %f\n", moveStep, blanka->walk_d, blanka->move_speed);
	blanka->x_play += cos(blanka->rotation_ang) * moveStep; 
	blanka->y_play += sin(blanka->rotation_ang) * moveStep; 
	printf ("wach wesel lhna\n");
	printf ("wach %d wesel %d lhna %f \n\n\n\n\n", blanka->x_play, blanka->y_play, cos(blanka->rotation_ang) * moveStep);
}

void	resetVal(t_ray *obj)
{
	obj->playstation->turn_d = 0;
	obj->playstation->walk_d = 0;
}

int	ft_move(int events, void *object)
{
	// (void) obj;
	// (t_ray *) obj;
	t_ray *obj = (t_ray *) object;
	// printf ("#%p#\n", obj->playstation);
	// printf ("#%d#\n", obj->myImage->lenOfLine);
	// obj->playstation->turn_d = 0;
	// obj->playstation->walk_d = 0;
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
	else
		return (0);
	// Update
	// printf ("seg\n");
	makeValus(obj->playstation);
	// printf ("seg0000 ===== \n");
	// printf("p1 >>>>>>>>>> [%p]\n", obj->myImage);
	// printf("p2 >>>>>>>>>> [%p]\n", obj->myImage->mlxImage);
	// exit(1);
	// if (obj->myImage->mlxImage == NULL)
	// 	printf ("werda\n");
	// else
	// 	printf ("kani m\n");
	mlx_clear_window (obj->start, obj->window);
	mlx_destroy_image (obj->start, obj->myImage->mlxImage);
	obj->myImage->mlxImage = mlx_new_image (obj->start, obj->the_long_line * 32, obj->the_rows * 32);
	obj->myImage->dataAddr = mlx_get_data_addr (obj->myImage->mlxImage, &obj->myImage->intPerPixl, &obj->myImage->lenOfLine, &obj->myImage->end);
	// ft_draw (obj, obj->playstation);
	ft_again (obj);
	resetVal(object);
	// printf ("seg1111111\n");
	return (0);
}

void	derictions(t_play *parzival, t_ray *obje, t_cub3d *usef)
{
	(void) usef;
	mlx_hook (obje->window, 2, 0, ft_move, parzival);
	mlx_hook (obje->window, 17, 0, close_the_win, NULL);
}
