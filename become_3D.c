/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   become_3D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 05:00:34 by momihamm          #+#    #+#             */
/*   Updated: 2024/03/16 08:22:41 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	make_rege(t_ray *obj, double tol, double ard, int id)
{
	double	x;
	double	y;
	int		i;
	int		j;

	i = 0;
	x = id * 1;
	y = 430 - (obj->dataray[id].wall_length / 2);
	obj->colur = 0x000099;
	while (i < ard)
	{
		j = 0;
		while (j < tol)
		{
			put_pix_img (obj->my_image, i + x, y + j,
				obj->colur);
			j++;
		}
		i++;
	}
}

void	ceiling_floor(t_ray *obj)
{
	int	indx;
	int	rows;

	indx = 0;
	while (indx < RAYS_WINDOW_WIDTH)
	{
		rows = 0;
		while (rows < WINDOW_HEIGHT)
		{
			if (rows <= (WINDOW_HEIGHT / 2))
				obj->colur = obj->ceiling;
			else
				obj->colur = obj->f_flor;
			put_pix_img (obj->my_image, indx, rows, obj->colur);
			rows++;
		}
		indx++;
	}
}

void	become_3d(t_ray *obj)
{
	int		id;
	double	corect_lenght;

	id = 0;
	while (id < RAYS_WINDOW_WIDTH)
	{
		corect_lenght = obj->dataray[id].massafa
			* cos (obj->dataray[id].ray_ang - obj->plays->rot_ang);
		obj->dataray[id].wall_length = (obj->plays->tile / corect_lenght)
			* obj->dest_por_wall;
		if (obj->dataray[id].wall_length > RAYS_WINDOW_WIDTH)
			obj->dataray[id].wall_length = RAYS_WINDOW_WIDTH;
		make_rege(obj, obj->dataray[id].wall_length, 0.5, id);
		id++;
	}
}
