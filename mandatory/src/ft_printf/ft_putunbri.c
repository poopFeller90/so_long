/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:52:54 by yhajbi            #+#    #+#             */
/*   Updated: 2024/11/19 03:04:02 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbri(unsigned int n)
{
	if (n > 9)
	{
		ft_putunbri(n / 10);
		ft_putunbri(n % 10);
	}
	else if (n <= 9)
		ft_putchari(n + 48);
	return (ft_countd(n, 10));
}
