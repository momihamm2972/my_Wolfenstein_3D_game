/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:36:21 by momihamm          #+#    #+#             */
/*   Updated: 2024/01/09 11:21:36 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

//TO DO :: INITIALSATION ALL VAR THAT I WILL USE AND START DRAWING

/**** INITIA ****/
void    init_strahl(t_ray *my_struct, t_cub3d *usef)
{
    my_struct->start = mlx_init ();
    // my_struct->the_long_line = the_longest_line (usef->map);
    the_longest_line(usef, my_struct);
}
/****************/
/***** DRAW *****/
void    drawing(t_ray *object, t_cub3d *yous)
{
    (void) yous;
    // object->start = mlx_init ();
    printf ("the longest == %d\n", object->the_long_line);
    object->window = mlx_new_window (object->start, object->the_long_line * 32, object->the_rows * 32, "lo3ba");
    vr_game_map (object, yous);
    mlx_loop (object->start);
}
/****************/