/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgpix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:19:57 by momihamm          #+#    #+#             */
/*   Updated: 2024/03/12 00:49:02 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

int	my_strlen (char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	put_pix_img(t_img *img, int x, int y, int colur)
{
	char	*puting;
	// int		lenght;
 
	if (x < 0 || y < 0)
		return ;
	puting = img->data_addr + (y * img->lenofline + x * (img->intperpixl / 8));
	// lenght = my_strlen (puting);
	// if (y > lenght)
	// 	return ;
	*(int *) puting = colur;
}

// void	put_pix_img(t_img *img, int x, int y, int color)
// {
//     char    *pixel;
//     int		i;

//     i = img->intperpixl - 8;
//     pixel = img->data_addr + (y * img->lenofline + x * (img->intperpixl / 8));
//     while (i >= 0)
//     {
//         /* big endian, MSB is the leftmost bit */
//         if (img->end != 0)
//             *pixel++ = (color >> i) & 0xFF;
//         /* little endian, LSB is the leftmost bit */
//         else
//             *pixel++ = (color >> (img->intperpixl - 8 - i)) & 0xFF;
//         i -= 8;
//     }
// }
