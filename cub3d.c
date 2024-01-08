/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:26:57 by yonadry           #+#    #+#             */
/*   Updated: 2024/01/08 17:37:49 by momihamm         ###   ########.fr       */
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
    t_cub3d *cub3d;

    if (ac == 2)
    {
        cub3d = malloc(sizeof(t_cub3d));
        // init_struct(cub3d);
        cub3d->file_name = check_extension(av[1]);
        read_map_elements(cub3d);
        free_all(cub3d);
    }
    else
		ft_putstr("Error\nPlease input a valid argument");
}