/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_specifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <yhajbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:55:38 by yhajbi            #+#    #+#             */
/*   Updated: 2024/11/23 11:36:30 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/* ft_handle_specifier:
 * basically a switch of if statements
 * that check if **str is one of the
 * specifiers cdiuspxX and calls the
 * appripriate function to print the
 * argument, then returns the count
 * of the printed characters. */

int	ft_handle_specifier(char **str, va_list ptr)
{
	int	count;

	count = 0;
	if (**str == 0)
		return (count);
	if (**str == '%')
		count += ft_putchari('%');
	else if (**str == 'c')
		count += ft_putchari(va_arg(ptr, int));
	else if ((**str == 'd' || **str == 'i'))
		count += ft_putnbri(va_arg(ptr, int));
	else if (**str == 'u')
		count += ft_putunbri(va_arg(ptr, unsigned int));
	else if (**str == 's')
		count += ft_putstri(va_arg(ptr, char *));
	else if (**str == 'p' )
		count += ft_printmemory(va_arg(ptr, void *));
	else if (**str == 'x' )
		count += ft_printhex(va_arg(ptr, unsigned int), 0);
	else if (**str == 'X')
		count += ft_printhex(va_arg(ptr, unsigned int), 1);
	return (count);
}
