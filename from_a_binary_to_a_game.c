/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_a_binary_to_a_game.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:41:58 by momihamm          #+#    #+#             */
/*   Updated: 2024/03/05 09:58:41 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	vir_hit(t_ray *bayren, t_cast *ptr);

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

void	determine_ange(t_ray *jackboys)
{
	jackboys->plays->ray_ang = fmod ( jackboys->plays->ray_ang  , (2 * M_PI));
	if (jackboys->plays->ray_ang < 0)
		jackboys->plays->ray_ang +=  (2 * M_PI);
}

void	init_player(t_ray *ready, t_cub3d *usef)
{
	get_curnt_posi (ready->plays, usef);
	ready->plays->turn_d = 0;
	ready->plays->walk_d = 0;
	ready->plays->rot_ang = M_PI;
	ready->plays->move_speed = 60.0;
	ready->plays->rotation_speed = 1 * (M_PI / 90);
	// raycasting vars;
	ready->plays->f_o_v = deg2rad (60.00);
	ready->plays->pixel_per_colum = 6; 
	ready->plays->num_of_rays = (ready->the_long_line * 32) / ready->plays->pixel_per_colum;
}

void	init_cast(t_ray *amine)
{
	amine->plays->tile = 32;
	amine->plays->finalya_h_wall = 0;
	amine->plays->finalya_v_wall = 0;
}

void	hor_hit(t_ray *bayren, t_cast *ptr)
{
	printf ("fin\n");
	ptr->first_hit_y = floor (bayren->plays->y_play / bayren->plays->tile);
	ptr->first_hit_y *= bayren->plays->tile;
	if (ptr->is_down == 0)
		ptr->first_hit_y += bayren->plays->tile;	
	ptr->first_hit_x = (ptr->first_hit_y - bayren->plays->y_play) / tan(bayren->plays->ray_ang);
	ptr->first_hit_x += bayren->plays->x_play;
	// calcul moves;
	bayren->plays->y_move = bayren->plays->tile;
	bayren->plays->x_move = bayren->plays->tile / tan(bayren->plays->ray_ang);
	if (ptr->is_up == 0)
		bayren->plays->y_move *= -1;
	if (ptr->is_left == 0 && bayren->plays->x_move > 0)
		bayren->plays->x_move *= -1;
	if (ptr->is_right == 0 && bayren->plays->x_move < 0)
		bayren->plays->x_move *= -1;
	// now hit the wall;
	ptr->next_h_x = ptr->first_hit_x;
	ptr->next_h_y = ptr->first_hit_y;
	// now check is the X and Y of my pixel is wall or not;
	if (ptr->is_up == 0)
		ptr->next_h_y--;
	// while (bayren->plays->finalya_h_wall == 0)
	while (ptr->next_h_x >= 0 && ptr->next_h_x <= (bayren->the_long_line * 32) && ptr->next_h_y >= 0 && ptr->next_h_y <= (bayren->the_rows * 32))
	{
		// if (is_wall (bayren, bayren->plays->x_play, bayren->plays->y_play) == -1)
		// 	printf ("*******************************************************************************\n");
		// if (bayren->plays->i_am_wall == 1)
		// {
		// 	printf ("#########################\n");
		// }
		if (is_ray_hit_wall (bayren, ptr->next_h_x, ptr->next_h_y) == -1)
		{
			bayren->plays->finalya_h_wall = 1;
			ptr->horzwall_hit_x = ptr->next_h_x;
			ptr->horzwall_hit_y = ptr->next_h_y;
			// bayren->colur = 0xFF0000;
			// dda(bayren, ptr->horzwall_hit_x, ptr->horzwall_hit_y);
			break;
		}
		else
		{
			ptr->next_h_x += bayren->plays->x_move;
			ptr->next_h_y += bayren->plays->y_move;
			// printf ("hna\n");
			// if (ptr->next_h_x >= (bayren->the_long_line * 32))
			// 	ptr->next_h_x = (bayren->the_long_line * 32);
			// if (ptr->next_h_x <= 0)
			// 	ptr->next_h_x = 0;
			// if (ptr->next_h_y >= (bayren->the_rows * 32))
			// 	ptr->next_h_y = (bayren->the_rows * 32);
			// if (ptr->next_h_y <= 0)
			// 	ptr->next_h_y = 0;
			// printf ("wela hna X= %f\tY= %f \t %d\n", ptr->next_h_x, ptr->next_h_y , bayren->the_rows);
		}
		if (ptr->next_h_x >= 0 && ptr->next_h_x <= (bayren->the_long_line * 32) && ptr->next_h_y >= 0 && ptr->next_h_y <= (bayren->the_rows * 32))
			bayren->plays->i = -1;
		else
		{
			vir_hit(bayren, ptr);
			// printf ("mada \tX %f \tY %f\n", ptr->next_h_x, ptr->next_h_y);
		}
	}
}

void	checker_of_directoins(t_ray *kmi, t_cast *ptr)
{
	
	if (kmi->plays->ray_ang > 0 && kmi->plays->ray_ang < M_PI)
	{
		// printf ("down\n");
		ptr->is_down = 0;
		ptr->is_up = 1;
	}
	else
	{
		// printf ("up\n");
		ptr->is_down = 1;
		ptr->is_up = 0;
	}
	if (kmi->plays->ray_ang < (0.5 * M_PI) || kmi->plays->ray_ang > (1.5 * M_PI))
	{
		// printf ("right\n");
		ptr->is_right = 0;
		ptr->is_left = 1;
	}
	else
	{
		// printf ("left\n"); 
		ptr->is_right = 1;
		ptr->is_left = 0;
	}
	
}

void	vir_hit(t_ray *bayren, t_cast *ptr)
{
	ptr->first_hit_x = floor (bayren->plays->x_play / bayren->plays->tile) * bayren->plays->tile;
	if (ptr->is_right == 0)
		ptr->first_hit_x += bayren->plays->tile;
	ptr->first_hit_y = bayren->plays->y_play + (ptr->first_hit_x - bayren->plays->x_play) * tan(bayren->plays->ray_ang);
	
	bayren->plays->x_move = bayren->plays->tile;
	if (ptr->is_left == 0)
		bayren->plays->x_move *= -1;
		
	bayren->plays->y_move = bayren->plays->tile * tan(bayren->plays->ray_ang);
	if (ptr->is_up == 0 && bayren->plays->y_move > 0)
		bayren->plays->y_move *= -1;
	if (ptr->is_down == 0 && bayren->plays->y_move < 0)
		bayren->plays->y_move *= -1;

	ptr->next_vir_x = ptr->first_hit_x;
	ptr->next_vir_y = ptr->first_hit_y;
	
	if (ptr->is_left == 0)
		ptr->next_vir_x--;

	while (ptr->next_vir_x >= 0 && ptr->next_vir_x <= (bayren->the_long_line * 32) && ptr->next_vir_y >= 0 && ptr->next_vir_y <= (bayren->the_rows * 32))
	{
		if (is_ray_hit_wall (bayren , ptr->next_vir_x, ptr->next_vir_y) == -1)
		{
			bayren->plays->finalya_v_wall = 1;
			ptr->vir_wall_hit_x = ptr->next_vir_x;
			ptr->vir_wall_hit_y = ptr->next_vir_y;
			// bayren->colur = 0x00CCCC;
			// dda(bayren, ptr->vir_wall_hit_x, ptr->vir_wall_hit_y);
			break;
		}
		else
		{
			ptr->next_vir_x += bayren->plays->x_move;
			ptr->next_vir_y += bayren->plays->y_move;
		}
		if (ptr->next_h_x >= 0 && ptr->next_h_x <= (bayren->the_long_line * 32) && ptr->next_h_y >= 0 && ptr->next_h_y <= (bayren->the_rows * 32))
			bayren->plays->i = -1;
		else
		{
			printf ("kmi\n");
			// hor_hit(bayren, ptr);
			printf ("wow\n");
			// printf ("mada \tX %f \tY %f\n", ptr->next_h_x, ptr->next_h_y);
		}
	}
}

void	init_ptr (t_cast *ptr)
{
	ptr->next_h_x = 0;
	ptr->next_h_y = 0;
	ptr->first_hit_x = 0;
	ptr->first_hit_y = 0;
	ptr->vir_wall_hit_x = 0;
	ptr->vir_wall_hit_y = 0;
	ptr->horzwall_hit_x = 0;
	ptr->horzwall_hit_y = 0;
}

// function distanceBetweenPoints(x1, y1, x2, y2) {
//     return Math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
// }

// distanceBetweenPoints(player.x, player.y, horzWallHitX, horzWallHitY)

void	calcul_hor_and_ver_dessetens(t_ray *obj, t_cast *collec)
{
	collec->hor_massafa = sqrt((collec->horzwall_hit_x - obj->plays->x_play) * (collec->horzwall_hit_x - obj->plays->x_play) + (collec->horzwall_hit_y - obj->plays->y_play) * (collec->horzwall_hit_y - obj->plays->y_play));
	collec->vir_massafa = sqrt((collec->vir_wall_hit_x - obj->plays->x_play) * (collec->vir_wall_hit_x - obj->plays->x_play) + (collec->vir_wall_hit_y - obj->plays->y_play) * (collec->vir_wall_hit_y - obj->plays->y_play));
}

void	chose_vert_or_horz(t_ray *obj, t_cast *collection)
{
	if (obj->plays->finalya_h_wall == 1 && obj->plays->finalya_v_wall == 1)
	{
		// printf ("vir  %f \t hor %f \n",obj->plays->finalya_v_wall,  obj->plays->finalya_h_wall);
		calcul_hor_and_ver_dessetens (obj, collection);
	
	printf ("hor %f \t vir %f \n", collection->hor_massafa , collection->vir_massafa);
		if (collection->hor_massafa > collection->vir_massafa)
		{
			collection->x_found_wall = collection->vir_wall_hit_x;
			collection->y_found_wall = collection->vir_wall_hit_y;
			collection->massafa = collection->vir_massafa;
			printf ("V\n");
		}
		else
		{
			collection->x_found_wall = collection->horzwall_hit_x;
			collection->y_found_wall = collection->horzwall_hit_y;
			collection->massafa = collection->hor_massafa;
			printf ("H\n");
		}
		// if (collection->hor_massafa > collection->vir_massafa)
		// {
		// 	collection->y_found_wall = collection->vir_wall_hit_y;
		// }
		// else
		// 	collection->y_found_wall = collection->horzwall_hit_y;
		// if (collection->hor_massafa > collection->vir_massafa)
		// 	collection->massafa = collection->vir_massafa;
		// else
		// 	collection->massafa = collection->hor_massafa;
		obj->colur = 0xFFFF00;
		dda(obj, collection->x_found_wall, collection->y_found_wall);
	}
	
}

void	cast_an_ray(t_ray *bayren, t_cast *ptr)
{
	init_ptr (ptr);
	checker_of_directoins (bayren, ptr);
	// horizonlat hit;
	hor_hit(bayren, ptr);
	// virtical hit;
	vir_hit(bayren, ptr);
	// // massafa of points
	chose_vert_or_horz (bayren, ptr);
}

void	casting(t_ray *parzi)
{
	int	id;
	t_cast	*ptr;

	init_cast (parzi);
	ptr = (t_cast *) malloc (sizeof (t_cast) * 1);
	if (!ptr)
		return ;
	id = 0;
	parzi->plays->ray_ang = parzi->plays->rot_ang - (parzi->plays->f_o_v / 2);
	// while (id < 1)
	while (id <= parzi->plays->num_of_rays)
	{
		determine_ange (parzi);
		cast_an_ray (parzi, ptr);
		parzi->colur = 0xFFFFFF;
		if (id == 0 || id == (parzi->plays->num_of_rays - 1))
			dda (parzi, ((parzi->plays->x_play) + 16) + cos(parzi->plays->ray_ang ) * 100, ((parzi->plays->y_play) + 16) + sin(parzi->plays->ray_ang )  * 100);
		parzi->plays->ray_ang += parzi->plays->f_o_v / parzi->plays->num_of_rays;
		determine_ange (parzi);
		id++;
	}
}

int	ft_again(t_ray *obj)
{
	int		row;
	int		clm;

	// printf (" %f \n",obj->plays->ray_ang);
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
	obj->colur = 0x00FF1A;
	draw_line (obj);
	casting(obj);
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
