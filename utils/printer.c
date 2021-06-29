/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:54:07 by agutierr          #+#    #+#             */
/*   Updated: 2021/06/29 19:42:57 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void			print_matrix(int **str, int lines, int rows)
{
	int			i;
	int			j;

	i = 0;
	while (i < lines)
	{
		j = 0;
		while (j < rows)
		{
			putchar(str[i][j] + '0');
			j++;
		}
		putchar('\n');
		i++;
	}
}

void			print_err(char *str)
{
	ft_putstr("ERROR\n");
	ft_putstr(str);
	exit(0);
}

void			ft_putstr(char *str)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

void			ft_putchar(char c)
{
	write (1, &c, 1);
}


