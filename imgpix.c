/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgpix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:19:57 by momihamm          #+#    #+#             */
/*   Updated: 2024/02/03 17:31:55 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void    putPixImg(t_img *img, int x, int y, int colur)
{
	char *puting;

	puting = img->dataAddr + (y * img->lenOfLine + x * (img->intPerPixl / 8));
	*(int *) puting = colur;
}
