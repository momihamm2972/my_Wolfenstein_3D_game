/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_a_binary_to_a_game.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:41:58 by momihamm          #+#    #+#             */
/*   Updated: 2024/03/13 07:25:31 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	is_ray_down(double ray_angle)
{
	// normalize_angle(ray_angle);
	// if (ray_angle > 0 && ray_angle < M_PI)
	// {
	// 	printf ("i am down\n");
	// }
		return (ray_angle > 0 && ray_angle < M_PI);
}

int	is_ray_up(double ray_angle)
{
	return (!is_ray_down(ray_angle));
}

int	is_ray_right(double ray_angle)
{
	// normalize_angle(ray_angle);
	if (ray_angle < M_PI / 2 || ray_angle > 3 * M_PI / 2)
		return (1);
	return (0);
}

int	is_ray_left(double ray_angle)
{
	return (!is_ray_right(ray_angle));
}

int	vir_hit(t_ray *bayren, int id);

int	check_is_player(t_play *obj, char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (c == 'N')
			obj->rot_ang = 3 * M_PI / 2;
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

double	normalize_angle(double angle)
{
	angle = fmod ( angle  , 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return (angle);
}

void	determine_ange(t_ray *jackboys, int id)
{
	(void) id;
	// printf ("befor %f\n", jackboys->plays->ray_ang);
	jackboys->dataray[id].ray_ang  = fmod ( jackboys->dataray[id].ray_ang   , 2 * M_PI);
	if (jackboys->dataray[id].ray_ang  < 0)
		jackboys->dataray[id].ray_ang  = (2 * M_PI) + jackboys->dataray[id].ray_ang ;
	// printf ("after %f\n", jackboys->plays->ray_ang);
}

void	init_player(t_ray *ready, t_cub3d *usef)
{
	get_curnt_posi (ready->plays, usef);
	ready->plays->turn_d = 0;
	ready->plays->walk_d = 0;
	ready->plays->move_speed = 60.0;
	ready->plays->rotation_speed = 2 * (M_PI / 90);
	// raycasting vars;
	ready->plays->f_o_v = deg2rad (60.00);
	ready->plays->pixel_per_colum = 1; 
	ready->plays->num_of_rays = 1440;
}

void	init_cast(t_ray *starlight)
{
	starlight->plays->tile = 32;
	starlight->plays->x_move = 0;
	starlight->plays->y_move = 0;
	starlight->plays->i_am_wall = 0;
}

// int	hor_hit(t_ray *bayren, int	id)
// {
// 	(void) id;
// 	// printf ("hor %f\n", bayren->plays->ray_ang);
// 	double	xintercept, yintercept, xstep, ystep;
// 	int	foundHorzWallHit = 0;
// 	double horzWallHitX = 0;
// 	double horzWallHitY = 0;
// 	yintercept = floor (bayren->plays->y_play / bayren->plays->tile) * bayren->plays->tile;
// 	yintercept += is_ray_down(bayren->plays->ray_ang) ? bayren->plays->tile : 0;

// 	xintercept = bayren->plays->x_play + ((yintercept - bayren->plays->y_play) / tan(bayren->plays->ray_ang));

// 	ystep = bayren->plays->tile;
// 	ystep *= is_ray_up(bayren->plays->ray_ang) ? -1 : 1;
	
// 	xstep = bayren->plays->tile / tan(bayren->plays->ray_ang);
// 	xstep *= (is_ray_left (bayren->plays->ray_ang) && xstep > 0) ? -1 : 1;
// 	xstep *= (is_ray_right (bayren->plays->ray_ang) && xstep < 0) ? -1 : 1;
	
// 	// printf ("xstep %f \t ystep %f\n", xstep, ystep);
	
// 	double nextHorzTouchX = xintercept;
// 	double nextHorzTouchY = yintercept;

// 	if (is_ray_up (bayren->plays->ray_ang))
// 		nextHorzTouchY--;
	
// 	// while (foundHorzWallHit != 1)
// 	while (nextHorzTouchX >= 0 && nextHorzTouchX <= 1440 && nextHorzTouchY >= 0 && nextHorzTouchY <= (bayren->the_rows * 32))
// 	{
// 		if (!(nextHorzTouchX >= 0 && nextHorzTouchX <= 1440 && nextHorzTouchY >= 0 && nextHorzTouchY <= (bayren->the_rows * 32)))
// 		{
// 			printf ("X %f\t Y %f\n", nextHorzTouchX, nextHorzTouchY);
// 		}
// 		    if (is_ray_hit_wall(bayren ,nextHorzTouchX, nextHorzTouchY))
// 			{
//                 foundHorzWallHit = 1;
//                 horzWallHitX = nextHorzTouchX;
//                 horzWallHitY = nextHorzTouchY;
// 				if (horzWallHitX < 0)
// 					horzWallHitX = 0;
// 				if (horzWallHitY < 0)
// 					horzWallHitY = 0;
// 				if (horzWallHitX > 1440)
// 					horzWallHitX = 1440;
// 				if (horzWallHitY > (bayren->the_rows * 32))
// 					horzWallHitY = (bayren->the_rows * 32);
// 				// bayren->colur = 0xFF0000;
// 				// dda (bayren, horzWallHitX, horzWallHitY);
// 				// sleep (1000);
// 				return (1);
//                 break;
//             } else {
//                 nextHorzTouchX += xstep;
//                 nextHorzTouchY += ystep;
// 				// if (nextHorzTouchX < 0)
// 				// {
// 				// 	printf ("this is X nextHorzTouch %f \t and xstep %f\n", nextHorzTouchX, xstep);
// 				// }
// 				// if (nextHorzTouchY < 0)
// 				// {
// 				// 	printf ("this is Y nextHorzTouch %f \t and ystep %f\n", nextHorzTouchY, ystep);
// 				// }
//             }
//         }
// 	return (0);
// }
int	hor_hit(t_ray *bayren, int	id)
{
	double check_y;
	determine_ange (bayren, id);

	bayren->dataray[id].first_hit_y = floor (bayren->plays->y_play / bayren->plays->tile) * bayren->plays->tile;
	if (is_ray_down(bayren->dataray[id].ray_ang))
		bayren->dataray[id].first_hit_y = floor (bayren->plays->y_play / bayren->plays->tile) * bayren->plays->tile + bayren->plays->tile;
	// printf("a_y:    %f\n", bayren->dataray[id].first_hit_y);
	bayren->dataray[id].first_hit_x = bayren->plays->x_play + (bayren->dataray[id].first_hit_y - bayren->plays->y_play) / tan(bayren->dataray[id].ray_ang);
	// calcul moves;
	bayren->plays->y_move = bayren->plays->tile;
	if (is_ray_up(bayren->dataray[id].ray_ang))
		bayren->plays->y_move *= -1;
	bayren->plays->x_move = bayren->plays->tile / tan(bayren->dataray[id].ray_ang);
	if (is_ray_left(bayren->dataray[id].ray_ang) && bayren->plays->x_move > 0)
		bayren->plays->x_move *= -1;
	if (is_ray_right(bayren->dataray[id].ray_ang) && bayren->plays->x_move < 0)
		bayren->plays->x_move *= -1;
	// now hit the wall;
	bayren->dataray[id].next_h_x = bayren->dataray[id].first_hit_x;
	bayren->dataray[id].next_h_y = bayren->dataray[id].first_hit_y;
	// while (kmi != 1)
	while (bayren->dataray[id].next_h_x > 0 && bayren->dataray[id].next_h_x <= (1440) && bayren->dataray[id].next_h_y > 0 && bayren->dataray[id].next_h_y <= (bayren->the_rows * 32))
	{

		check_y = bayren->dataray[id].next_h_y;
		if (is_ray_up(bayren->dataray[id].ray_ang))
			check_y = bayren->dataray[id].next_h_y - 1;
		if (is_ray_hit_wall (bayren, bayren->dataray[id].next_h_x, check_y) == -1)
		{
			bayren->dataray[id].horzwall_hit_x = bayren->dataray[id].next_h_x;
			bayren->dataray[id].horzwall_hit_y = bayren->dataray[id].next_h_y;
			return 1;
		}
		else
		{
			bayren->dataray[id].next_h_x += bayren->plays->x_move;
			bayren->dataray[id].next_h_y += bayren->plays->y_move;
		}

	}
	return 0;
}




// int	vir_hit(t_ray *bayren, int id)
// {
// 	 (void) id;
// 	double foundVertWallHit = 0;
//         double vertWallHitX = 0;
//         double vertWallHitY = 0;
// 		double	xintercept, yintercept, xstep, ystep;

//         // Find the x-coordinate of the closest vertical grid intersenction
//         xintercept = floor(bayren->plays->x_play / bayren->plays->tile) * bayren->plays->tile;
//         xintercept += is_ray_right (bayren->plays->ray_ang) ? bayren->plays->tile : 0;

//         // Find the y-coordinate of the closest vertical grid intersection
//         yintercept = bayren->plays->y_play + (xintercept - bayren->plays->x_play) * tan(bayren->plays->ray_ang);

//         // Calculate the increment xstep and ystep
//         xstep = bayren->plays->tile;
//         xstep *= is_ray_left (bayren->plays->ray_ang) ? -1 : 1;

//         ystep = bayren->plays->tile * tan(bayren->plays->ray_ang);
//         ystep *= (is_ray_up (bayren->plays->ray_ang) && ystep > 0) ? -1 : 1;
//         ystep *= (is_ray_down (bayren->plays->ray_ang) && ystep < 0) ? -1 : 1;

//         double nextVertTouchX = xintercept;
//         double nextVertTouchY = yintercept;

//         if (is_ray_left (bayren->plays->ray_ang))
//             nextVertTouchX--;

//         // Increment xstep and ystep until we find a wall
// 		// while (foundVertWallHit != 1)
//         while (nextVertTouchX >= 0 && nextVertTouchX <= 1440 && nextVertTouchY >= 0 && nextVertTouchY <= (bayren->the_rows * 32))
// 		{
//             if (is_ray_hit_wall(bayren , nextVertTouchX, nextVertTouchY)) {
//                 foundVertWallHit = 1;
//                 vertWallHitX = nextVertTouchX;
//                 vertWallHitY = nextVertTouchY;
// 				// bayren->colur = 0x00CCCC;
// 				// dda (bayren, vertWallHitX, vertWallHitY);
// 				return (1);
//                 break;
//             } else {
//                 nextVertTouchX += xstep;
//                 nextVertTouchY += ystep;
//             }
//         }
// 	return (0);
// }
int	vir_hit(t_ray *bayren, int id)
{
	// determine_ange (bayren);
	// int kmi = 0;
	// int mimi;
	determine_ange (bayren, id);
	bayren->dataray[id].first_hit_x = floor (bayren->plays->x_play / bayren->plays->tile) * bayren->plays->tile;
	if (is_ray_right(bayren->dataray[id].ray_ang))
		bayren->dataray[id].first_hit_x = floor(bayren->plays->x_play / bayren->plays->tile) * bayren->plays->tile + bayren->plays->tile;
	bayren->dataray[id].first_hit_y = bayren->plays->y_play + (bayren->dataray[id].first_hit_x - bayren->plays->x_play) * tan(bayren->dataray[id].ray_ang);
	// calculate the increment xstep and ystep;
	bayren->plays->x_move = bayren->plays->tile;
	if (is_ray_left(bayren->dataray[id].ray_ang))
		bayren->plays->x_move *= -1;
		
	bayren->plays->y_move = bayren->plays->tile * tan(bayren->dataray[id].ray_ang);
	if (is_ray_up(bayren->dataray[id].ray_ang) && bayren->plays->y_move > 0)
		bayren->plays->y_move *= -1;
	if (is_ray_down(bayren->dataray[id].ray_ang) && bayren->plays->y_move < 0)
		bayren->plays->y_move *= -1;

	bayren->dataray[id].next_vir_x = bayren->dataray[id].first_hit_x;
	bayren->dataray[id].next_vir_y = bayren->dataray[id].first_hit_y;
	
	double check_x;

	// while (kmi != 1)
	while (bayren->dataray[id].next_vir_x > 0 && bayren->dataray[id].next_vir_x <= (1440) && bayren->dataray[id].next_vir_y > 0 && bayren->dataray[id].next_vir_y <= (bayren->the_rows * 32))
	{
		// if (!(bayren->dataray[id].next_vir_x > 0 && bayren->dataray[id].next_vir_x <= (1440) && bayren->dataray[id].next_vir_y > 0 && bayren->dataray[id].next_vir_y <= (bayren->the_rows * 32)))
		// {
			
		// }
		check_x = bayren->dataray[id].next_vir_x;
		if (is_ray_left(bayren->dataray[id].ray_ang))
			check_x = bayren->dataray[id].next_vir_x - 1;
		// mimi = is_ray_hit_wall (bayren , check_x, bayren->dataray[id].next_vir_y);
		if (is_ray_hit_wall (bayren , check_x, bayren->dataray[id].next_vir_y) == -1)
		{
			// kmi = 1;
			bayren->dataray[id].vir_wall_hit_x = bayren->dataray[id].next_vir_x;
			bayren->dataray[id].vir_wall_hit_y = bayren->dataray[id].next_vir_y;
			return 1;
		}
		else
		{
			bayren->dataray[id].next_vir_x += bayren->plays->x_move;
			bayren->dataray[id].next_vir_y += bayren->plays->y_move;
		}
	}
	return 0;
}

void	init_ptr (t_ray *parzi, int id)
{
	// determine_ange (parzi, id);
	parzi->dataray[id].next_h_x = 0;
	parzi->dataray[id].next_h_y = 0;
	parzi->dataray[id].first_hit_x = 0;
	parzi->dataray[id].first_hit_y = 0;
	parzi->dataray[id].vir_wall_hit_x = 0;
	parzi->dataray[id].vir_wall_hit_y = 0;
	parzi->dataray[id].horzwall_hit_x = 0;
	parzi->dataray[id].horzwall_hit_y = 0;
	parzi->dataray[id].hor_massafa = 0;
	parzi->dataray[id].vir_massafa = 0;
	parzi->dataray[id].next_vir_x = 0;
	parzi->dataray[id].next_vir_y = 0;
	parzi->dataray[id].massafa = 0;
	parzi->dataray[id].virt = 0;
	parzi->dataray[id].horz = 0;
}

void	calcul_hor_and_ver_dessetens(t_ray *obj, int id)
{
	int hit_ho = hor_hit(obj, id);
	int hit_vi = vir_hit(obj, id);
	
	obj->dataray[id].hor_massafa = (double)sqrt(pow((obj->dataray[id].horzwall_hit_x - obj->plays->x_play), 2) + pow((obj->dataray[id].horzwall_hit_y - obj->plays->y_play), 2));
	obj->dataray[id].vir_massafa = (double)sqrt(pow((obj->dataray[id].vir_wall_hit_x - obj->plays->x_play), 2) + pow((obj->dataray[id].vir_wall_hit_y - obj->plays->y_play), 2));

	if (hit_ho == 0)
	{
		obj->dataray[id].hor_massafa = 2147483647;
		// printf ("no hor\n");
	}
	if (hit_vi == 0)
	{
		obj->dataray[id].vir_massafa = 2147483647;
		// printf ("no vir\n");
	}

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
		obj->colur = 0xFF00FF;
		if (id == 1439 || id == 0)
			obj->colur = 0xFFFFFF;
		dda(obj, obj->dataray[id].x_found_wall, obj->dataray[id].y_found_wall);
	}
	else
	{
		obj->dataray[id].x_found_wall = obj->dataray[id].horzwall_hit_x;
		obj->dataray[id].y_found_wall = obj->dataray[id].horzwall_hit_y;
		obj->dataray[id].massafa = obj->dataray[id].hor_massafa;
		obj->dataray[id].horz = 1;
		obj->colur = 0xCC6600;
		if (id == 1439 || id == 0)
			obj->colur = 0xFFFFFF;
		dda(obj, obj->dataray[id].x_found_wall, obj->dataray[id].y_found_wall);
	}
}

void	cast_an_ray(t_ray *bayren, int id)
{
	(void) bayren;
	init_ptr (bayren, id);
	chose_vert_or_horz (bayren, id);
}

void	casting(t_ray *parzi)
{
	int	id;

	id = 0;
	init_cast (parzi);
	parzi->dataray[id].ray_ang = parzi->plays->rot_ang - parzi->plays->f_o_v / 2;
	// parzi->dataray[id].ray_ang += deg2rad (10);
	// parzi->dataray[id].ray_ang = normalize_angle(parzi->dataray[id].ray_ang);
	while (id < 1440)
	{
		// printf ("%d\n", id);
		// if (id == 1439)
		// 	printf ("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
		// if (id == 0)
		// 	printf (" init %f\n", parzi->dataray[id].ray_ang);
		parzi->colur = 0xFFFFFF;
		if (id == 0 || id == (1440 - 1))
		{
			// if (id == 0)
				// printf (" fata %f\n", parzi->dataray[id].ray_ang);
			dda (parzi, ((parzi->plays->x_play)) + cos(parzi->dataray[id].ray_ang ) * 790, ((parzi->plays->y_play)) + sin(parzi->dataray[id].ray_ang ) * 790);
		}
		// determine_ange (parzi, id);
		cast_an_ray (parzi, id);
		// if (id + 1 <= 1439)
		// {
			parzi->dataray[id + 1].ray_ang = parzi->dataray[id].ray_ang ;
			id++;
			parzi->dataray[id].ray_ang += parzi->plays->f_o_v / 1440;
		// }
		// parzi->dataray[id].ray_ang  = normalize_angle(parzi->dataray[id].ray_ang );
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
	obj->colur = 0x00FF1A;
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
	draw_line (obj);
}

void	ft_draw(t_ray *object, t_play *parzi)
{
	(void) parzi;
	
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
