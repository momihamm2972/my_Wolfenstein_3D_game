/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:44:11 by momihamm          #+#    #+#             */
/*   Updated: 2024/02/07 22:16:42 by momihamm         ###   ########.fr       */
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

void	the_values_of_vue(int *var, int *x_)
{
	*var -= 2;
	*x_ += 1;
	if (*var <= 0)
	{
		*var = 0;
		*x_ = 0;
	}
}

void	make_vue(int row, int clm, t_ray *object)
{
	int	var[6];

	var[4] = clm * 32;
	var[5] = row * 32;
	var[0] = 16;
	var[1] = 8;
	var[2] = 0;
	object->colur = 0x00FF3B;
	while (var[2] < 32)
	{
		var[3] = 0;
		while (var[3] < 32)
		{
			if (var[3] == var[1])
				var[3] += var[0];
			// mlx_pixel_put (object->start, object->window, var[3] + var[4],
			// 	var[2] + var[5], object->colur);
			putPixImg (object->myImage, var[3] + var[4], var[2] + var[5],
			object->colur);
			var[3]++;
		}
		var[2]++;
		if (var >= 0)
			the_values_of_vue (&var[0], &var[1]);
	}
}

void	make_square(int row, int clm, t_ray *object, t_cub3d *yous)
{
	int	pi_x;
	int	pi_y;
	int	izaha_x;
	int	izaha_y;

	pi_x = 0;
	izaha_x = clm * 32;
	izaha_y = row * 32;
	if (yous->map[row][clm] == '1')
		object->colur = 0x005EFF;
	else if ((yous->map[row][clm]) == '0')
		object->colur = 0xFFFFFF;
	else if ((yous->map[row][clm]) == '+')
		object->colur = 0xB200FF;
	else
		object->colur = 0xFFFFFF;
	while (pi_x < 32)
	{
		// printf ("dkhel\n");
		pi_y = 0;
		while (pi_y < 32)
		{
			putPixImg (object->myImage, pi_x + izaha_x, pi_y + izaha_y , object->colur);
			pi_y++;
		}
		pi_x++;
	}
}
