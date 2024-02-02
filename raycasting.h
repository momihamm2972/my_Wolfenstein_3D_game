/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:36:19 by momihamm          #+#    #+#             */
/*   Updated: 2024/02/02 20:43:29 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"
# include <mlx.h>

typedef struct image
{
	void			*mlxImage;
	char			*dataAddr;
	int				intPerPixl;
	int				lenOfLine;
	int				end;
}	t_img;

typedef struct rendData
{
    void	*mlx_ptr;
    void	*win_ptr;
    t_img	img;
}	t_rendata;

typedef struct ray
{
	void			*start;
	void			*window;
	int				colur;
	int				the_long_line;
	int				the_rows;
	t_img			*myImage;
	t_rendata		*data;
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
void	drawing(t_ray *object, t_cub3d *yous, t_play *ashly);
void	init_strahl(t_ray *my_struct, t_cub3d *usef, t_play *play);
void	vr_game_map(t_ray *object, t_cub3d *yous_obj, t_play *parzival);
void	the_longest_line(t_cub3d *usef, t_ray *my_struct);
void	make_vue(int row, int clm, t_ray *object);
void	the_values_of_vue(int *var, int *x_);
void	derictions(t_play *parzival, t_ray *obje, t_cub3d *usef);
void	init_player(t_play *ready);
void	make_square(int row, int clm, t_ray *object, t_cub3d *yous);
int		check_is_player(char c);
int		ft_move(int events, t_play *parzival);
float	deg2rad(float degrees);
float	rad2deg(float radians);
/******************************************************************************/

#endif