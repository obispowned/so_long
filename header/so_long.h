/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:39:36 by agutierr          #+#    #+#             */
/*   Updated: 2021/06/30 21:11:19 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SO_LONG_H
# define _SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "utils.h"

typedef struct		s_items
{
	int				id;
	int				x;
	int				y;
}					t_item;

typedef struct		s_config
{
	int				flag_e;
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

/*                 process.c                       */
	t_config		load_file(char *file);
	t_config		file_procesator(char *file);

/*                 map.c                           */
	void			only_one_p_e(t_config *config, char c, int i, int j);
	char			**read_map2(int fd, t_config *config);
	int				**parserico(char **map, t_config *config);
	int				**read_map(char *file, t_config *config);
	void			searchmap(t_config *config, char **map);
	int				ft_valmap (char ** mapa, int x, int y, t_config *config);

/*                  check_err.c                    */
	int				check_lines(char *line, char *chars);
	void			check_errors(char *line);
	void			check_argv(char *file);

/*                                                 */
	int				chars_in_str(char *str, char c);


/*                                                 */

void			searchmap(t_config *config, char **map);

#endif
