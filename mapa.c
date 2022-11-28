/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaldona <rmaldona@student42.rio>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:23:16 by rmaldona          #+#    #+#             */
/*   Updated: 2022/11/23 18:02:16 by rmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "./mlx/mlx.h"
#include "so_long.h"

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 1024

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
		//img->img = mlx_xpm_file_to_image(img->mlx_ptr, img->player_down, &img->img_width, &img->img_height);
		updown = updown + 64;
		//mlx_destroy_image(img->mlx_ptr, img->img);
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

void teste(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char		*relative_path = "./img/floor.xpm";
	int			i = 0;
	int			j = 0;
	t_program	img;

	img.relative_path1 = "./img/right.xpm";
	img.player_down = "./img/down.xpm";
	img.mlx_ptr = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "MINHA JANELINHA");
	img.img = mlx_xpm_file_to_image(img.mlx_ptr, relative_path, &img.img_width, &img.img_height);
	while (64 * i <= 1280)
	{
		printf("i = %i\n", i * 64);
		mlx_put_image_to_window(img.mlx_ptr, img.mlx_win, img.img, 64 * i, j * 64);
		i++;
		if (64 * i > WINDOW_WIDTH && j * 64 <= WINDOW_HEIGHT)
		{
			printf("j = %i \n", j * 64);
			i = 0;
			j++;
		}
	}
	img.albuquerque = mlx_xpm_file_to_image(img.mlx_ptr, img.relative_path1, &img.img_width, &img.img_height);

	mlx_put_image_to_window(img.mlx_ptr, img.mlx_win, img.albuquerque, 0, 0);
	mlx_key_hook(img.mlx_win, key_hook, &img);
	mlx_loop(img.mlx_ptr);
}

