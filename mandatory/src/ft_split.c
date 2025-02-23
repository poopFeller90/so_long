/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:11:47 by yhajbi            #+#    #+#             */
/*   Updated: 2025/01/20 16:57:41 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	len;

	len = ft_strlen(src);
	if (n == 0)
		return (len);
	while (*src && n > 1)
	{
		*dest = *src;
		dest++;
		src++;
		n--;
	}
	*dest = '\0';
	return (len);
}

static int	ft_countsep(const char *s, char c)
{
	int	count;
	int	w_found;

	count = 0;
	w_found = 0;
	while (*s)
	{
		if (*s != c && !w_found)
		{
			w_found = 1;
			count++;
		}
		else if (*s == c && w_found)
			w_found = 0;
		s++;
	}
	return (count);
}

static char	*ft_cpword(const char *s, char c)
{
	int		w_sz;
	char	*ret;

	w_sz = 0;
	while (s[w_sz] && s[w_sz] != c)
		w_sz++;
	ret = (char *)malloc((w_sz + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, s, w_sz + 1);
	return (ret);
}

static void	ft_clear(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
		free(ret[i++]);
	free(ret);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		sz;
	char	**ret;

	if (!s)
		return (NULL);
	i = 0;
	sz = ft_countsep(s, c);
	ret = (char **)malloc((sz + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	while (i < sz)
	{
		while (*s == c)
			s++;
		if (*s != c)
			ret[i] = ft_cpword(s, c);
		if (!ret[i])
			return (ft_clear(ret), NULL);
		s += ft_strlen(ret[i++]);
	}
	ret[i] = NULL;
	return (ret);
}
