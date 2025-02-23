/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_path_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:30:30 by yhajbi            #+#    #+#             */
/*   Updated: 2025/01/21 21:32:12 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

char	*ft_strdup(const char *s)
{
	char	*d_s;
	char	*d;

	d_s = (char *)malloc(ft_strlen(s) + 1);
	if (!d_s)
		return (NULL);
	d = d_s;
	while (*s)
	{
		*d_s = *s;
		d_s++;
		s++;
	}
	*d_s = '\0';
	return (d);
}
