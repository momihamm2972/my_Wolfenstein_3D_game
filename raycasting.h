/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:36:19 by momihamm          #+#    #+#             */
/*   Updated: 2024/02/14 08:17:24 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "cub3d.h"
# include <mlx.h>

typedef struct image
{
	void	*mlx_img;
	char	*data_addr;
	int		intperpixl;
	int		lenofline;
	int		end;
}	t_img;

typedef struct player
{
	int			turn_d;
	int			walk_d;
	double		x_play;
	double		y_play;
	double		rot_ang;
	double		move_speed;
	double		rotation_speed;
}	t_play;

typedef struct ray
{
	void			*start;
	void			*window;
	char			**game_map;
	int				colur;
	int				the_long_line;
	int				the_rows;
	int				rad;
	t_img			*my_image;
	t_play			*plays;
}	t_ray;

/******************************** RAYCASTING **********************************/
// void	drawing(t_ray *object, t_cub3d *yous, t_play *ashly);
// void	init_strahl(t_ray *my_struct, t_cub3d *usef, t_play *play);
void	the_longest_line(t_cub3d *usef, t_ray *my_struct);
void	make_vue(int row, int clm, t_ray *object);
void	the_values_of_vue(int *var, int *x_);
// void	derictions(t_play *parzival, t_ray *obje, t_cub3d *usef);
void	init_player(t_play *ready, t_cub3d *usef);
void	put_pix_img(t_img *img, int x, int y, int colur);
void	getCurntPosi(t_play *parzival, t_cub3d *yous);
void	dda(t_ray *obj, double X1, double Y1);
void	updateTheGame(t_ray *obj, t_cub3d *usef, t_play *parzival);
void	ft_draw(t_ray *object, t_play *parzival);
// void	initData(t_ray *obj);
void	mlxArt(t_cub3d *usef, t_ray *strahl, t_play *parzival);
void	make_valus(t_play *blanka);
void	make_square(int row, int clm, t_ray *object);
int		check_is_player(char c);
int		whileMoving(t_play *bayren);
int		close_the_win(void);
int		ft_move(int events, void *object);
int		ft_again(t_ray *obj);
int		ft_mover(int events, void *object);
// float	deg2rad(float degrees);
// float	rad2deg(float radians);
/******************************************************************************/

#endif