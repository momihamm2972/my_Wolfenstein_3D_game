/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgpix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:19:57 by momihamm          #+#    #+#             */
/*   Updated: 2024/02/07 22:11:47 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void    putPixImg(t_img *img, int x, int y, int colur)
{
	char *puting;

	puting = img->dataAddr + (y * img->lenOfLine + x * (img->intPerPixl / 8));
	*(int *) puting = colur;
}
int    putPixStrahl(t_img *img, int x, int y, int colur, t_ray *noName)
{
	char *puting;

	// printf ("$9wada$%d!kmi!%d\n",x,y );
	// if (!img->dataAddr[x] || !img->dataAddr[y])
	// {
	// 	printf ("mo9arib mail\n@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n");
	// 	return (1);
	// }
	if (x > 0 && y > 0 && x < noName->the_long_line && y < noName->the_rows)
	{
	puting = img->dataAddr + (y * img->lenOfLine + x * (img->intPerPixl / 8));
	*(int *) puting = colur;
	}
	else 
	{
		// printf ("NONAME\n");
		// exit (1);
		return (1);
	}
	*(int *) puting = colur;
	return (0);
}
