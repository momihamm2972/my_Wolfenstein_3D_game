/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ddaUtils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:41:21 by momihamm          #+#    #+#             */
/*   Updated: 2024/02/14 10:18:31 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

void	get_curnt_posi(t_play *parzival, t_cub3d *yous)
{
	int	row;
	int	clm;

	row = 0;
	while (yous->map[row])
	{
		clm = 0;
		while (yous->map[row][clm])
		{
			if (check_is_player(yous->map[row][clm]) == 1)
			{
				parzival->x_play = clm;
				parzival->y_play = row;
				return ;
			}
			clm++;
		}
		row++;
	}
	return ;
}
