/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:52:42 by lschwart          #+#    #+#             */
/*   Updated: 2021/10/10 13:52:49 by lschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_stuff1(t_sos *sos)
{
	int	c_r;
	int	c_l;

	c_r = sos->row - 1;
	while (c_r >= 0)
	{
		c_l = sos->length - 1;
		while (c_l >= 0)
		{
			if (sos->map[c_r][c_l] == 'E')
				sos->exit++;
			if (sos->map[c_r][c_l] == 'C')
				sos->collect++;
			if (sos->map[c_r][c_l] == 'P')
			{
				sos->start_pos++;
				sos->width = c_l;
				sos->heigth = c_r;
			}
			c_l--;
		}
		c_r--;
	}
	ft_check_stuff2(sos);
	return (ft_check_stuff3(sos));
}

void	ft_check_stuff2(t_sos *sos)
{
	int	c_r;
	int	c_l;

	c_r = sos->row - 1;
	while (c_r >= 0)
	{
		c_l = sos->length - 1;
		while (c_l >= 0)
		{
			if (sos->map[c_r][c_l] != 'E' && sos->map[c_r][c_l] != 'C'
				&& sos->map[c_r][c_l] != 'P' && sos->map[c_r][c_l] != '0'
				&& sos->map[c_r][c_l] != '1')
			{
				printf("%s", "Error\nOops, the map's elements are incorrect\n"),
				exit(1);
			}
			c_l--;
		}
		c_r--;
	}
}

int	ft_check_stuff3(t_sos *sos)
{
	int	check;

	check = 1;
	if (sos->exit == 0 || sos->collect == 0 || sos->start_pos != 1)
		check = 0;
	return (check);
}

int	ft_check_overall(t_sos *sos)
{
	int	check;

	check = 1;
	if (ft_check_length(sos) == 0 || ft_check_stuff1(sos) == 0
		|| ft_check_surround(sos) == 0 || ft_check_surround(sos) == 0)
	{
		if (ft_check_length(sos) == 0)
			printf("%s", "Error\nOops, the map is not rectangular\n");
		else if (sos->exit == 0)
			printf("%s", "Error\nOops, there is no exit\n");
		else if (sos->collect == 0)
			printf("%s", "Error\nOops, there is no collectives\n");
		else if (sos->start_pos != 1)
			printf("%s", "Error\nOops, incorrect number of starting positions\n");
		else if (ft_check_surround(sos) == 0)
			printf("%s", "Error\nOops, the map is not surrounded\n");
		if (ft_check_length(sos) == 0 || ft_check_stuff1(sos) == 0
			|| ft_check_surround(sos) == 0 || ft_check_surround(sos) == 0)
			exit(1);
		check--;
	}
	return (check);
}
