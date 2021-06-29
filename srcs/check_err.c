/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:42:33 by agutierr          #+#    #+#             */
/*   Updated: 2021/06/29 19:17:58 by agutierr         ###   ########.fr       */
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

void			check_argv(char *file)
{
	printf("%s", file);
	if (file[ft_strlen(file) - 1] != 'r' && file[ft_strlen(file) - 2] != 'e' &&
	file[ft_strlen(file) - 3] != 'b' && file[ft_strlen(file) - 4] != '.')
		print_err("El archivo que ingresa debe ser tener la extension .ber");
}
