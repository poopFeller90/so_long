/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 14:03:49 by yhajbi            #+#    #+#             */
/*   Updated: 2025/02/23 14:03:51 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_init_pdata(t_parse_data *p_data)
{
	p_data->collectibles = 0;
	p_data->exits = 0;
	p_data->players = 0;
	p_data->hostiles = 0;
}
