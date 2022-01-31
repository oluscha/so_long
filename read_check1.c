/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_check1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:52:42 by lschwart          #+#    #+#             */
/*   Updated: 2021/10/10 13:52:49 by lschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_sos(t_sos *sos, int c)
{
	if (!(sos->map[c]))
	{
		clean_map(sos);
		printf("Error\nSome memory problems\n"),
		exit(1);
	}
}

void	ft_parsing(char **argv, t_sos *sos)
{
	int		fd;
	int		c;
	char	*help;

	ft_check_fd_map(argv, sos);
	fd = open(argv[1], O_RDONLY);
	c = 0;
	sos->map = (char **)malloc(sizeof(char *) * sos->row);
	while (c < sos->row)
	{
		help = get_next_line(fd);
		sos->map[c] = help;
		if (sos->map[c][ft_strlen(sos->map[c]) - 1] == '\n')
		{
			sos->map[c] = ft_substr(sos->map[c], 0, ft_strlen(sos->map[c]) - 1);
			ft_free_sos(sos, c);
			free(help);
		}
		c++;
	}
	close(fd);
}

int	ft_check_length(t_sos *sos)
{
	size_t	length;
	size_t	length_new;
	int		counter_row;
	int		check;

	check = 1;
	counter_row = sos->row - 1;
	length = ft_strlen(sos->map[counter_row]);
	while (counter_row != 0)
	{
		length_new = ft_strlen (sos->map[counter_row - 1]);
		if (length != length_new)
			check = 0;
		counter_row--;
	}
	if (check == 1)
		sos->length = ft_strlen(sos->map[sos->row - 1]);
	return (check);
}

int	ft_check_surround(t_sos	*sos)
{
	int	check;
	int	counter;

	check = 1;
	counter = sos->length - 1;
	while (counter >= 0)
	{
		if ((sos->map[0][counter] != '1')
			|| (sos->map[sos->row - 1][counter] != '1'))
			check = 0;
		counter--;
	}
	counter = sos->row - 1;
	while (counter >= 0)
	{
		if ((sos->map[counter][0] != '1')
			|| (sos->map[counter][0] != '1'))
			check = 0;
		counter--;
	}
	return (check);
}
