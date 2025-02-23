/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmemory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:54:14 by yhajbi            #+#    #+#             */
/*   Updated: 2024/11/19 23:16:37 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printmemory(void *ptr)
{
	int				i;
	int				dg;
	char			*buffer;
	unsigned long	address;

	address = (unsigned long)ptr;
	if (!ptr)
		return (ft_putstri("0x0"), 3);
	dg = ft_countd(address, 16);
	i = dg + 1;
	buffer = malloc((dg + 3) * sizeof(char));
	if (!buffer)
		return (0);
	buffer[0] = '0';
	buffer[1] = 'x';
	buffer[i + 1] = '\0';
	while (address > 0)
	{
		buffer[i--] = L_HEX[address % 16];
		address /= 16;
	}
	ft_putstri(buffer);
	free(buffer);
	return (dg + 2);
}
