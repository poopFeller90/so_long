/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:28:56 by yhajbi            #+#    #+#             */
/*   Updated: 2025/01/28 16:43:46 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_check_assets(void)
{
	if (open(I_SOYJAK, O_RDONLY) == -1)
		return (0);
	if (open(I_COBSON, O_RDONLY) == -1)
		return (0);
	if (open(I_SOYLENT_1, O_RDONLY) == -1)
		return (0);
	if (open(I_SOYLENT_2, O_RDONLY) == -1)
		return (0);
	if (open(I_SOYLENT_3, O_RDONLY) == -1)
		return (0);
	if (open(I_WALL, O_RDONLY) == -1)
		return (0);
	if (open(I_EXIT, O_RDONLY) == -1)
		return (0);
	if (open(I_GROUND, O_RDONLY) == -1)
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_parse_data	p_data;
	int				i;

	if (argc != 2)
		return (ft_printf("Usage: ./so_long /path/to/map.ber"));
	if (!ft_check_assets())
		return (ft_printf("Unable to open asset files"), exit(EXIT_FAILURE), 0);
	if (ft_parse_args(argv[1], &p_data) == -1 || p_data.is_valid == 0)
		return (ft_printf("The map is not valid\n"), exit(EXIT_FAILURE), 0);
	else
		ft_printf("The map is valid\n\n");
	srand(time(NULL));
	ft_init_game(&p_data);
	i = 0;
	while (p_data.matrix[i])
		ft_printf("%s\n", p_data.matrix[i++]);
	return (0);
}
