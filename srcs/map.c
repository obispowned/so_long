/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:44:13 by agutierr          #+#    #+#             */
/*   Updated: 2021/06/29 20:00:59 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

char			**read_map2(int fd, t_config *config, int count_sprites)
{
	char		*line;
	char		**map;
	int			i;

	config->count_c = 0;
	i = 0;
	if (!(map = (char **)ft_calloc(sizeof(char *) * config->max_lines + 1, 0)))
		print_err("Malloc ha fallado en read_map2");
	while (((get_next_line(fd, &line)) > 0))
	{
		if (line)
		{
			if (ft_strlen(line) != config->max_rows)
				print_err("El mapa debe ser rectangular\n");
			config->count_c += chars_in_str(line, 'C');
			map[i] = ft_strdup(line);
			i++;
		}
		kill(line);
	}
	map[i] = NULL;
	return (map);
}

int			**parserico(char **map, t_config *config)
{
	int		**mapa;
	int		i;
	int		j;

	i = 0;
	mapa = (int **)malloc(sizeof(int *)	* config->max_lines);
	while (config->max_lines > i)
	{
		mapa[i] = (int *)malloc(sizeof(int)	* config->max_rows);
		j = 0;
		while (j < config->max_rows)
		{
			if (map[i][j] == 'P')
				mapa[i][j] = 0;
			else if (map[i][j] == 'C')
				mapa[i][j] = 0;
			else if (map[i][j] == 'E')
				mapa[i][j] = 0;
			else
				mapa[i][j] = (int)(map[i][j] - '0');
			j++;
		}
		i++;
	}
	return (mapa);
}

int			**read_map(char *file, t_config *config)
{
	int			fd;
	char		**map;
	int			**mapa;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_err("Fallo al intentar abrir el archivo .cub");
	map = read_map2(fd, config, 0);
	searchmap(config, map); // busco y guardo CEP
	mapa = parserico(map, config); //paso mapa a int
	config->flag_e = 0;
	if ((ft_valmap(map, config->game_player[0], config->game_player[1], config)) != 1) //validamos mapa cerrado
		print_err("El jugador debe tener acceso a la salida\n");
	close(fd);
	double_kill(map);
	return (mapa);
}

void			searchmap(t_config *config, char **map)
{
	int			i;
	int			j;

	i = 0;
	while (i < config->max_lines)
	{
		j = 0;
		while (j < config->max_rows)
		{
			if (map[i][j] == 'P')
			{
				config->game_player[0] = i;
				config->game_player[1] = j;
			}
			if (map[i][j] == 'C')
			{
				config->game_object[0] = i;
				config->game_object[1] = j;
			}
			if (map[i][j] == 'E')
			{
				config->game_win[0] = i;
				config->game_win[1] = j;
			}
			j++;
		}
		i++;
	}
}

int		ft_valmap(char **mapa, int x, int y, t_config *config)
{ //X e Y son las coordenadas del jugador.
	if (mapa[x][y] == 'E')
		config->flag_e ++;
	if (x == 0 || y == 0 || y == (ft_strlen(mapa[x]) - 1) ||
		x == config->max_lines - 1 || y > ft_strlen(mapa[x + 1]) ||
			y > ft_strlen(mapa[x - 1]))
	{
		perror("Error\nMapa abierto");
		exit(7);
	}
	mapa[x][y] = '3';
	if (mapa[x][y + 1] == '0' || mapa[x][y + 1] == 'C' || mapa[x][y + 1] == 'E' || mapa[x][y + 1] == ' ')
		ft_valmap (mapa, x, y + 1 , config);
	if (mapa[x][y - 1] == '0' || mapa[x][y - 1] == 'C' || mapa[x][y - 1] == 'E' || mapa[x][y - 1] == ' ')
		ft_valmap (mapa, x, y - 1 , config);
	if (mapa[x + 1][y] == '0' || mapa[x + 1 ][y] == 'C' || mapa[x + 1][y] == 'E'|| mapa[x + 1][y] == ' ')
		ft_valmap (mapa, x + 1 , y, config);
	if (mapa[x - 1][y] == '0' || mapa[x - 1 ][y] == 'C' || mapa[x - 1][y] == 'E'|| mapa[x - 1][y] == ' ')
		ft_valmap (mapa, x - 1 , y, config);
	return (config->flag_e);
}
