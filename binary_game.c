/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:39:39 by momihamm          #+#    #+#             */
/*   Updated: 2024/02/14 11:08:26 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

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
	make_valus(obj->plays, obj);
	obj->my_image->mlx_img = mlx_new_image (obj->start, obj->the_long_line * 32,
			obj->the_rows * 32);
	obj->my_image->data_addr = mlx_get_data_addr (obj->my_image->mlx_img,
			&obj->my_image->intperpixl, &obj->my_image->lenofline,
			&obj->my_image->end);
}
