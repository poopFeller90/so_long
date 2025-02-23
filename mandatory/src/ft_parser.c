/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:30:21 by yhajbi            #+#    #+#             */
/*   Updated: 2025/01/21 21:32:12 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	ft_check_walls(t_parse_data *p_data, char *line, int flag)
{
	int	i;

	i = 0;
	if (flag == 0)
	{
		while (line[i])
		{
			if (line[i] != '1')
			{
				p_data->is_valid = 0;
				ft_printf("Horizontal walls are not closed\n");
				break ;
			}
			i++;
		}
	}
	else if (flag == 1)
	{
		if (line[0] != '1' || line[p_data->map_width - 1] != '1')
		{
			p_data->is_valid = 0;
			ft_printf("Vertical walls are not closed\n");
		}
	}
}

static int	ft_check_suffix(char *map_file)
{
	int	i;

	i = 0;
	if (map_file[i] == '.' && ft_strcmp(map_file, ".ber") != -1)
		return (-1);
	while (map_file[i] && map_file[i] != '.')
		i++;
	if (!map_file[i])
		return (-1);
	if (ft_strcmp((map_file + i), ".ber") != 0)
		return (-1);
	return (0);
}

static void	ft_check_enclosed_walls(t_parse_data *p_data)
{
	int	i;

	i = 0;
	p_data->matrix = ft_split(p_data->map, '\n');
	while (p_data->matrix[i])
	{
		if (i == 0 || i == (p_data->map_height - 1))
			ft_check_walls(p_data, p_data->matrix[i], 0);
		else
			ft_check_walls(p_data, p_data->matrix[i], 1);
		i++;
	}
}

static void	ft_check_map_content(t_parse_data *p_data)
{
	int	i;

	i = 0;
	p_data->collectibles = 0;
	p_data->exits = 0;
	p_data->players = 0;
	while (p_data->map[i])
	{
		if (p_data->map[i] == '\n'
			&& (p_data->map[i + 1] == '\n' || p_data->map[i + 1] == '\0'))
			p_data->is_valid = 0;
		if (!ft_check_character(p_data->map[i]))
			p_data->is_valid = 0;
		if (p_data->map[i] == 'E')
			p_data->exits++;
		else if (p_data->map[i] == 'C')
			p_data->collectibles++;
		else if (p_data->map[i] == 'P')
			p_data->players++;
		i++;
	}
	if (p_data->players != 1 || p_data->exits != 1 || p_data->collectibles < 1)
		p_data->is_valid = 0;
}

int	ft_parse_args(char *map_file, t_parse_data *p_data)
{
	int		fd;

	p_data->is_valid = 1;
	if (ft_check_suffix(map_file) == -1)
		return (ft_printf("Please provide a [.ber] file\n")
			, p_data->is_valid = 0, -1);
	fd = open (map_file, O_RDONLY);
	if (fd < 0)
		return (ft_printf("The map file was not found\n")
			, p_data->is_valid = 0, -1);
	p_data->map = ft_parse_map(fd);
	if (!p_data->map)
		return (ft_printf("The map is empty\n"), -1);
	close(fd);
	ft_get_dimensions(p_data);
	ft_check_enclosed_walls(p_data);
	if (p_data->is_valid)
		ft_check_map_content(p_data);
	if (p_data->is_valid)
		ft_check_path(p_data);
	return (0);
}
