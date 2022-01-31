/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:52:42 by lschwart          #+#    #+#             */
/*   Updated: 2021/10/10 13:52:49 by lschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "gnl/get_next_line.h"
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_sos
{
	char	**map;
	int		row;
	int		length;
	int		exit;
	int		collect;
	int		start_pos;
	int		heigth;
	int		width;
	int		moves;
	int		win;
	int		has_collected;
	int		exit_width;
	int		exit_height;
	void	*mlx;
	void	*mlx_win;
	void	*img_1;
	void	*img_0;
	void	*img_c;
	void	*img_e;
	void	*img_p;
	void	*img_win;
}	t_sos;

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

void	init_sos(t_sos *sos);
void	ft_parsing(char **argv, t_sos *sos);
int		ft_check_length(t_sos *sos);
int		ft_check_surround(t_sos	*sos);
int		ft_check_overall(t_sos *sos);
void	press_w(t_sos *sos);
void	press_s(t_sos *sos);
void	press_d(t_sos *sos);
void	press_a(t_sos *sos);
void	destroy_images(t_sos *sos);
void	clean_map(t_sos *sos);
int		close_game(t_sos *sos);
int		keyboard(int key, t_sos *sos);
void	ft_match_images(t_sos *sos);
int		put_map_to_window(t_sos *sos, int c, int r);
int		put_to_window(t_sos *sos);
void	ft_check_fd_map(char **argv, t_sos *sos);
void	ft_check_stuff2(t_sos *sos);
int		ft_check_stuff3(t_sos *sos);
void	ft_extension(char **argv);

#endif