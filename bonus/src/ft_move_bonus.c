/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:49:22 by yhajbi            #+#    #+#             */
/*   Updated: 2025/02/22 09:49:23 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static int	ft_count_collectibles(t_vars *vars)
{
	int		x;
	int		y;
	int		count;
	char	**map;

	y = 0;
	count = 0;
	map = vars->p_data->matrix;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	ft_move_up(t_vars *vars)
{
	char	pos;
	char	**map;

	map = vars->p_data->matrix;
	pos = map[vars->p_data->p_y - 1][vars->p_data->p_x];
	if (pos == 'E' || pos == 'C' || pos == '0' || pos == 'H')
	{
		if (pos == 'E' || pos == 'H')
		{
			if (pos == 'H')
				ft_printf("You have crossed the enemy's path\n");
			if (ft_count_collectibles(vars) == 0 || pos == 'H')
				ft_close_game(vars);
		}
		else
		{
			map[vars->p_data->p_y][vars->p_data->p_x] = '0';
			vars->p_data->p_y -= 1;
			map[vars->p_data->p_y][vars->p_data->p_x] = 'P';
			ft_draw(vars, 1);
		}
	}
	return (0);
}

int	ft_move_down(t_vars *vars)
{
	char	pos;
	char	**map;

	map = vars->p_data->matrix;
	pos = map[vars->p_data->p_y + 1][vars->p_data->p_x];
	if (pos == 'E' || pos == 'C' || pos == '0' || pos == 'H')
	{
		if (pos == 'E' || pos == 'H')
		{
			if (pos == 'H')
				ft_printf("You have crossed the enemy's path\n");
			if (ft_count_collectibles(vars) == 0 || pos == 'H')
				ft_close_game(vars);
		}
		else
		{
			map[vars->p_data->p_y][vars->p_data->p_x] = '0';
			vars->p_data->p_y += 1;
			map[vars->p_data->p_y][vars->p_data->p_x] = 'P';
			ft_draw(vars, 2);
		}
	}
	return (0);
}

int	ft_move_right(t_vars *vars)
{
	char	pos;
	char	**map;

	map = vars->p_data->matrix;
	pos = map[vars->p_data->p_y][vars->p_data->p_x + 1];
	if (pos == 'E' || pos == 'C' || pos == '0' || pos == 'H')
	{
		if (pos == 'E' || pos == 'H')
		{
			if (pos == 'H')
				ft_printf("You have crossed the enemy's path\n");
			if (ft_count_collectibles(vars) == 0 || pos == 'H')
				ft_close_game(vars);
		}
		else
		{
			map[vars->p_data->p_y][vars->p_data->p_x] = '0';
			vars->p_data->p_x += 1;
			map[vars->p_data->p_y][vars->p_data->p_x] = 'P';
			ft_draw(vars, 3);
		}
	}
	return (0);
}

int	ft_move_left(t_vars *vars)
{
	char	pos;
	char	**map;

	map = vars->p_data->matrix;
	pos = map[vars->p_data->p_y][vars->p_data->p_x - 1];
	if (pos == 'E' || pos == 'C' || pos == '0' || pos == 'H')
	{
		if (pos == 'E' || pos == 'H')
		{
			if (pos == 'H')
				ft_printf("You have crossed the enemy's path\n");
			if (ft_count_collectibles(vars) == 0 || pos == 'H')
				ft_close_game(vars);
		}
		else
		{
			map[vars->p_data->p_y][vars->p_data->p_x] = '0';
			vars->p_data->p_x -= 1;
			map[vars->p_data->p_y][vars->p_data->p_x] = 'P';
			ft_draw(vars, 4);
		}
	}
	return (0);
}
