/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaldona <rmaldona@student42.rio>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:49:53 by rmaldona          #+#    #+#             */
/*   Updated: 2022/12/01 14:44:56 by rmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "so_long.h"

void create_map(t_game *game, char **argv)
{
	int		fd;
	char	*line = NULL;
	char	*bigline = NULL;

	game->lin = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		printf ("error");

	if (ft_strrncmp(argv[1], ".ber", 4))
		m_error("Format map error");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (bigline == 0)
			bigline = ft_strjoin("", line);
		else
			bigline = ft_strjoin(bigline, line);
		game->lin++;
		game->col = ft_strlen(line) - 1;
	}
	game->map = ft_split(bigline, '\n');
	game->mapcopy = ft_split(bigline, '\n');

	size_t	len;
	int	lenmap;
	int	linemap;
	size_t	contp;
	int		contc;
	int		conte;

	contp = 0;
	contc = 0;
	conte = 0;
	lenmap = game->col - 1;
	linemap = game->lin - 2;
	if (game->col == game->lin)
		m_error("map is not rectangular");
	len = ft_strlen(bigline);
	while (lenmap)
	{
		if (game->map[0][lenmap] != '1' && game->map[game->lin - 1][lenmap] != '1')
			m_error("wall invalid");
		else
			lenmap--;
		while (linemap > 0)
		{
			if	(game->map[linemap][game->col - 1] != '1' && game->map[linemap][0] != '1')
				m_error("wall invalid");
			else
				linemap--;
		}
	}
	while (bigline[--len] != 0)
	{
		if (!ft_strchr("PEC01\n", bigline[len]))
			m_error("invalid caracter");
		if (bigline[len] == 'P')
		{
			contp++;
		}
		if (bigline[len] == 'C')
		{
			contc++;
		}
		if (bigline[len] == 'E')
		{
			conte++;
		}
	}
	if (contp != 1 || conte != 1 || contc == 0)
		m_error("missing caracter");
	int px = 0;
	int py = 0;
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
	count_elements(game, contc, px, py);
	compare(game, contc);
	
}

void	count_elements(t_game *game, int contc, int px, int py)
{
	if (game->mapcopy[px][py] == '1')
		return;
	if (game->mapcopy[px][py] == 'E')
			game->exit_count++;
	if (game->mapcopy[px][py] == 'C')
		game->coin_count++;
	game->mapcopy[px][py] = '1';
	count_elements(game, contc, px + 1, py);
	count_elements(game, contc, px - 1, py);
	count_elements(game, contc, px, py + 1);
	count_elements(game, contc, px, py - 1);
}

void	compare(t_game *game, int contc)
{
	if (game->coin_count != contc)
	{
		printf("\n\ncontc = %i\n", contc);
		printf("\n\ncoinc = %i\n", game->coin_count);
		m_error("ROTA NÃO VÁLIDA");
		exit(EXIT_FAILURE);
	}
}

void	m_error(char *msg)
{
	printf("Error:\n%s", msg);
	exit(0);
}


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
	return (0);
}
