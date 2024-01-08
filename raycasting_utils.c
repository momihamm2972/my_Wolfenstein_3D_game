/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:44:11 by momihamm          #+#    #+#             */
/*   Updated: 2024/01/06 17:51:58 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

float	deg2rad(float degrees)
{
	return (degrees * (M_PI / 180.0));
}

float	rad2deg(float radians)
{
	return (radians * (180.0 / M_PI));
}
