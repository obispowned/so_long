/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:08:00 by agutierr          #+#    #+#             */
/*   Updated: 2021/06/28 22:33:57 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int				check_lines(char *line, char *chars)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (line[i] != '\0')
	{
		while (chars[j] != '\0')
		{
			if (line[i] == chars[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void			check_errors(char *line)
{
	int i;

	i = 0;
	if (check_lines(line, "01CEP") == 0 && line[0] != '\0')
		print_err("Elimine los caracteres sobrantes.");
}

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
		check_errors(line);
		config.max_lines++;
		if (config.max_rows < ft_strlen(line))
			config.max_rows = ft_strlen(line);
		kill(line);
	}
	kill(line);
	close(fd);
	return (config);
}

char			**read_map2(int fd, t_config *config, int count_sprites)
{
	char		*line;
	char		**map;
	int			i;

	i = 0;
	if (!(map = (char **)ft_calloc(sizeof(char *) * config->max_lines + 1, 0)))
		print_err("Malloc ha fallado en read_map2");
	while (((get_next_line(fd, &line)) > 0))
	{
		map[i] = ft_strdup(line);
		kill(line);
		i++;
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
	//check_map(config, map);
	//valid_map(map);
	mapa = parserico(map, config);
	close(fd);
	double_kill(map);
	return (mapa);
}

void			check_argv(char *file)
{
	printf("%s", file);
	if (file[ft_strlen(file) - 1] != 'r' && file[ft_strlen(file) - 2] != 'e' &&
	file[ft_strlen(file) - 3] != 'b' && file[ft_strlen(file) - 4] != '.')
		print_err("El archivo que ingresa debe ser tener la extension .ber");
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


int				main(int argc, char **argv)
{
	t_config	config;
	//t_mlx		mlx;

	if (argc != 2)
		print_err("Numero de argumentos invalido");
	config = file_procesator(argv[1], argc);
	return (0);
}
