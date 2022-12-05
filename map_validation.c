/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaldona <rmaldona@student42.rio>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:32:52 by rmaldona          #+#    #+#             */
/*   Updated: 2022/12/01 17:24:05 by rmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	search_p(t_game *game, int px, int py)
{
	px = 0;
	py = 0;

	while (game->map[px][py] != 'P')
	{
		py = 0;
		while(game->map[px][py] != '\0' && game->map[px][py] != '\n')
		{
			if (game->map[px][py] == 'P')
				break;
			py++;
		}
		if (game->map[px][py] == 'P')
				break;
		px++;
	}
	game->px = px;
	game->py = py;
//	map_rectangular(game);
	count_elements(game, px, py);
	compare(game);
}

void	count_elements(t_game *game, int px, int py)
{
	if (game->mapcopy[px][py] == '1')
		return;
	if (game->mapcopy[px][py] == 'E')
			game->exit_count++;
	if (game->mapcopy[px][py] == 'C')
		game->coin_count++;
	game->mapcopy[px][py] = '1';
	count_elements(game, px + 1, py);
	count_elements(game, px - 1, py);
	count_elements(game, px, py + 1);
	count_elements(game, px, py - 1);
}

void	map_rectangular(t_game *game)
{
	int 	lin;
	int 	col;
	int 	i;

	col = game->col;
	printf("%i\n", game->col);
	lin = 0;
	i = 0;
	while (lin != game->lin)
	{
		i = 0;
		while (game->map[lin][i])
		{
			i++;
			printf("\ntest = %i\n", i);
		}
		if (i != col)
			m_error("Map is not rectangular");
		lin++;
		printf("\n%i\n", lin);
	}
}

void	compare(t_game *game)
{
	if (game->coin_count != game->contc)
	{
		m_error("ROTA NÃO VÁLIDA");
		exit(EXIT_FAILURE);
	}
}
