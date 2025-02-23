/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_controls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:48:46 by yhajbi            #+#    #+#             */
/*   Updated: 2025/02/22 09:48:47 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_handle_controls(int keycode, t_vars *vars)
{
	if (keycode == XK_Up || keycode == XK_w)
		ft_move_up(vars);
	else if (keycode == XK_Down || keycode == XK_s)
		ft_move_down(vars);
	else if (keycode == XK_Right || keycode == XK_d)
		ft_move_right(vars);
	else if (keycode == XK_Left || keycode == XK_a)
		ft_move_left(vars);
}

int	ft_control_hook(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape && vars->mlx)
		ft_close_game(vars);
	else
		ft_handle_controls(keycode, vars);
	return (0);
}
