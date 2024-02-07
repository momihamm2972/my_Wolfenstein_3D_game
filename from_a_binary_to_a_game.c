/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_a_binary_to_a_game.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:41:58 by momihamm          #+#    #+#             */
/*   Updated: 2024/02/07 22:58:54 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	check_is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	init_player(t_play *ready, t_cub3d *usef)
{
	// ready->x_play = 0;
	// ready->y_play = 0;
	getCurntPosi (ready, usef);
	ready->turn_d = 0;
	ready->walk_d = 0;
	ready->rotation_ang = 0;
	ready->move_speed = 0.0;
	ready->rotation_speed = 0.0;
}

// charq .. ready->rotation_ang = M_PI / 2;
// north .. 

void	make_a_strahl(t_ray *obje,t_play *parzival, int row, int clm, int rad)
{
	int	len;
	int	x;
	int	y;

	(void) row;
	(void) clm;
	(void) parzival;
	(void) rad;
	// int val;
	len = 0;
	// x = (clm * 32) + 16;
	// y = (row * 32);
	x = (parzival->x_play * 32) + 16;
	y = (parzival->y_play * 32) + 16;
	printf ("%d    -- %d\n",x, y);
	while (len < 10)
	{
		printf ("kmi >> %d\n", len);
		// mlx_pixel_put (obje->start, obje->window, x, y, 0xFF0000);
		// putPixStrahl(obje->myImage, x  , y  , obje->colur, obje);
		putPixImg(obje->myImage, x  , y  , obje->colur);
		// if (val == 1)
		// {
		// 	printf ("30ans\n");
		// 	return ;
		// }
		if (rad < 1)
		{
			x = round (x);
			y = round (y);
			x++;
			y += rad;
			y = round (y);
		}
		else if (rad == 1)
		{
			x = round (x);
			y = round (y);
			x++;
			y++;
		}
		else if (rad > 1)
		{
			x = round (x);
			y = round (y);
			x += x + (1 / rad);
			y++;
		}
		len++;
	}
}

void	vr_game_map(t_ray *object, t_cub3d *yous_obj, t_play *parzival)
{
	int		row;
	int		clm;

	row = 0;
	while (yous_obj->map[row])
	{
		clm = 0;
		while (yous_obj->map[row][clm])
		{
			// printf ("====>>elctro\n");
			if (yous_obj->map[row][clm] == '1')
				make_square(row, clm, object, yous_obj);
			else if (yous_obj->map[row][clm] == '+')
				make_square (row, clm, object, yous_obj);
			if (check_is_player (yous_obj->map[row][clm]) == 1)
			{
				// make_vue (row, clm, object);
				make_square (row, clm, object, yous_obj);
				object->colur = 0xEE0505;
				dda(yous_obj, object, parzival);
				make_a_strahl (object, parzival, row, clm, object->rad);
				// object->colur = 0x00FF00;
				// parzival->rotation_ang = M_PI / 2;
				// dda(yous_obj, object, parzival);
				// make_a_strahl (object, parzival, row, clm, object->rad);
			}
			// else
			// 	make_square (row, clm, object, yous_obj);
			clm++;
		}
		row++;
	}
	mlx_put_image_to_window (object->start, object->window, object->myImage->mlxImage, 0,0);
	derictions (parzival, object, yous_obj);
}
