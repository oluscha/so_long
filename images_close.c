/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_close.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:52:42 by lschwart          #+#    #+#             */
/*   Updated: 2021/10/10 13:52:49 by lschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_images(t_sos *sos)
{
	mlx_destroy_image(sos->mlx, sos->img_1);
	mlx_destroy_image(sos->mlx, sos->img_0);
	mlx_destroy_image(sos->mlx, sos->img_c);
	mlx_destroy_image(sos->mlx, sos->img_e);
	mlx_destroy_image(sos->mlx, sos->img_p);
}

void	clean_map(t_sos *sos)
{
	int	counter;

	counter = 0;
	while (counter < sos->row)
	{
		free(sos->map[counter]);
		counter++;
	}
	free(sos->map);
}

int	close_game(t_sos *sos)
{
	clean_map(sos);
	destroy_images(sos);
	mlx_clear_window(sos->mlx, sos->mlx_win);
	mlx_destroy_window(sos->mlx, sos->mlx_win);
	exit(0);
	return (0);
}

void	ft_match_images(t_sos *sos)
{
	int	width;
	int	heigth;

	width = 0;
	heigth = 0;
	sos->img_1 = mlx_xpm_file_to_image(sos->mlx,
			"./img/1.XPM", &width, &heigth);
	sos->img_0 = mlx_xpm_file_to_image(sos->mlx,
			"./img/0.XPM", &width, &heigth);
	sos->img_c = mlx_xpm_file_to_image(sos->mlx,
			"./img/C.XPM", &width, &heigth);
	sos->img_e = mlx_xpm_file_to_image(sos->mlx,
			"./img/E.XPM", &width, &heigth);
	sos->img_p = mlx_xpm_file_to_image(sos->mlx,
			"./img/P.XPM", &width, &heigth);
	sos->img_win = mlx_xpm_file_to_image(sos->mlx,
			"./img/WIN.XPM", &width, &heigth);
}

int	put_map_to_window(t_sos *sos, int c, int r)
{
	while (r < sos->row)
	{
		c = 0;
		while (c < sos->length)
		{
			if (sos->map[r][c] == '1')
				mlx_put_image_to_window(sos->mlx, sos->mlx_win,
					sos->img_1, c * 32, r * 32);
			if (sos->map[r][c] == '0')
				mlx_put_image_to_window(sos->mlx, sos->mlx_win,
					sos->img_0, c * 32, r * 32);
			if (sos->map[r][c] == 'C')
				mlx_put_image_to_window(sos->mlx, sos->mlx_win,
					sos->img_c, c * 32, r * 32);
			if (sos->map[r][c] == 'E')
				mlx_put_image_to_window(sos->mlx, sos->mlx_win,
					sos->img_e, c * 32, r * 32);
			if (sos->map[r][c] == 'P')
				mlx_put_image_to_window(sos->mlx, sos->mlx_win,
					sos->img_p, c * 32, r * 32);
			c++;
		}
		r++;
	}
	return (0);
}
