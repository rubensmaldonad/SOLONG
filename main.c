/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaldona <rmaldona@student42.rio>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:37:22 by rmaldona          #+#    #+#             */
/*   Updated: 2022/12/01 16:51:12 by rmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int i = 0;
	t_game game;
	if (argc == 2)
	{
		create_map(&game, argv);

		while (game.map[i] && game.mapcopy[i])
		{
			printf("\n\n%s\n%s\n", game.map[i], game.mapcopy[i]);
			i++;
		}
	}
	else
		printf("faltou argumentos");
	teste(&game);
	return (0);
}
