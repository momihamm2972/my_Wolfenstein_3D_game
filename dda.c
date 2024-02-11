/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:01:43 by momihamm          #+#    #+#             */
/*   Updated: 2024/02/08 17:22:06 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void dda(t_ray *obj, double X0, double Y0, double X1, double Y1) 
{ 
	double dx = X1 - X0; 
	double dy = Y1 - Y0; 
	double steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy); 
	double Xinc = dx / (double)steps; 
	double Yinc = dy / (double)steps; 
	float X = X0; 
	float Y = Y0; 
	for (int i = 0; i <= steps; i++) { 
		putPixImg(obj->myImage, X, Y, obj->colur);
		X += Xinc;
		Y += Yinc;
	} 
} 
