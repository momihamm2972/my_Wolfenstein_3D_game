/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_a_binary_to_a_game.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:41:58 by momihamm          #+#    #+#             */
/*   Updated: 2024/02/12 02:07:25 by momihamm         ###   ########.fr       */
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
	ready->rotation_ang = M_PI;
	ready->move_speed = 2.0;
	ready->rotation_speed = 2 * (M_PI / 180);
}

void	ft_again (t_ray *obj)
{
	int		row;
	int		clm;

	row = 0;
	while (obj->gameMap[row])
	{
		clm = 0;
		while (obj->gameMap[row][clm])
		{
			if (obj->gameMap[row][clm] == '1')
				make_square(row, clm, obj);
			else if (obj->gameMap[row][clm] == '+')
				make_square (row, clm, obj);
			// if (check_is_player (object->gameMap[row][clm]) == 1)
			// {
			// 	make_square (row, clm, object);
			// 	object->colur = 0xEE0505;
			// 	dda(object,(parzival->x_play * 32) + 16, (parzival->y_play * 32) + 16, ((parzival->x_play * 32) + 16) +cos(parzival->rotation_ang)* 40, ((parzival->y_play * 32) + 16 )+sin(parzival->rotation_ang)*40);
			// }
			clm++;
		}
		row++;
	}
	obj->colur = 0xFFFFFF;
	int x =0;
	int y =0;
	int var =12;
	int val = 12;
	while (x < 8)
	{
		y = 0;
		var = 12;
		while (y < 8)
		{
			putPixImg (obj->myImage, (obj->playstation->x_play * 32) + var, (obj->playstation->y_play * 32) + val, obj->colur);
			y++;
			var++;
		}
		x++;
		val++;
	}
	// putPixImg (obj->myImage, (obj->playstation->x_play * 32) + 12, (obj->playstation->y_play * 32) + 12, obj->colur);
	// putPixImg (obj->myImage, (obj->playstation->x_play * 32) + 13, (obj->playstation->y_play * 32) + 12, obj->colur);
	// putPixImg (obj->myImage, (obj->playstation->x_play * 32) + 14, (obj->playstation->y_play * 32) + 12, obj->colur);
	// putPixImg (obj->myImage, (obj->playstation->x_play * 32) + 15, (obj->playstation->y_play * 32) + 12, obj->colur);
	// putPixImg (obj->myImage, (obj->playstation->x_play * 32) + 16, (obj->playstation->y_play * 32) + 12, obj->colur);
	// putPixImg (obj->myImage, (obj->playstation->x_play * 32) + 17, (obj->playstation->y_play * 32) + 12, obj->colur);
	// putPixImg (obj->myImage, (obj->playstation->x_play * 32) + 18, (obj->playstation->y_play * 32) + 12, obj->colur);
	// putPixImg (obj->myImage, (obj->playstation->x_play * 32) + 19, (obj->playstation->y_play * 32) + 12, obj->colur);
	obj->colur = 0xEE0505;
	dda(obj,(obj->playstation->x_play * 32) + 16, (obj->playstation->y_play * 32) + 16, ((obj->playstation->x_play * 32) + 16) +cos(obj->playstation->rotation_ang)* 40, ((obj->playstation->y_play * 32) + 16 )+sin(obj->playstation->rotation_ang)*40);
	mlx_put_image_to_window (obj->start, obj->window, obj->myImage->mlxImage, 0 , 0);
}


void	ft_draw (t_ray *object, t_play *parzival)
{
	int		row;
	int		clm;
	(void) parzival;
// printf ("start drawing\n");
	row = 0;
	while (object->gameMap[row])
	{
		clm = 0;
		while (object->gameMap[row][clm])
		{
			if (object->gameMap[row][clm] == '1')
				make_square(row, clm, object);
			else if (object->gameMap[row][clm] == '+')
				make_square (row, clm, object);
			// if (check_is_player (object->gameMap[row][clm]) == 1)
			// {
			// 	make_square (row, clm, object);
			// 	object->colur = 0xEE0505;
			// 	dda(object,(parzival->x_play * 32) + 16, (parzival->y_play * 32) + 16, ((parzival->x_play * 32) + 16) +cos(parzival->rotation_ang)* 40, ((parzival->y_play * 32) + 16 )+sin(parzival->rotation_ang)*40);
			// }
			clm++;
		}
		row++;
	}
	row = 0;
	while (object->gameMap[row])
	{
		clm = 0;
		while (object->gameMap[row][clm])
		{
			// if (object->gameMap[row][clm] == '1')
			// 	make_square(row, clm, object);
			// else if (object->gameMap[row][clm] == '+')
			// 	make_square (row, clm, object);
			if (check_is_player (object->gameMap[row][clm]) == 1)
			{
				make_square (row, clm, object);
				object->colur = 0xEE0505;
				dda(object,(parzival->x_play * 32) + 16, (parzival->y_play * 32) + 16, ((parzival->x_play * 32) + 16) +cos(parzival->rotation_ang)* 40, ((parzival->y_play * 32) + 16 )+sin(parzival->rotation_ang)*40);
			}
			clm++;
		}
		row++;
	}
	// updateTheGame(object, yous_obj, parzival);
	mlx_put_image_to_window (object->start, object->window, object->myImage->mlxImage, 0 , 0);
	// mlx_put_image_to_window (object->start, object->window, object->myImage->mlxImage, 0,0);
}


void	updateTheGame(t_ray *obj, t_cub3d *usef, t_play *parzival)
{
	(void) obj;
	(void) usef;
	(void) parzival;
	mlx_put_image_to_window (obj->start, obj->window, obj->myImage->mlxImage, 0,0);
	derictions (parzival, obj, usef);
	mlx_destroy_image(obj->start, obj->myImage->mlxImage);
	mlx_clear_window (obj->start, obj->window);
	// if (obj->myImage->mlxImage == NULL)
	// 	printf ("khawya\n");
	// else
	// 	printf ("3amra\n");
	obj->myImage->mlxImage = mlx_new_image (obj->start, obj->the_long_line * 32,
			obj->the_rows * 32);
	obj->myImage->dataAddr = mlx_get_data_addr (obj->myImage->mlxImage, &obj->myImage->intPerPixl, &obj->myImage->lenOfLine, &obj->myImage->end);
	parzival->rotation_ang = 0;
	// vr_game_map(obj, usef,parzival);
	// ft_draw (obj, usef, parzival);
}