/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:30:34 by yhajbi            #+#    #+#             */
/*   Updated: 2025/01/21 21:31:49 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	ft_find_player(t_parse_data *p_data)
{
	int	x;
	int	y;

	y = 0;
	while (p_data->matrix[y])
	{
		x = 0;
		while (p_data->matrix[y][x])
		{
			if (p_data->matrix[y][x] == 'P')
			{
				p_data->p_x = x;
				p_data->p_y = y;
			}
			x++;
		}
		y++;
	}
}

static char	**ft_copy_map(t_parse_data *p_data)
{
	int		i;
	char	**map;

	i = 0;
	map = malloc((p_data->map_height + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	while (p_data->matrix[i])
	{
		map[i] = ft_strdup(p_data->matrix[i]);
		i++;
	}
	map[i] = 0;
	return (map);
}

static void	ft_flood_fill(char **map, int x, int y)
{
	int	row;

	row = 0;
	while (map[row])
		row++;
	if (x > ft_strlen(map[0]) || y > row || x < 0 || y < 0)
		return ;
	if (map[y][x] == '0' || map[y][x] == 'C'
			|| map[y][x] == 'E' || map[y][x] == 'P' || map[y][x] == 'H')
	{
		if (map[y][x] == 'E')
		{
			map[y][x] = 'X';
			return ;
		}
		map[y][x] = 'X';
	}
	else
		return ;
	ft_flood_fill(map, x + 1, y);
	ft_flood_fill(map, x - 1, y);
	ft_flood_fill(map, x, y + 1);
	ft_flood_fill(map, x, y - 1);
}

static void	ft_check_flooded_map(char **map, t_parse_data *p_data)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == '0'
					|| map[y][x] == 'P' || map[y][x] == 'E' || map[y][x] == 'H')
			{
				p_data->is_valid = 0;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	ft_check_path(t_parse_data *p_data)
{
	char	**map;
	int		i;

	map = ft_copy_map(p_data);
	ft_find_player(p_data);
	ft_flood_fill(map, p_data->p_x, p_data->p_y);
	ft_check_flooded_map(map, p_data);
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
