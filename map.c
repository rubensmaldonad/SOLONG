/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaldona <rmaldona@student42.rio>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:17:56 by rmaldona          #+#    #+#             */
/*   Updated: 2022/10/17 15:06:21 by rmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



void	render map(struct, char *patch)
{
	int		fd;
	char	*gnl;
	int		x;
	int		y;
	char	**map;

	x = 0;
	fd = open(patch, O_RDONLY);
	gnl = get_next_line(fd);
	y = strlen(gnl - 1);
	map = malloc((y + 1) * sizeof (char *));
	map[x] = gnl;

	while (x)
	{
		gnl= get_next_line(fd);
		map[x] = gnl;
	}
}
