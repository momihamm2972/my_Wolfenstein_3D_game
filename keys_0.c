/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 16:28:57 by momihamm          #+#    #+#             */
/*   Updated: 2024/02/16 12:49:16 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	close_the_win(void)
{
	exit (0);
}

int	is_wall(t_ray *obj, double x, double y)
{
	int	row;
	int	clm;
// 	double x_z;
// 	double y_z;
// 	int i = 0;
// 	// double x_o;
// 	// double y_o;

// 	// x_z = x - 0.5;
// 	// y_z = y - 0.5;
// 	x_z =  (x * 32) - 4;
// 	y_z =  (y * 32) - 4;

printf ("=%f=\t +%f+\n", x * 32, y * 32);
// // printf ("@%f@\t @%f@\n", x, y);
// 	x_z = x_z /32;
// 	y_z = y_z /32;
	// clm = floor (x);
	// row = floor (y);
	// clm = (int)round (x);
	// row = (int)round (y);
	x = ((x * 32) + 13) / 32;
	y = ((y * 32) + 11) / 32;
	clm = floor (x);
	row = floor (y);
	// printf ("row %d clm %d\n", row, clm);
	if (obj->game_map[row][clm] == '1')
	{
printf (">>>>>>%d>÷>>>%d>>>>>one\n", row, clm);		// obj->game_map[row][clm] = '$';
		// for (int i=0;i < obj->the_rows ; i++)
		// {
		// 	printf ("%s\n", obj->game_map[i]);
		// }
		// exit (0);
		return (-1);
		// i++;
	}
// 	x_z =  (x * 32) + 4;
// 	y_z =  (y * 32) - 4;
// 	x_z = x_z /32;
// 	y_z = y_z /32;
// // printf ("=%f=\t +%f+\n", x, y);
// // printf ("@%f@\t @%f@\n", x, y);
// 	// clm = floor (x);
// 	// row = floor (y);
// 	clm = (int)round (x_z);
// 	row = (int)round (y_z);
// 	// printf ("row %d clm %d\n", row, clm);
// 	if (obj->game_map[row][clm] == '1')
// 	{
// printf (">>>>>>%d>÷>>>%d>>>>>two\n", row, clm);		// printf (">>>>>>>>>>>>>>>%c\n", obj->game_map[row][clm]);
// 		// obj->game_map[row][clm] = '$';
// 		// for (int i=0;i < obj->the_rows ; i++)
// 		// {
// 		// 	printf ("%s\n", obj->game_map[i]);
// 		// }
// 		// exit (0);
// 		// return (-1);
// 		i++;
// 	}
// 	x_z =  (x * 32) - 4;
// 	y_z =  (y * 32) + 4;
// 	x_z = x_z /32;
// 	y_z = y_z /32;
// // printf ("=%f=\t +%f+\n", x, y);
// // printf ("@%f@\t @%f@\n", x, y);
// 	// clm = floor (x);
// 	// row = floor (y);
// 	clm = (int)round (x_z);
// 	row = (int)round (y_z);
// 	// printf ("row %d clm %d\n", row, clm);
// 	if (obj->game_map[row][clm] == '1')
// 	{
// 		printf (">>>>>>%d>÷>>>%d>>>>>three\n", row, clm);
// 		// printf (">>>>>>>>>>>>>>>%c\n", obj->game_map[row][clm]);
// 		// obj->game_map[row][clm] = '$';
// 		// for (int i=0;i < obj->the_rows ; i++)
// 		// {
// 		// 	printf ("%s\n", obj->game_map[i]);
// 		// }
// 		// exit (0);
// 		// return (-1);
// 		i++;
// 	}

// 	x_z =  (x * 32) + 4;
// 	y_z =  (y * 32) + 4;
// 	x_z = x_z /32;
// 	y_z = y_z /32;
// // printf ("=%f=\t +%f+\n", x, y);
// // printf ("@%f@\t @%f@\n", x, y);
// 	// clm = floor (x);
// 	// row = floor (y);
// 	clm = (int)round (x_z);
// 	row = (int)round (y_z);
// 	// printf ("row %d clm %d\n", row, clm);
// 	if (obj->game_map[row][clm] == '1')
// 	{
// printf (">>>>>>%d>÷>>>%d>>>>>for\n", row, clm);		// printf (">>>>>>>>>>>>>>>%c\n", obj->game_map[row][clm]);
// 		// obj->game_map[row][clm] = '$';
// 		// for (int i=0;i < obj->the_rows ; i++)
// 		// {
// 		// 	printf ("%s\n", obj->game_map[i]);
// 		// }
// 		// exit (0);
// 		return (-1);
// 		// i++;
// 	}
	
	// clm = (int)round (x_z);
	// row = (int)round (y_z);
	// // printf ("row %d clm %d\n", row, clm);
	// if (obj->game_map[row][clm] == '1')
	// {
	// 	// printf (">>>>>>>>>>>>>>>%c\n", obj->game_map[row][clm]);
	// 	// obj->game_map[row][clm] = '$';
	// 	// for (int i=0;i < obj->the_rows ; i++)
	// 	// {
	// 	// 	printf ("%s\n", obj->game_map[i]);
	// 	// }
	// 	// exit (0);
	// 	return (-1);
	// }
	// else
	// 	printf (">>>>>>>>>>>>>>>%c\n", obj->game_map[row][clm]);
	// if (i >= 0)
	// 	return (-1);
	return (0);
}

void	make_valus(t_play *blanka, t_ray *obj)
{
	double	movestep;
	// double	new_x;
	// double	new_y;
(void) obj;
	blanka->rot_ang += blanka->turn_d * blanka->rotation_speed;
	movestep = blanka->walk_d * blanka->move_speed / 16;
	// get_curnt_posi ()
	// new_posi (obj);
	
	// printf ("!%f!\t @%f@\n", blanka->player_xx, blanka->player_yy);
	// new_x = (blanka->player_xx / 32) + (cos(blanka->rot_ang) * movestep);
	// new_y = (blanka->player_yy / 32) + (sin(blanka->rot_ang) * movestep);
	// blanka->new_x = blanka->x_play + (cos(blanka->rot_ang) * movestep);
	// blanka->new_y = blanka->y_play + (sin(blanka->rot_ang) * movestep);
	// printf ("older than old valus X %f\t Y %f\n", blanka->x_play, blanka->y_play);
	blanka->x_play += cos(blanka->rot_ang) * movestep;
	blanka->y_play += sin(blanka->rot_ang) * movestep;
	blanka->new_x = blanka->x_play - cos(blanka->rot_ang) * movestep;
	blanka->new_y = blanka->y_play - sin(blanka->rot_ang) * movestep;

	// printf ("old valus x {%f)\t y @%f}\n", blanka->x_play, blanka->y_play);
	// // printf ("!%f!\t @%f@\n", blanka->x_play, blanka->y_play);
	
	if ((is_wall (obj, blanka->x_play, blanka->y_play) == -1))
	{
		blanka->x_play = blanka->new_x;
		blanka->y_play = blanka->new_y;
		// printf ("new valus x %f \tY %f \n", blanka->new_x, blanka->new_y);
	}
	else
		printf ("\n\n\n\n\nzre3\n\n\n\n\n\n\n");
}

void	resetval(t_ray *obj)
{
	obj->plays->turn_d = 0;
	obj->plays->walk_d = 0;
}

int	ft_mover(int events, void *object)
{
	t_ray	*obj;

	obj = (t_ray *)object;
	if (events == 53)
		close_the_win ();
	if (events == 124 || events == 2)
		obj->plays->turn_d = 0;
	if (events == 123 || events == 0)
		obj->plays->turn_d = 0;
	if (events == 126 || events == 13)
		obj->plays->walk_d = 0;
	if (events == 125 || events == 1)
		obj->plays->walk_d = 0;
	return (0);
}

int	ft_move(int events, void *object)
{
	t_ray	*obj;

	obj = (t_ray *) object;
	if (events == 53)
		close_the_win ();
	if (events == 124 || events == 2)
		obj->plays->turn_d = 1;
	if (events == 123 || events == 0)
		obj->plays->turn_d = -1;
	if (events == 126 || events == 13)
		obj->plays->walk_d = 1;
	if (events == 125 || events == 1)
		obj->plays->walk_d = -1;
	return (0);
}
