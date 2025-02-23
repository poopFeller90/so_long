/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <yhajbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 02:59:52 by yhajbi            #+#    #+#             */
/*   Updated: 2024/11/23 11:37:04 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define U_HEX "0123456789ABCDEF"
# define L_HEX "0123456789abcdef"

int	ft_putchari(char c);
int	ft_strleni(char *str);
int	ft_putstri(char *str);
int	ft_countd(unsigned long n, int base);
int	ft_putnbri(int n);
int	ft_putunbri(unsigned int n);
int	ft_printmemory(void *ptr);
int	ft_printhex(unsigned int n, int flag);
int	ft_handle_specifier(char **str, va_list ptr);
int	ft_switch(char **str, va_list ptr);
int	ft_printf(const char *str, ...);

#endif
