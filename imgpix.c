/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgpix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:19:57 by momihamm          #+#    #+#             */
/*   Updated: 2024/03/16 08:22:41 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	put_pix_img(t_img *img, int x, int y, int colur)
{
	char	*puting;

	if (x < 0 || x >= RAYS_WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	puting = img->data_addr + (y * img->lenofline + x * (img->intperpixl / 8));
	*(int *) puting = colur;
}
