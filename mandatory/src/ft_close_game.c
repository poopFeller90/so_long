/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 10:07:12 by yhajbi            #+#    #+#             */
/*   Updated: 2025/02/22 10:07:14 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_destroy_sprites(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->sprites->soyjak);
	mlx_destroy_image(vars->mlx, vars->sprites->cobson);
	mlx_destroy_image(vars->mlx, vars->sprites->soylent);
	mlx_destroy_image(vars->mlx, vars->sprites->ground);
	mlx_destroy_image(vars->mlx, vars->sprites->wall);
	mlx_destroy_image(vars->mlx, vars->sprites->exit);
}

static void	ft_free_matrix(t_vars *vars)
{
	char	**map;
	int		i;

	map = vars->p_data->matrix;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_close_game(t_vars *vars)
{
	ft_destroy_sprites(vars);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_loop_end(vars->mlx);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free(vars->p_data->map);
	ft_free_matrix(vars);
	ft_printf("Thank you for playing\n");
	exit(EXIT_SUCCESS);
}
