/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:50:18 by yhajbi            #+#    #+#             */
/*   Updated: 2025/02/22 09:50:19 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	*ft_helper(void *mlx, int img, int w, int h)
{
	if (img == 1)
		return (mlx_xpm_file_to_image(mlx, I_SOYJAK, &w, &h));
	else if (img == 2)
		return (mlx_xpm_file_to_image(mlx, I_COBSON, &w, &h));
	else if (img == 3)
		return (mlx_xpm_file_to_image(mlx, I_SOYLENT, &w, &h));
	else if (img == 4)
		return (mlx_xpm_file_to_image(mlx, I_WALL, &w, &h));
	else if (img == 5)
		return (mlx_xpm_file_to_image(mlx, I_EXIT, &w, &h));
	else if (img == 6)
		return (mlx_xpm_file_to_image(mlx, I_GROUND, &w, &h));
	return (NULL);
}

static int	ft_convert_sprites(t_vars *vars)
{
	vars->sprites->soyjak = ft_helper(vars->mlx, 1, 64, 64);
	if (!vars->sprites->soyjak)
		return (0);
	vars->sprites->cobson = ft_helper(vars->mlx, 2, 64, 64);
	if (!vars->sprites->cobson)
		return (0);
	vars->sprites->soylent = ft_helper(vars->mlx, 3, 64, 64);
	if (!vars->sprites->soylent)
		return (0);
	vars->sprites->wall = ft_helper(vars->mlx, 4, 64, 64);
	if (!vars->sprites->wall)
		return (0);
	vars->sprites->exit = ft_helper(vars->mlx, 5, 64, 64);
	if (!vars->sprites->exit)
		return (0);
	vars->sprites->ground = ft_helper(vars->mlx, 6, 64, 64);
	if (!vars->sprites->ground)
		return (0);
	return (1);
}

static void	ft_draw_sprite(t_sprites *sprites, void *mlx, void *win, char c)
{
	if (c == '0')
		mlx_put_image_to_window(mlx, win,
			sprites->ground, sprites->x, sprites->y);
	else if (c == '1')
		mlx_put_image_to_window(mlx, win,
			sprites->wall, sprites->x, sprites->y);
	else if (c == 'C')
		mlx_put_image_to_window(mlx, win,
			sprites->soylent, sprites->x, sprites->y);
	else if (c == 'P')
		mlx_put_image_to_window(mlx, win,
			sprites->soyjak, sprites->x, sprites->y);
	else if (c == 'E')
		mlx_put_image_to_window(mlx, win,
			sprites->exit, sprites->x, sprites->y);
}

static void	ft_draw_map(t_vars *vars, t_sprites *sprites)
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
			sprites->x = x * 64;
			sprites->y = y * 64;
			ft_draw_sprite(sprites, vars->mlx, vars->win, map[y][x]);
			x++;
		}
		y++;
	}
}

int	ft_draw(t_vars *vars, int flag)
{
	static int			ret;
	static int			num;
	static t_sprites	sprites;

	vars->sprites = &sprites;
	if (!flag)
	{
		ret = ft_convert_sprites(vars);
		if (ret)
			ft_draw_map(vars, &sprites);
		else
			ft_close_game(vars);
		vars->sprites = &sprites;
	}
	if (num > 0)
		ft_printf("Move = %d\n", num);
	ft_draw_move(vars, flag);
	num++;
	return (0);
}
