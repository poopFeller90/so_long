/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 19:41:29 by yhajbi            #+#    #+#             */
/*   Updated: 2025/02/23 19:41:30 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static int	ft_animate_soylent(t_vars *vars)
{
	static int	i;
	static int	delay;
	static int	direction;

	if (delay++ < 8500)
		return (1);
	delay = 0;
	vars->sprites->i_frame = i % 3;
	ft_draw(vars, 0);
	if (i == 2)
		direction = -1;
	if (i == 0)
		direction = 1;
	i += direction;
	vars->move = vars->move;
	return (1);
}

static void	ft_move_horizontal(t_vars *vars, char **map)
{
	int	n_x;
	int	c_y;

	c_y = vars->sprites->c_y;
	n_x = vars->sprites->c_x + vars->sprites->c_d;
	if (map[c_y][n_x] == 'P')
	{
		ft_printf("You have crossed the enemy's path\n");
		ft_close_game(vars);
	}
	else if (map[c_y][n_x] != '1' && map[c_y][n_x] != 'E')
	{
		map[c_y][vars->sprites->c_x] = '0';
		map[c_y][n_x] = 'H';
		vars->sprites->c_x = n_x;
	}
	else
		vars->sprites->c_d *= -1;
}

static void	ft_move_vertical(t_vars *vars, char **map)
{
	int	n_y;
	int	c_x;

	c_x = vars->sprites->c_x;
	n_y = vars->sprites->c_y + vars->sprites->c_d;
	if (map[n_y][c_x] == 'P')
	{
		ft_printf("You have crossed the enemy's path\n");
		ft_close_game(vars);
	}
	else if (map[n_y][c_x] != '1' && map[n_y][c_x] != 'E')
	{
		map[vars->sprites->c_y][c_x] = '0';
		map[n_y][c_x] = 'H';
		vars->sprites->c_y = n_y;
	}
	else
		vars->sprites->c_d *= -1;
}

static int	ft_move_cobson(t_vars *vars)
{
	static int	i;
	static int	delay;
	char		**map;

	map = vars->p_data->matrix;
	if (delay++ < 4000)
		return (1);
	delay = 0;
	if (i % 2 == 0)
		ft_move_horizontal(vars, map);
	else if (i % 2 != 0)
		ft_move_vertical(vars, map);
	//i++;
	i += rand();
	ft_draw(vars, 0);
	return (1);
}

int	ft_animation_hook(t_vars *vars)
{
	ft_animate_soylent(vars);
	ft_move_cobson(vars);
	return (1);
}
