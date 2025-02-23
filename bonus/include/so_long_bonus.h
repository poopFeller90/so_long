/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhajbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 21:27:33 by yhajbi            #+#    #+#             */
/*   Updated: 2025/01/28 14:46:40 by yhajbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "../../mlx_linux/minilibx-linux/mlx.h"
# include "../src/get_next_line/get_next_line_bonus.h"
# include "../src/ft_printf/ft_printf_bonus.h"
# include <X11/keysym.h>
# include <X11/X.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <time.h>

# define I_SOYJAK "./bonus/assets/soyjak.xpm"
# define I_COBSON "./bonus/assets/cobson.xpm"
# define I_SOYLENT_1 "./bonus/assets/soylent_1.xpm"
# define I_SOYLENT_2 "./bonus/assets/soylent_2.xpm"
# define I_SOYLENT_3 "./bonus/assets/soylent_3.xpm"
# define I_WALL "./bonus/assets/wall.xpm"
# define I_EXIT "./bonus/assets/exit.xpm"
# define I_GROUND "./bonus/assets/ground.xpm"

typedef struct s_parse_data
{
	int		is_valid;
	char	*map;
	char	**matrix;
	int		map_height;
	int		map_width;
	int		p_x;
	int		p_y;
	int		collectibles;
	int		exits;
	int		players;
	int		hostiles;
}		t_parse_data;

typedef struct	s_parse_map
{
	char				*line;
	struct s_parse_map	*next;
}						t_parse_map;

typedef struct s_sprites
{
	void	*soyjak;
	void	*cobson;
	void	*soylent[3];
	void	*wall;
	void	*exit;
	void	*ground;
	int		converted;
	int		i_frame;
	int		x;
	int		y;
	int		c_x;
	int		c_y;
	int		c_d;
}			t_sprites;

typedef struct	s_vars
{
	void			*mlx;
	void			*win;
	t_parse_data	*p_data;
	t_sprites		*sprites;
	int				move;
	int				c_init;
}					t_vars;

/*    ---    Rendering and gameplay files    ---    */

// ft_init_game.c functions:
void	ft_init_game(t_parse_data *p_data);
void	ft_find_cobson(t_vars *vars);

// ft_close_game.c functions:
void	ft_close_game(t_vars *vars);

// ft_draw.c functions:
int	ft_draw(t_vars *vars, int flag);

// ft_animation_bonus.c functions:
//int	ft_animate_soylent(t_vars *vars);
//int	ft_move_cobson(t_vars *vars);
int	ft_animation_hook(t_vars *vars);

// ft_draw_utils.c functions:
void	ft_draw_move(t_vars *vars, int flag);

// ft_controls.c functions:
int	ft_control_hook(int keycode, t_vars *vars);

// ft_move.c functions:
int	ft_move_up(t_vars *vars);
int	ft_move_down(t_vars *vars);
int	ft_move_right(t_vars *vars);
int	ft_move_left(t_vars *vars);

// ft_dutils_bonus.c functions:
int	ft_helper_soylent(t_vars *vars, int w, int h);

/*    ---    Parsing and preparation files    ---    */

// ft_parser.c functions:
int	ft_parse_args(char *map_file, t_parse_data *p_data);

// ft_parser_utils.c functions:
int	ft_strlen(char const *s);
int	ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_get_dimensions(t_parse_data *p_data);
int	ft_check_character(char c);

// ft_parse_map.c functions:
char	*ft_parse_map(int fd);

// ft_split.c functions:
char	**ft_split(char const *s, char c);

// ft_check_path.c functions:
void	ft_check_path(t_parse_data *p_data);

// ft_check_path_utils.c functions:
char	*ft_strdup(char const *s);

// ft_init_game.c functions:
void	ft_init_game(t_parse_data *p_data);

// ft_putils_bonus.c functions:
void	ft_init_pdata(t_parse_data *p_data);
#endif
