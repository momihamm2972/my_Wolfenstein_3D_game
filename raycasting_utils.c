/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:44:11 by momihamm          #+#    #+#             */
/*   Updated: 2024/01/09 16:53:41 by momihamm         ###   ########.fr       */
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
void	make_vue (int row, int clm, t_ray *object)
{
	int	pi_x;
	int	pi_y;
	int	izaha_x;
	int	izaha_y;
	int _x_;
	int var;
	
	pi_x = 0;
	izaha_x = clm * 32;
	izaha_y = row * 32;
	_x_ = 8;
	var = 16;
	while (pi_x < 32)
	{
		pi_y = 0;
		while (pi_y < 32)
		{
			if (pi_y == _x_)
				pi_y+= var;
			mlx_pixel_put (object->start, object->window, pi_y + izaha_x, pi_x + izaha_y, object->colur);
			pi_y++;
		}
		pi_x++;
		if (var >= 0)
		{
			var -= 2;
			_x_++;
			if (var <= 0)
			{
				var = 0;
				_x_ = 0;
			}
		}
	}
}

void	make_square(int row, int clm, t_ray *object)
{
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
			mlx_pixel_put (object->start, object->window, pi_x + izaha_x, pi_y + izaha_y, object->colur);
			pi_y++;
		}
		pi_x++;
	}
	// int	pi_x;
	// int	pi_y;
	// int	izaha_x;
	// int	izaha_y;
	// int _x_;
	// int var;
	
	// pi_x = 0;
	// izaha_x = clm * 32;
	// izaha_y = row * 32;
	// _x_ = 8;
	// var = 16;
	// while (pi_x < 32)
	// {
	// 	pi_y = 0;
	// 	while (pi_y < 32)
	// 	{
	// 		if (pi_y == _x_)
	// 			pi_y+= var;
	// 		mlx_pixel_put (object->start, object->window, pi_y + izaha_x, pi_x + izaha_y, object->colur);
	// 		pi_y++;
	// 	}
	// 	pi_x++;
	// 	if (var >= 0)
	// 	{
	// 		var -= 2;
	// 		_x_++;
	// 		if (var <= 0)
	// 		{
	// 			var = 0;
	// 			_x_ = 0;
	// 		}
	// 	}
	// }
}

void	vr_game_map(t_ray *object, t_cub3d *yous_obj)
{
	int	row;
	int	clm;
	// int	culor;

	row = 0;
	// clm = 0;
	// (void) culor;
	while (yous_obj->map[row])
	{
		clm = 0;
		while (yous_obj->map[row][clm])
		{
			if (yous_obj->map[row][clm] == '1')
			{
				// mlx_pixel_put (object->start, object->window, row * 32, clm * 32 , 0x005EFF);
				object->colur = 0x005EFF;
				make_square(row, clm, object);
			}
			else if (yous_obj->map[row][clm] == '+')
			{
				// mlx_pixel_put (object->start, object->window, row * 64, clm * 64 , 0xFF0000);
				object->colur = 0xFF0000;
				make_square (row, clm, object);
			}
			else if (yous_obj->map[row][clm] == 'N' || yous_obj->map[row][clm] == 'S' || yous_obj->map[row][clm] == 'E' || yous_obj->map[row][clm] == 'W')
			{
				// mlx_pixel_put (object->start, object->window, row * 64, clm * 64 , 0xFF0000);
				object->colur = 0xFF00FF;
				make_vue (row, clm, object);
			}
			else
			{
				// mlx_pixel_put (object->start, object->window, row * 64, clm * 64 , 0xFFFFFF);
				object->colur = 0xFFFFFF;
				make_square (row, clm, object);
			}
			clm++;
		}
		row++;
	}
	
}
