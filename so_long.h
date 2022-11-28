/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaldona <rmaldona@student42.rio>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 12:40:35 by rmaldona          #+#    #+#             */
/*   Updated: 2022/11/28 17:48:50 by rmaldona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

#include "./mlx/mlx.h"
#include "./libft/libft.h"
#include "./libft/get_next_line.h"
#include <fcntl.h>

# define FLOOR	"./img/floor.xpm"
# define DOWN	"./img/down.xpm"
# define UP		"./img/up.xpm"
# define RIGHT	"./img/right.xpm"

typedef struct s_game
{
	int		lin;
	int		exit_count;
	int		coin_count;
	int		read_lin;
	int		col;
//	int		countc;
	char	**map;
	char	**mapcopy;
	void	*img;
}			t_game;

typedef struct s_program
{
    void    *img;
    void    *albuquerque;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
    int     img_width;
    int     img_height;
    void    *mlx_ptr;
    void    *relative_path;
    void    *relative_path1;
    void    *player_down;
    void    *mlx_win;
}           t_program;

void	create_map(t_game *game, char **argv);
void	m_error(char *msg);
void	draw_map(t_game *game, char *bigline);
void	check_caracter(char *bigline, size_t len);
void	teste(int argc, char **argv);
int		keyhook(int keycode, t_program *img);
void	count_elements(t_game *game, int contc, int px, int py);
void	compare(t_game *game, int contc);

#endif
