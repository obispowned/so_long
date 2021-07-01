/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 20:15:15 by agutierr          #+#    #+#             */
/*   Updated: 2021/07/01 21:21:15 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "../header/so_long.h"

int		key_press(int key, t_mlx *mlx)
{
	mlx->prueba = 0;
	if (key == KEY_UP || key == KEY_W)
		printf("1 UP\n");
	if (key == KEY_DOWN || key == KEY_S)
		printf("1 DOWN\n");
	if (key == KEY_RIGHT)
		printf("1 RIGHT\n");
	if (key == KEY_D)
		printf("1 D\n");
	if (key == KEY_LEFT)
		printf("1 LEFT\n");
	if (key == KEY_A)
		printf("1 A\n");
	if (key == KEY_SHIFT_L)
		printf("1 SL\n");
	if (key == KEY_ESC)
	{
		mlx_destroy_window(mlx->ptr, mlx->win);
		free(mlx->ptr);
		exit(-1);
	}
	return (0);
}

int		key_release(int key, t_mlx *mlx)
{
	mlx->prueba = 0;
	if (key == KEY_UP || key == KEY_W)
		printf("0 UP\n");
	if (key == KEY_DOWN || key == KEY_S)
		printf("0 DOWN\n");
	if (key == KEY_RIGHT)
		printf("0 RIGHT\n");
	if (key == KEY_D)
		printf("0 D\n");
	if (key == KEY_LEFT)
		printf("0 LEFT\n");
	if (key == KEY_A)
		printf("0 A\n");
	if (key == KEY_SHIFT_L)
		printf("0 SL\n");
	return (0);
}

int		exit_game(t_mlx *mlx)
{
	mlx->prueba = 0;
	mlx_destroy_window(mlx->ptr, mlx->win);
	free(mlx->ptr);
	exit(-1);
	return (0);
}
