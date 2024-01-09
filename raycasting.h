/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:36:19 by momihamm          #+#    #+#             */
/*   Updated: 2024/01/09 11:17:14 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

#ifndef PIX_SIZE
# define PIX_SEZE 64
#endif

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
	void			*start;
	void			*window;
	unsigned int	colur_zero;
	unsigned int	colur_one;
	int				the_long_line;
	int				the_rows;
}	t_ray;


/******************************** RAYCASTING **********************************/
float	deg2rad(float degrees);
float	rad2deg(float radians);
void    drawing(t_ray *object, t_cub3d *yous);
void    init_strahl(t_ray *my_struct, t_cub3d *usef);
void	vr_game_map(t_ray *object, t_cub3d *yous_obj);
void	the_longest_line(t_cub3d *usef, t_ray *my_struct);

void	make_square(int row, int clm, t_ray *object);
/******************************************************************************/

#endif