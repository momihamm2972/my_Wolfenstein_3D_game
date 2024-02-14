/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: momihamm <momihamm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 18:26:57 by yonadry           #+#    #+#             */
/*   Updated: 2024/02/14 00:48:21 by momihamm         ###   ########.fr       */
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

void    mlxArt(t_cub3d *usef, t_ray *strahl, t_play *parzival)
{
    strahl->start = mlx_init ();
    init_player (parzival, usef);
    the_longest_line (usef, strahl);
    getCurntPosi (parzival, usef);
    // initData (strahl);
    // strahl->myImage = malloc (sizeof (t_img));
    // printf ("mra\n");
    strahl->window = mlx_new_window (strahl->start, strahl->the_long_line * 32, strahl->the_rows * 32, "MUSLIM");
    // printf ("alger\n");
    strahl->myImage->mlxImage = mlx_new_image (strahl->start, strahl->the_long_line * 32, strahl->the_rows * 32);
    // printf ("emarat\n");
    strahl->myImage->dataAddr = mlx_get_data_addr (strahl->myImage->mlxImage, &strahl->myImage->intPerPixl, &strahl->myImage->lenOfLine, &strahl->myImage->end);
    ft_draw (strahl, parzival);
    // printf("p1 >>>>>>>>>> [%p]\n", strahl->myImage);
	// printf("p2 >>>>>>>>>> [%p]\n", strahl->myImage->mlxImage);
    // printf ("every day11\n");
	// exit(1);
    mlx_hook (strahl->window, 2, 0L, ft_move, strahl);
    mlx_hook (strahl->window, 3, 0L, ftMoveR, strahl);
    mlx_loop_hook(strahl->start, ft_again  , strahl);
    // printf ("every dayethwthwrthj1\n");
	mlx_hook (strahl->window, 17, 0, close_the_win, NULL);
    // printf ("every dayyyyyyyyyyyyyyyyyy\n");
    mlx_loop (strahl->start);
}

int main(int ac, char **av)
{
    t_cub3d	*cub3d;
    t_ray	*strahl;
    // t_play  *parzival;

    if (ac == 2)
    {
        cub3d = malloc(sizeof(t_cub3d));
		strahl = malloc (sizeof(t_ray));
        strahl->playstation = malloc (sizeof(t_play));
        strahl->myImage = malloc (sizeof (t_img));
        // ###########################;
        cub3d->file_name = check_extension(av[1]);
        read_map_elements(cub3d);
        strahl->gameMap = cub3d->map;
        int i =0;
        // int j =0;
        while (strahl->gameMap[i])
        {
            printf ("**%s**\n", strahl->gameMap[i]);
            i++;
        }
        mlxArt (cub3d, strahl, strahl->playstation);
		// init_strahl (strahl, cub3d, parzival);
        // getCurntPosi(parzival, cub3d);
        // printf ("Kmix>>%d\ty>>%d\n",parzival->x_play , parzival->y_play);
        // drawing (strahl, cub3d, parzival);
        // derictions (parzival, strahl, cub3d);
        // printf ("cristal\n");
        // if (whileMoving(parzival) == -1)
        //     printf ("update\n");
        // else
        //     printf ("smoock\n");
        // mlx_loop (strahl->start);
        free_all(cub3d);
    }
    else
		ft_putstr("Error\nPlease input a valid argument"); 
}
