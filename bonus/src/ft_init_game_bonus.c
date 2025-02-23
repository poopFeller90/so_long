/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:29:16 by yhajbi            #+#    #+#             */
/*   Updated: 2025/01/28 17:53:58 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static int	ft_exit(t_vars *vars)
{
	ft_close_game(vars);
	return (0);
}

void	ft_find_cobson(t_vars *vars)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = vars->p_data->matrix;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'H')
			{
				vars->sprites->c_x = x;
				vars->sprites->c_y = y;
				vars->sprites->c_d = 1;
				vars->c_init = 1;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	ft_init_game(t_parse_data *p_data)
{
	t_vars	vars;
	int		size_x;
	int		size_y;

	vars.move = 0;
	vars.c_init = 0;
	if (p_data->is_valid == 0)
		return ;
	else
		vars.mlx = mlx_init();
	size_x = p_data->map_width * 64;
	size_y = p_data->map_height * 64;
	vars.p_data = p_data;
	vars.win = mlx_new_window(vars.mlx,
			size_x, size_y, "Escape From Cobson 2D");
	if (!vars.win)
		return ;
	ft_draw(&vars, 0);
	mlx_hook(vars.win, KeyPress, KeyPressMask, ft_control_hook, &vars);
	mlx_hook(vars.win, DestroyNotify, NoEventMask, ft_exit, &vars);
	mlx_loop_hook(vars.mlx, ft_animation_hook, &vars);
	mlx_loop(vars.mlx);
}
