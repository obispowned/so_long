/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 19:08:00 by agutierr          #+#    #+#             */
/*   Updated: 2021/06/29 17:54:16 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int				chars_in_str(char *str, char c)
{
	int			i;
	int			count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

int				main(int argc, char **argv)
{
	t_config	config;
	//t_mlx		mlx;

	if (argc != 2)
		print_err("Numero de argumentos invalido");
	config = file_procesator(argv[1], argc);
	printf("\nL: %d, R: %d\n", config.max_lines, config.max_rows);
	printf("\nPlayer: %d-%d, Obj: %d Ext: %d-%d\n", config.game_player[0], config.game_player[1],
	config.count_c, config.game_win[0],config.game_win[1]);
	print_matrix(config.mapa, config.max_lines, config.max_rows);
	return (0);
}
