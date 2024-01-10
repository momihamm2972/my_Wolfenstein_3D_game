/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_a_binary_to_a_game.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:41:58 by momihamm          #+#    #+#             */
/*   Updated: 2024/01/10 22:40:59 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	check_is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	init_player(t_play *ready)
{
	ready->x_play = 0;
	ready->y_play = 0;
	ready->turn_d = 0;
	ready->walk_d = 0;
	ready->rotation_ang = 0.0;
	ready->move_speed = 0.0;
	ready->rotation_speed = 0.0;
}

void	make_a_strahl(t_ray *obje, int row, int clm)
{
	int	len;
	int	x;
	int	y;

	len = 8;
	x = (clm * 32) + 16;
	y = (row * 32);
	while (len > -70)
	{
		mlx_pixel_put (obje->start, obje->window, x, y + len, 0xFF0000);
		len--;
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
			if (yous_obj->map[row][clm] == '1')
				make_square(row, clm, object, yous_obj);
			else if (yous_obj->map[row][clm] == '+')
				make_square (row, clm, object, yous_obj);
			if (check_is_player (yous_obj->map[row][clm]) == 1)
			{
				make_vue (row, clm, object);
				make_a_strahl (object, row, clm);
			}
			else
				make_square (row, clm, object, yous_obj);
			clm++;
		}
		row++;
	}
	derictions (parzival, object, yous_obj);
}
