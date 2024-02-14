/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:01:43 by momihamm          #+#    #+#             */
/*   Updated: 2024/02/14 08:15:54 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void new_posi(t_ray *parzi)
{
	int	row;
	int	clm;

	row = 0;
	while (parzi->game_map[row])
	{
		clm = 0;
		while (parzi->game_map[row][clm])
		{
			if (check_is_player(parzi->game_map[row][clm]) == 1)
			{
				parzi->plays->x_play = clm;
				parzi->plays->y_play = row;
				return ;
			} 
			clm++;
		}
		row++;
	}
}

void dda(t_ray *obj, double X1, double Y1) 
{ 
	printf ("Y42rzOtUGOartQJINe27aJu3oKUVYISG2A88OZYvfGb7JqpmnjY4\n2rzOtUGOartQJINe27aJu3oKUVYISG2A88OZYvfGb7JqpmnjY42rzOtUGOartQJIN\ne27aJu3oKUVYISG2A88OZYvfGb7JqpmnjY42rzOtUGOartQJINe27aJu3oKUVYISG2A88OZY\nvfGb7JqpmnjY42rzOtUGOartQJINe27aJu3oKUVYISG2A88OZYvfGb\n7JqpmnjY42rzOtUGO\nartQJINe27aJu3oKUVYISG2A88OZYvfGb7JqpmnjY42rzOtUGOartQJINe27aJu3oKUVYISG\n2A88OZYvfGb7JqpmnjY42rzOtUGOartQJINe27aJu3oKUVYISG2A88OZYvfGb7Jqpmnj\n");
	double X0= (obj->plays->x_play * 32) + 16;
	double Y0=  (obj->plays->y_play * 32) + 16;
	double dx = X1 - X0; 
	double dy = Y1 - Y0; 
	double steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy); 
	double Xinc = dx / (double)steps; 
	double Yinc = dy / (double)steps; 
	float X = X0; 
	float Y = Y0; 
	for (int i = 0; i <= steps; i++) { 
		put_pix_img(obj->my_image, X, Y, obj->colur);
		X += Xinc;
		Y += Yinc;
	} 
} 


// void dda(t_ray *obj, double X0, double Y0, double X1, double Y1) 
// { 
// 	double dx = X1 - X0; 
// 	double dy = Y1 - Y0; 
// 	// printf ("X = %f \t Y = %f\n@!@!@!@!@!@!@!@!@!@", X0, Y0);
// 	// new_posi (obj);
// 	// printf ("x = %f \t y = %f\n@!@!@!@!@!@!@!@!@!@", obj->plays->x_play, obj->plays->y_play);
// 	// printf ("xn = %f \t yn = %f\n@!@!@!@!@!@!@!@!@!@", (obj->plays->x_play * 32) + 16, (obj->plays->y_play * 32) + 16);
// 	double steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy); 
// 	double Xinc = dx / (double)steps; 
// 	double Yinc = dy / (double)steps; 
// 	float X = X0; 
// 	float Y = Y0; 
// 	for (int i = 0; i <= steps; i++) { 
// 		putPixImg(obj->my_image, X, Y, obj->colur);
// 		X += Xinc;
// 		Y += Yinc;
// 	} 
// } 