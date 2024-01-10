/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:36:19 by momihamm          #+#    #+#             */
/*   Updated: 2024/01/10 21:37:45 by momihamm         ###   ########.fr       */
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
	// unsigned int	colur_zero;
	// unsigned int	colur_one;
	int				colur;
	int				the_long_line;
	int				the_rows;
}	t_ray;

typedef struct player
{
	int		x_play;
	int		y_play;
	int		turn_d;
	int		walk_d;
	float	rotation_ang;
	float	move_speed;
	float	rotation_speed;
}	t_play;

/******************************** RAYCASTING **********************************/
float	deg2rad(float degrees);
float	rad2deg(float radians);
void    drawing(t_ray *object, t_cub3d *yous, t_play *ashly);
void    init_strahl(t_ray *my_struct, t_cub3d *usef, t_play *play);
void	vr_game_map(t_ray *object, t_cub3d *yous_obj, t_play *parzival);
void	the_longest_line(t_cub3d *usef, t_ray *my_struct);
void	make_vue (int row, int clm, t_ray *object);
void	the_values_of_vue(int *var, int *x_);
int		check_is_player(char c);
void	derictions(t_play *parzival, t_ray *obje, t_cub3d *usef);
int		ft_move(int events, t_play *parzival);
void	init_player (t_play *ready);

void	make_square(int row, int clm, t_ray *object, t_cub3d *yous);
/******************************************************************************/

#endif