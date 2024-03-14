/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_and_reless.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 02:12:07 by momihamm          #+#    #+#             */
/*   Updated: 2024/03/14 02:13:18 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

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
