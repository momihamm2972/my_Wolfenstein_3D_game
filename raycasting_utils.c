/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:44:11 by momihamm          #+#    #+#             */
/*   Updated: 2024/01/09 14:10:58 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"



float	deg2rad(float degrees)
{
	return (degrees * (M_PI / 180.0));
}

float	rad2deg(float radians)
{
	return (radians * (180.0 / M_PI));
}

void	make_square(int row, int clm, t_ray *object)
{
	(void)row;
	(void)clm;
	int	pi_x;
	int	pi_y;
	int	izaha_x;
	int	izaha_y;
	
	pi_x = 0;
	// pi_y = 0;
	izaha_x = clm * 32;
	izaha_y = row * 32;
	while (pi_x < 32)
	{
		pi_y = 0;
		while (pi_y < 32)
		{
			mlx_pixel_put (object->start, object->window, pi_x + izaha_x, pi_y + izaha_y, 0x005EFF);
			pi_y++;
		}
		pi_x++;
	}
	// mlx_pixel_put (object->start, object->window, 32, 0 , 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 31, 0 , 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 30, 0 , 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 29, 0 , 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 28, 0 , 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 27, 0 , 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 26, 0 , 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 25, 0 , 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 24, 0 , 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 23, 0 , 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 22, 0 , 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 21, 0 , 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 20, 0 , 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 19, 0 , 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 18, 0 , 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 17, 0 , 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 16, 0 , 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 15, 0 , 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 14, 0 , 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 13, 0 , 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 12, 0 , 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 11, 0 , 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 10, 0 , 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 9, 0, 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 8, 0, 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 7, 0, 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 6, 0, 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 5, 0, 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 4, 0, 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 3, 0, 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 2, 0, 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 1, 0, 0x005EFF);
	// mlx_pixel_put (object->start, object->window, 0, 0, 0x005EFF);
}

void	vr_game_map(t_ray *object, t_cub3d *yous_obj)
{
	int	row;
	int	clm;
	int	culor;

	row = 0;
	// clm = 0;
	(void) culor;
	while (yous_obj->map[row])
	{
		clm = 0;
		while (yous_obj->map[row][clm])
		{
			if (yous_obj->map[row][clm] == '1')
			{
				// mlx_pixel_put (object->start, object->window, row * 32, clm * 32 , 0x005EFF);
				// culor = 0x000000;÷
				make_square(row, clm, object);
			}
			// else if (yous_obj->map[row][clm] == '+')
			// {
			// 	mlx_pixel_put (object->start, object->window, row * 64, clm * 64 , 0xFF0000);
			// 	culor = 0xFF0000;
			// }
			// else
			// {
			// 	mlx_pixel_put (object->start, object->window, row * 64, clm * 64 , 0xFFFFFF);
			// 	culor = 0xFFFFFF;
			// }
			clm++;
		}
		row++;
	}
	
}
