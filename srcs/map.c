/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:44:13 by agutierr          #+#    #+#             */
/*   Updated: 2021/07/01 20:02:53 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void			only_map_chars(char *line)
{
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0'
		&& line[i] != 'C' && line[i] != 'P'
		&& line[i] != 'E')
			print_err("Solo permitidos caracteres: 0-1-P-C-E.\n");
		i++;
	}
}

char			**read_map2(int fd, t_config *config)
{
	char		*line;
	char		**map;
	int			i;

	config->count_c = 0;
	i = 0;
	if (!(map = (char **)ft_calloc(sizeof(char *) , config->max_lines + 1)))
		print_err("Malloc ha fallado en read_map2");
	while (((get_next_line(fd, &line)) > 0))
	{
		only_map_chars(line);
		if (ft_strlen(line) != config->max_rows)
			print_err("El mapa debe ser rectangular y saltos de linea\n");
		config->count_c += chars_in_str(line, 'C');
		map[i] = ft_strdup(line);
		i++;
		free(line);
	}
	free (line);
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

void		reset_param(t_config *config)
{
	config->flag_e = 0;
	config->flag_c = 0;
	config->game_player[0] = -1;
	config->game_player[1] = -1;
	config->game_win[0] = -1;
	config->game_win[1] = -1;
	config->height = 400;
	config->width = 600;
}

int			**read_map(char *file, t_config *config)
{
	int			fd;
	char		**map;
	int			**mapa;

	reset_param(config);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_err("Fallo al intentar abrir el archivo .cub");
	map = read_map2(fd, config); //FALLO AQUI
	searchmap(config, map); // busco y guardo CEP
	mapa = parserico(map, config); //paso mapa a int
	ft_valmap(map, config->game_player[0], config->game_player[1], config); //validamos mapa cerrado
	if (config->flag_e != 1 || config->flag_c < 1)
		print_err("El jugador debe tener acceso a una sola salida y al menos un consumible\n");
	close(fd);
	double_kill(map);
	return (mapa);
}
void			only_one_p_e(t_config *config, char c, int i, int j)
{ //Comprobar que solo hay 1 jugador o  1 exit
	if (c == 'P')
	{
		if (config->game_player[0] == -1 || config->game_player[1] == -1)
		{
			config->game_player[0] = i;
			config->game_player[1] = j;
		}
		else
			print_err("Hay varias posiciones para un solo jugador.\n");
	}
	if (c == 'E')
	{
		if (config->game_win[0] == -1 || config->game_win[1] == -1)
		{
			config->game_win[0] = i;
			config->game_win[1] = j;
		}
		else
			print_err("Hay varias posiciones para una sola salida.\n");
	}
}

void			save_items(t_config *config, int i, int j, int id)
{
	config->item[id] = malloc(sizeof(t_item));
	config->item[id]->id = id;
	config->item[id]->x = i;
	config->item[id]->y = j;
}

void			searchmap(t_config *config, char **map)
{
	int			i;
	int			j;
	int			id_item;

	id_item = 0;
	i = 0;
	config->item = malloc(sizeof(t_item *) * config->count_c);
	while (i < config->max_lines)
	{
		j = 0;
		while (j < config->max_rows)
		{
			if (map[i][j] == 'P' || map[i][j] == 'E')
				only_one_p_e(config, map[i][j], i, j); //Comprobar que solo hay 1 jugador o  1 exit
			if (map[i][j] == 'C')
			{
				save_items(config, i, j, id_item);
				id_item++;
			}
			j++;
		}
		i++;
	}
	if (config->game_player[0] == -1 || config->game_player[1] == -1)
		print_err("Para jugar es necesario una posicion para Player.\n");
	if (config->game_win[0] == -1 || config->game_win[1] == -1)
		print_err("Para jugar es necesario una posicion para Exit.\n");
}

void		ft_valmap(char **mapa, int x, int y, t_config *config)
{ //X e Y son las coordenadas del jugador.
	if (mapa[x][y] == 'E')
		config->flag_e ++;
	if (mapa[x][y] == 'C')
		config->flag_c ++;
	if (x == 0 || y == 0 || y == (ft_strlen(mapa[x]) - 1) ||
		x == config->max_lines - 1 || y > ft_strlen(mapa[x + 1]) ||
			y > ft_strlen(mapa[x - 1]))
		print_err("Mapa abierto");
	mapa[x][y] = '3';
	if (mapa[x][y + 1] == '0' || mapa[x][y + 1] == 'C' || mapa[x][y + 1] == 'E'|| mapa[x][y + 1] == ' ')
		ft_valmap (mapa, x, y + 1 , config);
	if (mapa[x][y - 1] == '0' || mapa[x][y - 1] == 'C' || mapa[x][y - 1] == 'E' || mapa[x][y - 1] == ' ')
		ft_valmap (mapa, x, y - 1 , config);
	if (mapa[x + 1][y] == '0' || mapa[x + 1 ][y] == 'C' || mapa[x + 1][y] == 'E'|| mapa[x + 1][y] == ' ')
		ft_valmap (mapa, x + 1 , y, config);
	if (mapa[x - 1][y] == '0' || mapa[x - 1 ][y] == 'C' || mapa[x - 1][y] == 'E'|| mapa[x - 1][y] == ' ')
		ft_valmap (mapa, x - 1 , y, config);
}
