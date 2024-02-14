/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:44:11 by momihamm          #+#    #+#             */
/*   Updated: 2024/02/14 04:48:11 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

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
			put_pix_img (object->my_image, var[3] + var[4], var[2] + var[5],
				object->colur);
			var[3]++;
		}
		var[2]++;
		if (var >= 0)
			the_values_of_vue (&var[0], &var[1]);
	}
}

void	player_and_culor(t_ray *obj, int row, int clm)
{
	if (obj->game_map[row][clm] == '1')
		obj->colur = 0x005EFF;
	else if ((obj->game_map[row][clm]) == '0')
		obj->colur = 0xFFFFFF;
	else if ((obj->game_map[row][clm]) == '+')
		obj->colur = 0xB200FF;
	else
		obj->colur = 0xFFFFFF;
}

void	make_square(int row, int clm, t_ray *object)
{
	int	var[5];

	var[0] = 0;
	var[1] = clm * 32;
	var[2] = row * 32;
	var[3] = 32;
	if (check_is_player (object->game_map[row][clm]) == 1)
	{
		var[3] = 8;
		var[1] += 12;
		var[2] += 12;
	}
	player_and_culor (object, row, clm);
	while (var[0] < var[3])
	{
		var[4] = 0;
		while (var[4] < var[3])
		{
			put_pix_img (object->my_image, var[0] + var[1], var[4] + var[2],
				object->colur);
			var[4]++;
		}
		var[0]++;
	}
}
