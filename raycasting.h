/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:36:19 by momihamm          #+#    #+#             */
/*   Updated: 2024/01/08 17:27:47 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"
# include <mlx.h>
// # include <stdio.h>
// # include <unistd.h>
// # include <math.h>
// # include <stdlib.h>
// # include <string.h>
// # include <fcntl.h>
// # include <stdint.h>

typedef struct ray
{
	int ray;
}	t_ray;


/******************************** RAYCASTING **********************************/
float	deg2rad(float degrees);
float	rad2deg(float radians);
// void    initial_vars(t_cub3d *yous_struct, t_ray *my_struct);
/******************************************************************************/

#endif