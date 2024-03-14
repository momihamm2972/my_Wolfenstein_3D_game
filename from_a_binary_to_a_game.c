/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_a_binary_to_a_game.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:41:58 by momihamm          #+#    #+#             */
/*   Updated: 2024/03/14 11:04:05 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	determine_ange(t_ray *jackboys, int id)
{
	jackboys->dataray[id].ray_ang = fmod (jackboys->dataray[id].ray_ang,
			2 * M_PI);
	if (jackboys->dataray[id].ray_ang < 0)
		jackboys->dataray[id].ray_ang = (2 * M_PI)
			+ jackboys->dataray[id].ray_ang ;
}

void	chose_vert_or_horz(t_ray *obj, int id)
{
	calcul_hor_and_ver_dessetens (obj, id);
	if (obj->dataray[id].hor_massafa > obj->dataray[id].vir_massafa)
	{
		obj->dataray[id].x_found_wall = obj->dataray[id].vir_wall_hit_x;
		obj->dataray[id].y_found_wall = obj->dataray[id].vir_wall_hit_y;
		obj->dataray[id].massafa = obj->dataray[id].vir_massafa;
		obj->dataray[id].virt = 1;
	}
	else
	{
		obj->dataray[id].x_found_wall = obj->dataray[id].horzwall_hit_x;
		obj->dataray[id].y_found_wall = obj->dataray[id].horzwall_hit_y;
		obj->dataray[id].massafa = obj->dataray[id].hor_massafa;
		obj->dataray[id].horz = 1;
	}
}

void	cast_an_ray(t_ray *bayren, int id)
{
	init_ptr (bayren, id);
	chose_vert_or_horz (bayren, id);
}

void	casting(t_ray *parzi)
{
	int	id;

	id = 0;
	init_cast (parzi);
	parzi->dataray[id].ray_ang = parzi->plays->rot_ang;
	parzi->dataray[id].ray_ang -= parzi->plays->f_o_v / 2;
	while (id < 1440)
	{
		cast_an_ray (parzi, id);
		parzi->dataray[id + 1].ray_ang = parzi->dataray[id].ray_ang ;
		id++;
		parzi->dataray[id].ray_ang += parzi->plays->f_o_v / 1440;
	}
}

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
			put_pix_img (obj->my_image, i + x, j + y,
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
	while (indx < 1440)
	{
		rows = 0;
		while (rows < 860)
		{
			if (rows <= (860 / 2))
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
	while (id < 1440)
	{
		corect_lenght = obj->dataray[id].massafa
			* cos (obj->dataray[id].ray_ang - obj->plays->rot_ang);
		obj->dataray[id].wall_length = (obj->plays->tile / corect_lenght)
			* obj->dest_por_wall;
		make_rege(obj, obj->dataray[id].wall_length, 1, id);
		id++;
	}
}

int	ft_again(t_ray *obj)
{
	creat_img (obj);
	casting(obj);
	ceiling_floor (obj);
	become_3d (obj);
	mlx_put_image_to_window (obj->start, obj->window,
		obj->my_image->mlx_img, 0, 0);
	return (0);
}

// int	ft_again(t_ray *obj)
// {
// 	int		row;
// 	int		clm;

// 	row = 0;
// 	creat_img (obj);
// 	while (obj->game_map[row])
// 	{
// 		clm = 0;
// 		while (obj->game_map[row][clm])
// 		{
// 			if (obj->game_map[row][clm] == '1')
// 				make_square(row, clm, obj);
// 			else if (obj->game_map[row][clm] == '+')
// 				make_square (row, clm, obj);
// 			clm++;
// 		}
// 		row++;
// 	}
// 	obj->colur = 0x00FF1A;
// 	casting(obj);
// 	draw_line (obj);
// 	mlx_put_image_to_window (obj->start, obj->window,
// 		obj->my_image->mlx_img, 0, 0);
// 	return (0);
// }
