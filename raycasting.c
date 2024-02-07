/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:36:21 by momihamm          #+#    #+#             */
/*   Updated: 2024/02/06 20:58:36 by momihamm         ###   ########.fr       */
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
	obj->data = malloc (sizeof (t_rendata));
	obj->data->mlx_ptr = obj->start;
	obj->data->win_ptr = obj->window;
}

/****************/
/***** DRAW *****/
void	drawing(t_ray *object, t_cub3d *yous, t_play *ashly)
{
	object->window = mlx_new_window (object->start, object->the_long_line * 32,
			object->the_rows * 32, "lo3ba");
	object->myImage = malloc (sizeof (t_img));
	object->myImage->mlxImage = mlx_new_image (object->start, object->the_long_line * 32,
			object->the_rows * 32);
	initData(object);
	object->myImage->dataAddr = mlx_get_data_addr (object->myImage->mlxImage, &object->myImage->intPerPixl, &object->myImage->lenOfLine, &object->myImage->end);
	// putPixImg(object->myImage,)
	printf ("\n!\n%s\n!\n", object->myImage->dataAddr);
	vr_game_map (object, yous, ashly);
	mlx_loop (object->start);
}
/****************/