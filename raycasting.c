/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:36:21 by momihamm          #+#    #+#             */
/*   Updated: 2024/02/11 04:07:29 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

//TO DO :: INITIALSATION ALL VAR THAT I WILL USE AND START DRAWING

/**** INITIA ****/
void	init_strahl(t_ray *my_struct, t_cub3d *usef, t_play *play)
{
	my_struct->start = mlx_init ();
	init_player (play, usef);
	the_longest_line (usef, my_struct);
}

void	initData(t_ray *obj)
{
	(void) obj;
	// obj->data = malloc (sizeof (t_rendata));
	// obj->data->mlx_ptr = obj->start;
	// obj->data->win_ptr = obj->window;
}

/****************/
/***** DRAW *****/

// void	mlxxThings(t_ray *obj, t_cub3d *usef, t_play *ashly)
// {
// 	initData(obj);
// 	(void) usef;
// 	(void) ashly;
// 	obj->myImage->dataAddr =  mlx_get_data_addr (obj->myImage->mlxImage, &obj->myImage->intPerPixl, &obj->myImage->lenOfLine, &obj->myImage->end);
// }

void	drawing(t_ray *object, t_cub3d *yous, t_play *ashly)
{
	(void) ashly;
	(void) yous;
	object->myImage = malloc (sizeof (t_img));
	object->window = mlx_new_window (object->start, object->the_long_line * 32,
			object->the_rows * 32, "nadi canadi");
	object->myImage->mlxImage = mlx_new_image (object->start, object->the_long_line * 32,
			object->the_rows * 32);
	initData(object);
	object->myImage->dataAddr = mlx_get_data_addr (object->myImage->mlxImage, &object->myImage->intPerPixl, &object->myImage->lenOfLine, &object->myImage->end);
	printf ("vix\n");
	// putPixImg(object->myImage,)
	printf ("fin\n!\n%s\n!\n", object->myImage->dataAddr);
	// vr_game_map (object, yous, ashly);
	
	ft_draw (object,yous, ashly);
	// updateTheGame (object, yous, ashly);
	// mlx_loop (object->start);
}
/****************/