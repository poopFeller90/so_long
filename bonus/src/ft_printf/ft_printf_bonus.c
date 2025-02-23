/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <yhajbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 11:19:00 by yhajbi            #+#    #+#             */
/*   Updated: 2024/11/23 11:37:54 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/* ft_printf:
 * Initializes ptr with the arguments and calls
 * ft_switch that checks for specifiers or just
 * printf the characters from *str */

int	ft_printf(const char *str, ...)
{
	int		count;
	va_list	ptr;

	count = 0;
	va_start(ptr, str);
	if (write(1, NULL, 0) < 0)
		return (-1);
	while (*str)
	{
		count += ft_switch((char **)&str, ptr);
		if (*str)
			str++;
	}
	va_end(ptr);
	return (count);
}
