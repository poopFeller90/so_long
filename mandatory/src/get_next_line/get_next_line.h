/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 20:56:16 by yhajbi            #+#    #+#             */
/*   Updated: 2025/01/17 18:41:38 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define OPEN_MAX 1024

typedef struct s_fragment
{
	char				fragment[BUFFER_SIZE];
	ssize_t				sz;
	int					stop;
	struct s_fragment	*next;
}						t_fragment;

char	*get_next_line(int fd);
void	ft_free_nodes(t_fragment *p_head);
char	*ft_defragment(t_fragment *p_head);

#endif
