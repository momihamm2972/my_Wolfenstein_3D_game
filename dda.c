/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:01:43 by momihamm          #+#    #+#             */
/*   Updated: 2024/02/08 16:56:36 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

// void    dda(t_cub3d *usef, t_ray *strahl, t_play *parzival)
// {
// 	(void) usef;
// 	(void) strahl;
// 	int	destX;
// 	int	destY;
// 	double	mayl;
// 	// int	newX;
// 	// int	newY;

// 	destX = parzival->x_play + (cos(parzival->rotation_ang) * 10);
// 	destY = parzival->y_play + (sin(parzival->rotation_ang) * 10);
// 	// destX = parzival->x_play + 10;
// 	// destY = parzival->y_play + 10;
// 	mayl = 0;
// 	printf ("X<%d>Y<%d>\t%f\nrot$$$$$$$$$$$$>>%f\n",destX, destY, mayl, parzival->rotation_ang);
// 	mayl = (destX - parzival->x_play) / (destY - parzival->y_play);
// 	if (mayl == 1)
// 	{
// 		strahl->rad = 1;
// 		printf ("increment by 1\n");
// 	}
// 	else if (mayl < 1 )
// 	{
// 		strahl->rad = 0;
// 		printf ("small\n");
// 	}
// 	else if (mayl > 1)
// 	{
// 		strahl->rad = 2;
// 		printf ("BIG\n");
// 	}
// }

// C program for DDA line generation 

// Function for finding absolute value 
// int abs÷(int n) { return ((n > 0) ? n : (n * (-1))); } 

// DDA Function for line generation 
void dda(t_ray *obj, double X0, double Y0, double X1, double Y1) 
{ 
	// calculate dx & dy 
	printf ("ZA %f===%f!!!%f++++++%f\n", X0, Y0, X1,Y1);
	double dx = X1 - X0; 
	double dy = Y1 - Y0; 
	printf ("dx = %f dy =  %f\n",dx, dy);

	// calculate steps required for generating pixels 
	double steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy); 
	printf ("dx = %f dy =  %f\n",dx, dy);
	printf ("step = %f\n", steps);

	// calculate increment in x & y for each steps 
	double Xinc = dx / (double)steps; 
	double Yinc = dy / (double)steps; 

	printf ("Xi = %f Yi = %f\n", Xinc, Yinc);
	// Put pixel for each step 
	float X = X0; 
	float Y = Y0; 
	for (int i = 0; i <= steps; i++) { 
		// putpixel(round(X), round(Y), RED); // put pixel at (X,Y) 
		putPixImg(obj->myImage, X, Y, obj->colur);
		X += Xinc; // increment in x at each step 
		Y += Yinc; // increment in y at each step 
		// delay(100); // for visualization of line- 
					// generation step by step 
	} 
} 

// Driver program 
