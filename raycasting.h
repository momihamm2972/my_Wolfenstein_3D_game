/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:36:19 by momihamm          #+#    #+#             */
/*   Updated: 2024/02/12 00:07:59 by momihamm         ###   ########.fr       */
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

// typedef struct rendData
// {
//     void	*mlx_ptr;
//     void	*win_ptr;
//     // t_img	img;
// }	t_rendata;


typedef struct player
{
	int		x_play;
	int		y_play;
	int		turn_d;
	int		walk_d;
	double	rotation_ang;
	double	move_speed;
	double	rotation_speed;
}	t_play;

typedef struct ray
{
	void			*start;
	void			*window;
	char			**gameMap;
	int				colur;
	int				the_long_line;
	int				the_rows;
	int				rad;
	t_img			*myImage;
	// t_rendata		*data;
	t_play			*playstation;
}	t_ray;

/******************************** RAYCASTING **********************************/
void	drawing(t_ray *object, t_cub3d *yous, t_play *ashly);
void	init_strahl(t_ray *my_struct, t_cub3d *usef, t_play *play);
void	vr_game_map(t_ray *object, t_cub3d *yous_obj, t_play *parzival);
void	the_longest_line(t_cub3d *usef, t_ray *my_struct);
void	make_vue(int row, int clm, t_ray *object);
void	the_values_of_vue(int *var, int *x_);
void	derictions(t_play *parzival, t_ray *obje, t_cub3d *usef);
void	init_player(t_play *ready, t_cub3d *usef);
// void	make_square(int row, int clm, t_ray *object, t_cub3d *yous);
// int    putPixImg(t_img *img, int x, int y, int colur);
int    putPixStrahl(t_img *img, int x, int y, int colur, t_ray *noName);
void    putPixImg(t_img *img, int x, int y, int colur);
void    getCurntPosi(t_play *parzival, t_cub3d *yous);
int		check_is_player(char c);
// int		ft_move(int events, t_play *parzival);
int		whileMoving(t_play *bayren);
float	deg2rad(float degrees);
float	rad2deg(float radians);
void	make_a_strahl(t_ray *obje,t_play *parzival, int row, int clm, int rad);
// void    dda(t_cub3d *usef, t_ray *strahl, t_play *parzival);
void dda(t_ray *obj, double X0, double Y0, double X1, double Y1);
void	updateTheGame(t_ray *obj, t_cub3d *usef, t_play *parzival);
void	ft_draw (t_ray *object, t_play *parzival);
void	initData(t_ray *obj);




void    mlxArt(t_cub3d *usef, t_ray *strahl, t_play *parzival);
int	close_the_win(void);
void	makeValus(t_play *blanka);
// int	ft_move(int events, t_play *parzival, t_ray *obj);
int	ft_move(int events, void *object);
void	make_square(int row, int clm, t_ray *object);
void	ft_again (t_ray *obj);
/******************************************************************************/

#endif