/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_a_binary_to_a_game.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:41:58 by momihamm          #+#    #+#             */
/*   Updated: 2024/02/23 16:04:58 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	check_is_player(t_play *obj, char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (c == 'N')
			obj->rot_ang = - M_PI / 2;
		if (c == 'S')
			obj->rot_ang = M_PI / 2;
		if (c == 'E')
			obj->rot_ang = 0;
		if (c == 'W')
			obj->rot_ang = M_PI;
		return (1);
	}
	return (0);
}

void	init_player(t_ray *ready, t_cub3d *usef)
{
	get_curnt_posi (ready->plays, usef);
	ready->plays->turn_d = 0;
	ready->plays->walk_d = 0;
	ready->plays->rot_ang = M_PI;
	ready->plays->move_speed = 60.0;
	ready->plays->rotation_speed = 2 * (M_PI / 90);
	// raycasting vars;
	ready->plays->f_o_v = deg2rad (60.00);
	// ready->i = 0;
	ready->plays->pixel_per_colum = 10; 
	// ready->plays->num_of_rays = 1.0;
	// printf ("lline %d\n", ready->the_long_line);
	// printf ("ll32ine %d\n", ready->the_long_line * 32);
	// printf ("pixel %d\n", ready->plays->pixel_per_colum);
	// printf ("numof_rays %d\n", ready->plays->num_of_rays);
	// printf ("result %d\n", (ready->the_long_line * 32) / ready->plays->pixel_per_colum);
	// printf ("pix %d\tnumofrays %d\n", ready->plays->pixel_per_colum, ready->plays->num_of_rays);
	ready->plays->num_of_rays = (ready->the_long_line * 32) / ready->plays->pixel_per_colum;
	// printf ("zre3   %d\n", (ready->the_long_line * 32) / ready->plays->num_of_rays);
	// printf ("pix %d\tnumofrays %d\n", ready->plays->pixel_per_colum, ready->plays->num_of_rays);
	// printf ("numof rays %d\n", ready->plays->num_of_rays);
	// exit (0);
}

void	casting(t_ray *parzi)
{
	int	id;
// printf ("some data line = %d  per pixle %f num of rays %d\n", parzi->the_long_line * 32, parzi->plays->pixel_per_colum, (int)((parzi->the_long_line * 32) / parzi->plays->pixel_per_colum));
// printf ("any one home!%d!\n", parzi->plays->num_of_rays);
	id = 0;
	if (id > (int)parzi->plays->num_of_rays)
		printf ("\nkmi\n");
	parzi->plays->ray_ang = parzi->plays->rot_ang - (parzi->plays->f_o_v / 2);
	while (id < parzi->plays->num_of_rays)
	{
		printf ("casting\n");
		// take the DATA of each ray; PS==> you need to figr out how to save the DATA you will need;
		// cast each ray;
		parzi->colur = 0xFFFF33;
		dda (parzi, ((parzi->plays->x_play) + 16) + cos(parzi->plays->ray_ang ) * 800, ((parzi->plays->y_play) + 16) + sin(parzi->plays->ray_ang )  * 800);
		parzi->plays->ray_ang += parzi->plays->f_o_v / parzi->plays->num_of_rays;
		id++;
	}
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
	casting(obj); 
	draw_line (obj);
	mlx_put_image_to_window (obj->start, obj->window,
		obj->my_image->mlx_img, 0, 0);
	return (0);
}

void	draw_zero(t_ray *obj, t_play *parzi)
{
	int	row;
	int	clm;

	(void) parzi;
	row = 0;
	while (obj->game_map[row])
	{
		clm = 0;
		while (obj->game_map[row][clm])
		{
			if (check_is_player (obj->plays, obj->game_map[row][clm]) == 1)
				make_square (row, clm, obj);
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
