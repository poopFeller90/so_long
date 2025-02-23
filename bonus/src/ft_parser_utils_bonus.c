/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:30:15 by yhajbi            #+#    #+#             */
/*   Updated: 2025/01/21 21:32:12 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret_s;
	int		sum_sz;

	if (!s1 || !s2)
		return (NULL);
	sum_sz = ft_strlen(s1) + ft_strlen(s2);
	ret_s = (char *)malloc((sum_sz + 1) * sizeof(char));
	if (!ret_s)
		return (NULL);
	while (*s1)
		*ret_s++ = *s1++;
	while (*s2)
		*ret_s++ = *s2++;
	*ret_s = '\0';
	return (ret_s - sum_sz);
}

void	ft_get_dimensions(t_parse_data *p_data)
{
	int	i;

	i = 0;
	p_data->map_height = 0;
	p_data->map_width = 0;
	while (p_data->map[i] != '\n')
	{
		p_data->map_width++;
		i++;
	}
	while (p_data->map[i])
	{
		if (p_data->map[i] == '\n')
			p_data->map_height++;
		i++;
	}
	p_data->map_height++;
}

int	ft_check_character(char c)
{
	return (c == 'P' || c == 'H' || c == 'E' || c == 'C'
		|| c == '1' || c == '0' || c == '\n');
}
