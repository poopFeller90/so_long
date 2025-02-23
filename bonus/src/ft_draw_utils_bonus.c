/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:50:26 by yhajbi            #+#    #+#             */
/*   Updated: 2025/02/22 09:50:27 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	ft_draw_up(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->p_data->p_x;
	y = vars->p_data->p_y;
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->sprites->soyjak, x * 64, y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->sprites->ground, x * 64, (y + 1) * 64);
	ft_printf("Move = %d\n", ++vars->move);
}

static void	ft_draw_down(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->p_data->p_x;
	y = vars->p_data->p_y;
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->sprites->soyjak, x * 64, y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->sprites->ground, x * 64, (y - 1) * 64);
	ft_printf("Move = %d\n", ++vars->move);
}

static void	ft_draw_right(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->p_data->p_x;
	y = vars->p_data->p_y;
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->sprites->soyjak, x * 64, y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->sprites->ground, (x - 1) * 64, y * 64);
	ft_printf("Move = %d\n", ++vars->move);
}

static void	ft_draw_left(t_vars *vars)
{
	int	x;
	int	y;

	x = vars->p_data->p_x;
	y = vars->p_data->p_y;
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->sprites->soyjak, x * 64, y * 64);
	mlx_put_image_to_window(vars->mlx, vars->win,
		vars->sprites->ground, (x + 1) * 64, y * 64);
	ft_printf("Move = %d\n", ++vars->move);
}

void	ft_draw_move(t_vars *vars, int flag)
{
	if (flag == 1)
		ft_draw_up(vars);
	else if (flag == 2)
		ft_draw_down(vars);
	else if (flag == 3)
		ft_draw_right(vars);
	else if (flag == 4)
		ft_draw_left(vars);
}
