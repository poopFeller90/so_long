/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:39:13 by yhajbi            #+#    #+#             */
/*   Updated: 2025/02/22 09:39:15 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	ft_free_list(t_parse_map *head)
{
	t_parse_map	*next;
	t_parse_map	*node;

	node = head;
	while (node)
	{
		next = node->next;
		free(node->line);
		free(node);
		node = next;
	}
}

static int	ft_get_len(t_parse_map *head)
{
	int			len;
	t_parse_map	*node;

	len = 0;
	node = head;
	while (node)
	{
		len += ft_strlen(node->line);
		node = node->next;
	}
	return (len);
}

static void	ft_copy_lines(t_parse_map *head, char *map)
{
	int			map_i;
	int			line_i;
	t_parse_map	*node;

	map_i = 0;
	node = head;
	while (node)
	{
		line_i = 0;
		while (node->line[line_i])
		{
			map[map_i] = node->line[line_i];
			map_i++;
			line_i++;
		}
		node = node->next;
	}
	map[map_i] = '\0';
}

static t_parse_map	*ft_get_list(int fd)
{
	t_parse_map	*head;
	t_parse_map	*node;
	char		*tmp;

	tmp = get_next_line(fd);
	if (!tmp)
		return (NULL);
	head = malloc(sizeof(t_parse_map));
	if (!head)
		return (NULL);
	head->line = tmp;
	node = head;
	while (node)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		node->next = malloc(sizeof(t_parse_map));
		if (!node->next)
			return (free(tmp), ft_free_list(head), NULL);
		node = node->next;
		node->line = tmp;
	}
	return (node->next = NULL, head);
}

char	*ft_parse_map(int fd)
{
	t_parse_map	*head;
	char		*map;
	int			total_len;

	head = ft_get_list(fd);
	if (!head)
		return (NULL);
	total_len = ft_get_len(head);
	map = malloc(sizeof(char) * (total_len + 1));
	if (!map)
		return (ft_free_list(head), NULL);
	ft_copy_lines(head, map);
	return (ft_free_list(head), map);
}
