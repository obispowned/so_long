/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:41:35 by agutierr          #+#    #+#             */
/*   Updated: 2021/06/29 19:34:48 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

t_config		load_file(char *file)
{
	t_config	config;
	int			fd;
	int			ret;
	char		*line;

	config.max_lines = 0;
	config.max_rows = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_err("Fallo al intentar abrir el archivooo.");
	while (((ret = get_next_line(fd, &line)) > 0))
	{
		if (line)
		{
			check_errors(line);
			config.max_lines++;
			if (config.max_rows < ft_strlen(line))
				config.max_rows = ft_strlen(line);
		}
		kill(line);
	}
	//kill(line);
	close(fd);
	return (config);
}

t_config		file_procesator(char *file, int argc)
{
	t_config	config;

	check_argv(file); // .ber
	config = load_file(file); //open, max lines, max rows y check que solo haya 01CEP
	config.mapa = read_map(file, &config); // leer y guardar mapa en int *

	/*if (config.player_begin[0] == 0 && config.player_begin[1] == 0)
		print_err("Este mapa no puede ser usado sin un jugador");*/
	return (config);
}
