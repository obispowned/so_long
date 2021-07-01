/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:39:36 by agutierr          #+#    #+#             */
/*   Updated: 2021/07/01 21:26:49 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SO_LONG_H
# define _SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "../get_next_line/get_next_line.h"
# include "utils.h"
# include "detect_so.h"
# include "hook.h"

typedef struct s_img
{
	void			*id;
	unsigned int	*data;
	int				bpp;
	int				sl;
	int				ed;
}					t_img;
typedef struct s_tile
{
	char			type;
	unsigned int	color;
	int				sx;
	int				sy;
	int				x;
	int				y;
	t_img			img;
}					t_tile;

typedef struct s_map
{
	int				won;
	int				collect_count;
	char			**map;
	t_tile			player;
	t_tile			**tiles;
	t_img			empty_img;
	t_img			wall_img;
	t_img			player_img;
	t_img			exit_img;
	t_img			collect_img;
	long			sx;
	long			sy;
}					t_map;

typedef	struct		s_mlx
{
	int				prueba;
	void			*ptr;
	void			*win;
	t_map			map_dat;
	int				win_height;
	int				win_width;
	int				**finalmap;
}					t_mlx;

typedef struct		s_items
{
	int				id;
	int				x;
	int				y;
}					t_item;

typedef struct		s_config
{
	int				flag_e;
	int				flag_c;
	int				count_c;
	int				max_lines;
	int				max_rows;
	int				height;
	int				width;
	int				**mapa;
	int				game_player[2];
	int				game_win[2];
	int				game_object[2];
	t_item			**item;
}					t_config;

# define COLOR_EMPTY		0x00636D83
# define COLOR_WALL			0x00101010
# define COLOR_COLLECT		0x00D19A66
# define COLOR_PLAYER		0x0000F000
# define COLOR_EXIT			0x00F00000
# define CARGANDO			0x0090ee90

/*                 process.c                       */
	t_config		load_file(char *file);
	t_config		file_procesator(char *file);

/*                 map.c                           */
	void			only_one_p_e(t_config *config, char c, int i, int j);
	char			**read_map2(int fd, t_config *config);
	int				**parserico(char **map, t_config *config);
	int				**read_map(char *file, t_config *config);
	void			searchmap(t_config *config, char **map);
	void			ft_valmap (char ** mapa, int x, int y, t_config *config);

/*                  check_err.c                    */
	int				check_lines(char *line, char *chars);
	void			check_errors(char *line);
	void			check_argv(char *file);

/*                                                 */
	int				chars_in_str(char *str, char c);


/*                                                 */

void				searchmap(t_config *config, char **map);

/**/
int					graphic_part(t_config *config);
int					key_press(int key, t_mlx *mlx);
int					key_release(int key, t_mlx *mlx);
int					exit_game(t_mlx *mlx);
void				reset_mlx(t_mlx *mlx, t_config *config);

#endif
