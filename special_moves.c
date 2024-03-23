/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 04:47:29 by momihamm          #+#    #+#             */
/*   Updated: 2024/03/23 11:12:28 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	left(t_ray *obj)
{
	double	old_x;
	double	old_y;
	int		i;

	old_x = obj->plays->x_play;
	old_y = obj->plays->y_play;
	i = 0;
	if (obj->plays->left_walk == 1)
	{
		obj->plays->fake_angle = obj->plays->rot_ang - (M_PI / 2);
		obj->plays->x_play += cos(obj->plays->fake_angle);
		obj->plays->y_play += sin(obj->plays->fake_angle);
		if ((is_wall (obj, obj->plays->x_play - 4,
					obj->plays->y_play - 4) == -1))
			i++;
		if ((is_wall (obj, obj->plays->x_play + 4,
					obj->plays->y_play + 4) == -1))
			i++;
		if (i > 0)
		{
			obj->plays->x_play = old_x;
			obj->plays->y_play = old_y;
		}
	}
}

void	right(t_ray *obj)
{
	double	old_x;
	double	old_y;
	int		i;

	old_x = obj->plays->x_play;
	old_y = obj->plays->y_play;
	i = 0;
	if (obj->plays->right_walk == 1)
	{
		obj->plays->fake_angle = obj->plays->rot_ang + (M_PI / 2);
		obj->plays->x_play += cos(obj->plays->fake_angle);
		obj->plays->y_play += sin(obj->plays->fake_angle);
		if ((is_wall (obj, obj->plays->x_play - 4,
					obj->plays->y_play - 4) == -1))
			i++;
		if ((is_wall (obj, obj->plays->x_play + 4,
					obj->plays->y_play + 4) == -1))
			i++;
		if (i > 0)
		{
			obj->plays->x_play = old_x;
			obj->plays->y_play = old_y;
		}
	}
}

void	check_mate(t_ray *obj)
{
	if (is_wall (obj, obj->plays->x_play - obj->plays->j_y,
			obj->plays->y_play - obj->plays->i_x) == -1)
	{
		obj->plays->x_play = obj->plays->new_x;
		obj->plays->y_play = obj->plays->new_y;
	}
}

void	up_and_down(t_play *obj, t_ray *data)
{
	obj->i_x = 0;
	obj->j_y = 0;
	if (is_ray_down (obj->rot_ang) == 1 && obj->walk_d == 1)
	{
		obj->i_x = 5;
		obj->j_y = 0;
	}
	else if (is_ray_down (obj->rot_ang) == 1 && obj->walk_d == -1)
	{
		obj->i_x = -5;
		obj->j_y = 0;
	}
	else if (is_ray_down (obj->rot_ang) == 0 && obj->walk_d == 1)
	{
		obj->i_x = -5;
		obj->j_y = 0;
	}
	else if (is_ray_down (obj->rot_ang) == 0 && obj->walk_d == -1)
	{
		obj->i_x = 5;
		obj->j_y = 0;
	}
	check_mate (data);
}

void	eastorwestfoodisthebest(t_ray *obj)
{
	obj->plays->i_x = 0;
	obj->plays->j_y = 0;
	if (is_ray_right (obj->plays->rot_ang) == 1 && obj->plays->walk_d == 1)
	{
		obj->plays->i_x = 0;
		obj->plays->j_y = -5;
	}
	if (is_ray_right (obj->plays->rot_ang) == 1 && obj->plays->walk_d == -1)
	{
		obj->plays->i_x = 0;
		obj->plays->j_y = 5;
	}
	if (is_ray_right (obj->plays->rot_ang) == 0 && obj->plays->walk_d == 1)
	{
		obj->plays->i_x = 0;
		obj->plays->j_y = 5;
	}
	if (is_ray_right (obj->plays->rot_ang) == 0 && obj->plays->walk_d == -1)
	{
		obj->plays->i_x = 0;
		obj->plays->j_y = -5;
	}
	check_mate (obj);
}
