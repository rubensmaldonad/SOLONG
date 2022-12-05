/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaldona <rmaldona@student42.rio>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 20:49:53 by rmaldona          #+#    #+#             */
/*   Updated: 2022/12/01 14:47:31 by rmaldona         ###   ########.fr       */
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
	draw_map(game, bigline);
}

void	draw_map(t_game *game, char *bigline)
{
	size_t	len;
	int		lenmap;
	size_t	linemap;

	lenmap = 0;
	linemap = game->lin - 2;
	if (game->col == game->lin)
		m_error("map is not rectangular");
	len = ft_strlen(bigline);
	while (lenmap != game->col)
	{
		if (game->map[0][lenmap] != '1' && game->map[game->lin - 1][lenmap] != '1')
			m_error("wall invalid");
		else
			lenmap++;
		while (linemap > 0)
		{
			if	(game->map[linemap][game->col - 1] != '1' && game->map[linemap][0] != '1')
				m_error("wall invalid");
			else
				linemap--;
		}
	}
	check_caracter(game, bigline, len);
	map_rectangular(game);
}

void	check_caracter(t_game *game, char *bigline, size_t len)
{
	size_t	contp;
	int		conte;
	int		px;
	int		py;

	px = 0;
	py = 0;
	contp = 0;
	game->contc = 0;
	conte = 0;
	while (bigline[--len] != 0)
	{
		if (!ft_strchr("PEC01\n", bigline[len]))
			m_error("invalid caracter");
		if (bigline[len] == 'P')
			contp++;
		if (bigline[len] == 'C')
			game->contc++;
		if (bigline[len] == 'E')
			conte++;
	}
	if (contp != 1 || conte != 1 || game->contc == 0)
		m_error("missing caracter");
	search_p(game, px, py);
}

void	m_error(char *msg)
{
	printf("Error:\n%s", msg);
	exit(0);
}
