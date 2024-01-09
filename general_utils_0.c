/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_utils_0.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:48:58 by momihamm          #+#    #+#             */
/*   Updated: 2024/01/09 11:17:04 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	the_longest_line(t_cub3d *usef, t_ray *my_struct)
{
	int	big_len;
	int	row;

	big_len = 0;
	row = 0;
	printf ("lkmaya\n");
	while (usef->map[row])
	{
		if ((int)ft_strlen (usef->map[row]) > big_len)
			big_len = (int)ft_strlen(usef->map[row]);
		printf (">>>>%d\n", row);
		row++;
	}
	my_struct->the_long_line = big_len;
	my_struct->the_rows = row;
}
