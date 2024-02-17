/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_a_binary_to_a_game.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:41:58 by momihamm          #+#    #+#             */
/*   Updated: 2024/02/16 05:15:03 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	check_is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		// if (c == 'N')
		// 	printf ("NNNNNNNNNNNN\n");
		// if (c == 'S')
		// 	printf ("SSSSSSSSSSSSS\n");
		// if (c == 'E')
		// 	printf ("EEEEEEEEEEEEEE\n");
		// if (c == 'W')
		// 	printf ("WWWWWWWWWWWWWWWWWWWWW\n");
		return (1);
	}
	return (0);
}

void	init_player(t_play *ready, t_cub3d *usef)
{
	get_curnt_posi (ready, usef);
	ready->turn_d = 0;
	ready->walk_d = 0;
	ready->rot_ang = M_PI;
	ready->move_speed = 2.0;
	ready->rotation_speed = 2 * (M_PI / 90);
	// ready->player_xx = 0;
	// ready->player_yy = 0;
}

int	ft_again(t_ray *obj)
{
	int		row;
	int		clm;

	row = 0;
	creat_img (obj);
	while (obj->game_map[row])
	{
		clm = 0;
		while (obj->game_map[row][clm])
		{
			if (obj->game_map[row][clm] == '1')
				make_square(row, clm, obj);
			else if (obj->game_map[row][clm] == '+')
				make_square (row, clm, obj);
			clm++;
		}
		row++;
	}
	obj->colur = 0xFFFFFF;
	draw_line (obj);
	mlx_put_image_to_window (obj->start, obj->window,
		obj->my_image->mlx_img, 0, 0);
	return (0);
}

void	draw_zero(t_ray *obj, t_play *parzi)
{
	int	row;
	int	clm;

	row = 0;
	while (obj->game_map[row])
	{
		clm = 0;
		while (obj->game_map[row][clm])
		{
			if (check_is_player (obj->game_map[row][clm]) == 1)
			{
				make_square (row, clm, obj);
				obj->colur = 0xEE0505;
				dda(obj,
					((parzi->x_play * 32) + 16)
					+ cos(parzi->rot_ang) * 40,
					((parzi->y_play * 32) + 16)
					+ sin(parzi->rot_ang) * 40);
			}
			clm++;
		}
		row++;
	}
}

void	ft_draw(t_ray *object, t_play *parzi)
{
	int		row;
	int		clm;

	row = 0;
	while (object->game_map[row])
	{
		clm = 0;
		while (object->game_map[row][clm])
		{
			if (object->game_map[row][clm] == '1')
				make_square(row, clm, object);
			else if (object->game_map[row][clm] == '+')
				make_square (row, clm, object);
			clm++;
		}
		row++;
	}
	draw_zero (object, parzi);
	mlx_put_image_to_window (object->start, object->window,
		object->my_image->mlx_img, 0, 0);
}
