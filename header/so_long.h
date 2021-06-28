/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:39:36 by agutierr          #+#    #+#             */
/*   Updated: 2021/06/28 21:09:57 by agutierr         ###   ########.fr       */
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

typedef struct		s_mapi
{
	int				**worldmap;
}					t_mapi;

typedef struct		s_config
{
	int				max_lines;
	int				max_rows;
	int				height;
	int				width;
	int				**mapa;
	int				game_player[2];
	int				game_win[2];
	int				game_object[2];
}					t_config;

#endif
