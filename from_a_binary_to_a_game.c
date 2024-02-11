/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_a_binary_to_a_game.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:41:58 by momihamm          #+#    #+#             */
/*   Updated: 2024/02/11 01:31:16 by momihamm         ###   ########.fr       */
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
	ready->move_speed = 0.0;
	ready->rotation_speed = 1.0;
}


void	ft_draw (t_ray *object, t_cub3d *yous_obj, t_play *parzival)
{
	int		row;
	int		clm;
printf ("start drawing\n");
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
				make_square (row, clm, object, yous_obj);
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
	if (obj->myImage->mlxImage == NULL)
		printf ("khawya\n");
	else
		printf ("3amra\n");
	obj->myImage->mlxImage = mlx_new_image (obj->start, obj->the_long_line * 32,
			obj->the_rows * 32);
	obj->myImage->dataAddr = mlx_get_data_addr (obj->myImage->mlxImage, &obj->myImage->intPerPixl, &obj->myImage->lenOfLine, &obj->myImage->end);
	parzival->rotation_ang = 0;
	// vr_game_map(obj, usef,parzival);
	// ft_draw (obj, usef, parzival);
}