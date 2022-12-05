/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaldona <rmaldona@student42.rio>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:23:16 by rmaldona          #+#    #+#             */
/*   Updated: 2022/12/01 17:27:59 by rmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "./mlx/mlx.h"
#include "so_long.h"

int key_hook(int keycode, t_program *img)
{
	static int	updown = 0;
	static int 	lr = 0;

	if (keycode == 2)
	{
		lr = lr + 64;
		mlx_put_image_to_window(img->mlx_ptr, img->mlx_win, img->img, lr - 64, updown);
		mlx_put_image_to_window(img->mlx_ptr, img->mlx_win, img->albuquerque, lr, updown);
	}
	else if (keycode == 0)
	{
		lr = lr - 64;
		mlx_put_image_to_window(img->mlx_ptr, img->mlx_win, img->img, lr + 64, updown);
		mlx_put_image_to_window(img->mlx_ptr, img->mlx_win, img->albuquerque, lr, updown);
	}
	else if (keycode == 1)
	{
		updown = updown + 64;
		mlx_put_image_to_window(img->mlx_ptr, img->mlx_win, img->img, lr, updown - 64);
		mlx_put_image_to_window(img->mlx_ptr, img->mlx_win, img->albuquerque, lr, updown);
	}
	else if (keycode == 13)
	{
		updown = updown - 64;
		mlx_put_image_to_window(img->mlx_ptr, img->mlx_win, img->img, lr, updown + 64);
		mlx_put_image_to_window(img->mlx_ptr, img->mlx_win, img->albuquerque, lr, updown);
	}
	return 42;
}

#include <stdio.h>

void teste(t_game *game)
{
	char		*relative_path = "./img/floor.xpm";
	t_program	img;

	img.relative_path1 = "./img/right.xpm";
	img.player_down = "./img/down.xpm";
	img.mlx_ptr = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx_ptr, WINDOW_WIDTH * game->col, WINDOW_HEIGHT * game->lin, "MINHA JANELINHA");
	img.img = mlx_xpm_file_to_image(img.mlx_ptr, relative_path, &img.img_width, &img.img_height);
	img.albuquerque = mlx_xpm_file_to_image(img.mlx_ptr, img.relative_path1, &img.img_width, &img.img_height);

	printf("PX = %i\n PY = %i\n", game->px, game->py);
	mlx_put_image_to_window(img.mlx_ptr, img.mlx_win, img.albuquerque, game->py * 64, game->px * 64);
	mlx_key_hook(img.mlx_win, key_hook, &img);
	mlx_loop(img.mlx_ptr);
}

