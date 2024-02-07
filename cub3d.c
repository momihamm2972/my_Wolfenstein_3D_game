/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:26:57 by yonadry           #+#    #+#             */
/*   Updated: 2024/02/07 19:59:19 by momihamm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d.h"
#include "raycasting.h"

void    free_all(t_cub3d *cub3d)
{
    free(cub3d->east_texture);
    free(cub3d->north_texture);
    free(cub3d->west_texture);
    free(cub3d->south_texture);
    free_strs(cub3d->map, 0);
    free(cub3d);
}

int main(int ac, char **av)
{
    t_cub3d	*cub3d;
    t_ray	*strahl;
    t_play  *parzival;

    if (ac == 2)
    {
        cub3d = malloc(sizeof(t_cub3d));
		strahl = malloc (sizeof(t_ray));
        parzival = malloc (sizeof(t_play));
        cub3d->file_name = check_extension(av[1]);
        read_map_elements(cub3d);
		init_strahl (strahl, cub3d, parzival);
        getCurntPosi(parzival, cub3d);
        printf ("x>>%d\ty>>%d\n",parzival->x_play , parzival->y_play);
        // dda(cub3d, strahl, parzival);
        drawing (strahl, cub3d, parzival);
        free_all(cub3d);
    }
    else
		ft_putstr("Error\nPlease input a valid argument");
}
