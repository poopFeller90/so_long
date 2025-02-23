/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <yhajbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:56:07 by yhajbi            #+#    #+#             */
/*   Updated: 2024/11/22 14:24:54 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/* ft_switch:
 * Checks if **str is a specifier. if it is,
 * it calls ft_handle _specifier to print
 * the specifier with its proper argument.
 * Or just prints the character if it isnt
 * a specifier, with ft_putchari. It also
 * keeps track of the count of everything
 * printed and returns it to the calling
 * function ft_printf. */

int	ft_switch(char **str, va_list ptr)
{
	int		count;

	count = 0;
	if (**str == '%')
	{
		(*str)++;
		count += ft_handle_specifier(str, ptr);
	}
	else
		count += ft_putchari(**str);
	return (count);
}
