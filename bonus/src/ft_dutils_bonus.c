/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dutils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:39:19 by yhajbi            #+#    #+#             */
/*   Updated: 2025/02/23 14:39:21 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_helper_soylent(t_vars *vars, int w, int h)
{
	vars->sprites->soylent[0] = mlx_xpm_file_to_image(vars->mlx,
			I_SOYLENT_1, &w, &h);
	vars->sprites->soylent[1] = mlx_xpm_file_to_image(vars->mlx,
			I_SOYLENT_2, &w, &h);
	vars->sprites->soylent[2] = mlx_xpm_file_to_image(vars->mlx,
			I_SOYLENT_3, &w, &h);
	if (!vars->sprites->soylent[0] || !vars->sprites->soylent[1]
		|| !vars->sprites->soylent[2])
		return (0);
	return (1);
}
