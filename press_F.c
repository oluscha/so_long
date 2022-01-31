/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_F.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:52:42 by lschwart          #+#    #+#             */
/*   Updated: 2021/10/10 13:52:49 by lschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	press_w(t_sos *sos)
{
	int	b;

	b = sos->heigth;
	if (sos->map[b - 1][sos->width] == 'C'
		|| sos->map[b - 1][sos->width] == '0'
		|| (sos->map[b - 1][sos->width] == 'E'
		&& sos->has_collected == sos->collect))
	{
		if (sos->map[b - 1][sos->width] == 'C')
			sos->has_collected++;
		sos->moves++;
		sos->heigth--;
		if (sos->map[sos->heigth][sos->width] == 'E')
			sos->win++;
		sos->map[sos->heigth][sos->width] = 'P';
		sos->map[b][sos->width] = '0';
	}
}

void	press_s(t_sos *sos)
{
	int	b;

	b = sos->heigth;
	if (sos->map[b + 1][sos->width] == 'C'
		|| sos->map[b + 1][sos->width] == '0'
		|| (sos->map[b + 1][sos->width] == 'E'
		&& sos->has_collected == sos->collect))
	{
		if (sos->map[b + 1][sos->width] == 'C')
			sos->has_collected++;
		sos->moves++;
		sos->heigth++;
		if (sos->map[sos->heigth][sos->width] == 'E')
			sos->win++;
		sos->map[sos->heigth][sos->width] = 'P';
		sos->map[b][sos->width] = '0';
	}
}

void	press_d(t_sos *sos)
{
	int	b;

	b = sos->width;
	if (sos->map[sos->heigth][b + 1] == 'C'
		|| sos->map[sos->heigth][b + 1] == '0'
		|| (sos->map[sos->heigth][b + 1] == 'E'
		&& sos->has_collected == sos->collect))
	{
		if (sos->map[sos->heigth][b + 1] == 'C')
			sos->has_collected++;
		sos->moves++;
		sos->width++;
		if (sos->map[sos->heigth][sos->width] == 'E')
			sos->win++;
		sos->map[sos->heigth][sos->width] = 'P';
		sos->map[sos->heigth][b] = '0';
	}
}

void	press_a(t_sos *sos)
{
	int	b;

	b = sos->width;
	if (sos->map[sos->heigth][b - 1] == 'C'
		|| sos->map[sos->heigth][b - 1] == '0'
		|| (sos->map[sos->heigth][b - 1] == 'E'
		&& sos->has_collected == sos->collect))
	{
		if (sos->map[sos->heigth][b - 1] == 'C')
			sos->has_collected++;
		sos->moves++;
		sos->width--;
		if (sos->map[sos->heigth][b - 1] == 'E')
			sos->win++;
		sos->map[sos->heigth][sos->width] = 'P';
		sos->map[sos->heigth][b] = '0';
	}
}

int	keyboard(int keycode, t_sos *sos)
{
	if (keycode == ESC)
		close_game(sos);
	if (keycode == W)
		press_w(sos);
	if (keycode == D)
		press_d(sos);
	if (keycode == A)
		press_a(sos);
	if (keycode == S)
		press_s(sos);
	if (keycode == W || keycode == D || keycode == A || keycode == S)
		printf("Moves:%d\n", sos->moves);
	return (0);
}
