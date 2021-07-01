/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 21:14:45 by agutierr          #+#    #+#             */
/*   Updated: 2021/07/01 21:29:00 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void			reset_mlx(t_mlx *mlx, t_config *config)
{
	mlx->win_height = config->height;
	mlx->win_width = config->width;
	mlx->finalmap = config->mapa;
}

int			graphic_part(t_config *config)
{
	t_mlx		mlx;

	reset_mlx(&mlx, config);
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, mlx.win_width, mlx.win_height, "so_long");
	mlx_string_put(mlx.ptr, mlx.win, (mlx.win_width / 2) - 50, mlx.win_height / 2,
		mlx_get_color_value(mlx.ptr, CARGANDO), "Cargando...");
	mlx_do_sync(mlx.ptr);
	//init_graphics(mlx, *config);
	mlx_hook(mlx.win, 2, 1L << 0, &key_press, &mlx);
	mlx_hook(mlx.win, 3, 1L << 1, &key_release, &mlx);
	mlx_hook(mlx.win, 17, 1L << 17, exit_game, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}
/*
void		init_graphics(t_mlx mlx, t_config config)
{
	int	tsx;
	int	tsy;
 construyendo....
	tsx = mlx.win_width / config.max_rows;
	tsy = mlx.win_height / config.max_lines;
	mlx.map_dat.tiles = caloc(sizeof(t_tile *) * config.max_lines);
	mlx.map.won = 0;
	mlx.map.empty_img = init_img(mlx, COLOR_EMPTY, tsx, tsy);
	mlx.map.wall_img = init_img(mlx, COLOR_WALL, tsx, tsy);
	mlx.map.collect_img = init_img(mlx, COLOR_COLLECT, tsx, tsy);
	mlx.map.player_img = init_img(mlx, COLOR_PLAYER, tsx, tsy);
	mlx.map.exit_img = init_img(mlx, COLOR_EXIT, tsx, tsy);
	mlx.map.player.type = CHAR_PLAYER;
	mlx.map.player.sx = tsx;
	mlx.map.player.sy = tsy;
	mlx.map.player.color = COLOR_PLAYER;
	mlx.map.player.img = mlx.map.player_img;
	mlx.map.collect_count = 0;
	mlx.map = init_tile_each(map, tsx, tsy);
	draw_window(mlx, map);
	return (map);
}
*/



/*
void	draw_window(t_mlx mlx, t_config *config)
{
	int		i;
	int		j;

	i = 0;
	while (i < map.sy)
	{
		j = 0;
		while (j < map.sx)
		{
			if (map.player.x == j && map.player.y == i)
				mlx_put_image_to_window(mlx.id, mlx.win.id,
					map.player.img.id, map.player.sx * j, map.player.sy * i);
			else
				mlx_put_image_to_window(mlx.id, mlx.win.id,
					map.tiles[i][j].img.id, map.tiles[i][j].sx * j,
					map.tiles[i][j].sy * i);
			j++;
		}
		i++;
	}
	if (map.won)
		draw_won(mlx, map);
}*/
