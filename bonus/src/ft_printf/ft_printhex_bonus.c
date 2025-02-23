/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <yhajbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:55:01 by yhajbi            #+#    #+#             */
/*   Updated: 2024/11/21 20:42:54 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_printhex(unsigned int n, int flag)
{
	int		dg;
	char	*buffer;

	dg = ft_countd(n, 16);
	buffer = malloc((dg + 1) * sizeof(char));
	if (!buffer)
		return (0);
	buffer[dg] = '\0';
	if (!n)
		return (free(buffer), ft_putstri("0\0"), dg);
	while (n > 0)
	{
		if (flag)
		{
			buffer[--dg] = U_HEX[n % 16];
			n /= 16;
		}
		else if (!flag)
		{
			buffer[--dg] = L_HEX[n % 16];
			n /= 16;
		}
	}
	dg = ft_putstri(buffer);
	return (free(buffer), dg);
}
