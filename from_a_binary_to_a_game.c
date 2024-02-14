/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_a_binary_to_a_game.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:41:58 by momihamm          #+#    #+#             */
/*   Updated: 2024/02/14 08:56:25 by momihamm         ###   ########.fr       */
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
	getCurntPosi (ready, usef);
	ready->turn_d = 0;
	ready->walk_d = 0;
	ready->rot_ang = M_PI;
	ready->move_speed = 4.0;
	ready->rotation_speed = 2 * (M_PI / 45);
}

void	draw_line(t_ray *obj)
{
	int	x;
	int	y;
	int	var;
	int	val;

	x = 0;
	val = 12;
	while (x < 8)
	{
		y = 0;
		var = 12;
		while (y < 8)
		{
			put_pix_img (obj->my_image, (obj->plays->x_play * 32) + var,
				(obj->plays->y_play * 32) + val, obj->colur);
			y++;
			var++;
		}
		x++;
		val++;
	}
	dda(obj,
		((obj->plays->x_play * 32) + 16) + cos(obj->plays->rot_ang) * 40,
		((obj->plays->y_play * 32) + 16) + sin(obj->plays->rot_ang) * 40);
}

void	creat_img(t_ray *obj)
{
	mlx_clear_window (obj->start, obj->window);
	mlx_destroy_image (obj->start, obj->my_image->mlx_img);
	make_valus(obj->plays);
	obj->my_image->mlx_img = mlx_new_image (obj->start, obj->the_long_line * 32,
			obj->the_rows * 32);
	obj->my_image->data_addr = mlx_get_data_addr (obj->my_image->mlx_img,
			&obj->my_image->intperpixl, &obj->my_image->lenofline,
			&obj->my_image->end);
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
