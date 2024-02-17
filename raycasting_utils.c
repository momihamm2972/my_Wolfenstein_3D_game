/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:44:11 by momihamm          #+#    #+#             */
/*   Updated: 2024/02/16 04:09:39 by momihamm         ###   ########.fr       */
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

// void	make_vue(int row, int clm, t_ray *object)
// {
// 	int	var[6];

// 	var[4] = clm * 32;
// 	var[5] = row * 32;
// 	var[0] = 16;
// 	var[1] = 8;
// 	var[2] = 0;
// 	object->colur = 0x00FF3B;
// 	while (var[2] < 32)
// 	{
// 		var[3] = 0;
// 		while (var[3] < 32)
// 		{
// 			if (var[3] == var[1])
// 				var[3] += var[0];
// 			put_pix_img (object->my_image, var[3] + var[4], var[2] + var[5],
// 				object->colur);
// 			var[3]++;
// 		}
// 		var[2]++;
// 		if (var >= 0)
// 			the_values_of_vue (&var[0], &var[1]);
// 	}
// }

void	player_and_culor(t_ray *obj, int row, int clm)
{
	if (obj->game_map[row][clm] == '1')
		obj->colur = 0x005EFF;
	else if ((obj->game_map[row][clm]) == '0')
		obj->colur = 0xFFFFFF;
	else if ((obj->game_map[row][clm]) == '+')
		obj->colur = 0xB200FF;
	else
		obj->colur = 0x0022FF;
}

void	make_square(int row, int clm, t_ray *object)
{
	int	var[5];

	var[0] = 0;
	var[1] = clm * 32;
	var[2] = row * 32;
	var[3] = 32;
	// double	movestep;
	// printf ("\n\n\n\n\nmake_squaremake_squaremake_squaremake_square\n\n\n\n\n\n\n\n");
	int kmi;
	int zre3;
	// movestep = object->plays->walk_d * object->plays->move_speed / 16;
	if (check_is_player (object->game_map[row][clm]) == 1)
	{
		var[3] = 8;
		var[1] += 12;
		var[2] += 12;
		kmi = var[1];
		zre3 = var[2];
		// if (object->plays->player_xx == 0 && object->plays->player_yy == 0)
		// {
		// 	printf ("ja\n");
		// 	object->plays->player_xx = var[1];
		// 	object->plays->player_yy = var[2];
		// 	// object->plays->new_x = (object->plays->player_xx / 32) + (cos(object->plays->rot_ang) * movestep);
		// 	// object->plays->new_y = (object->plays->player_yy / 32) + (sin(object->plays->rot_ang) * movestep);
		// }
		// printf ("1 = %d\t 2 =%d\n", var[1], var[2]);
		// exit (0);
	}
	player_and_culor (object, row, clm);
	// int i = 0;
	while (var[0] < var[3])
	{
		var[4] = 0;
		// else
		// 	object->colur = 0xFFFFFF;
		while (var[4] < var[3])
		{
		// if (var[3] == 8 && i <= 2  && check_is_player (object->game_map[row][clm]) == 1)
		// 	object->colur = 0x00DF34;
		// else
		// 	object->colur = 0xFFFFFF;
			put_pix_img (object->my_image, var[0] + var[1], var[4] + var[2],
				object->colur);
			var[4]++;
		}
		var[0]++;
		// i++;
		// put_pix_img (object->my_image, var[0] + kmi, var[4] + zre3,
		// 		0x00DF34);
	}
	// var[0] = 0;
	// var[1] = clm * 32;
	// var[2] = row * 32;
	// var[3] = 32;
	// if (check_is_player (object->game_map[row][clm]) == 1)
	// {
	// 	put_pix_img (object->my_image, var[0] + kmi, var[4] + zre3,
	// 				0x00DF34);
	// 	mlx_put_image_to_window (object->start, object->window, object->my_image->mlx_img, 0,0);
	// 	sleep (5);
	// 	printf ("sllep\n");
	// 	// exit (0);
	// }
}
