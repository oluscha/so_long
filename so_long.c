/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lschwart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 13:52:42 by lschwart          #+#    #+#             */
/*   Updated: 2021/10/10 13:52:49 by lschwart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sos(t_sos *sos)
{
	sos->map = NULL;
	sos->row = 0;
	sos->length = 0;
	sos->exit = 0;
	sos->collect = 0;
	sos->start_pos = 0;
	sos->width = 0;
	sos->heigth = 0;
	sos->moves = 0;
	sos->win = 0;
	sos->has_collected = 0;
	sos->exit_height = 0;
	sos->exit_width = 0;
}

void	ft_extension(char **argv)
{
	if (argv[1][ft_strlen(argv[1]) - 1] != 'r'
		|| argv[1][ft_strlen(argv[1]) - 2] != 'e'
		|| argv[1][ft_strlen(argv[1]) - 3] != 'b'
		|| argv[1][ft_strlen(argv[1]) - 4] != '.')
	{
		printf("Error\nWrong extention of file\n"),
		exit(1);
	}
}

void	ft_check_fd_map(char **argv, t_sos *sos)
{
	int		fd;
	char	*help;

	ft_extension(argv);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || fd > 10240)
	{
		printf("Error\nOops \"%s\" not opened\n", argv[1]),
		close(fd),
		exit(1);
	}
	help = get_next_line(fd);
	while (help != NULL)
	{
		sos->row++;
		free(help);
		help = get_next_line(fd);
	}
	if (sos->row == 0)
	{
		printf("Error\nOops \"%s\" is empty\n", argv[1]),
		close(fd),
		exit(1);
	}
	close(fd);
}

int	put_to_window(t_sos *sos)
{
	static int	counter;

	mlx_clear_window(sos->mlx, sos->mlx_win);
	if (sos->win == 1)
	{
		counter++;
		mlx_put_image_to_window(sos->mlx, sos->mlx_win, sos->img_win,
			sos->length * 16 - 48, sos->row * 16 - 48);
		if (counter == 250)
			close_game(sos);
	}
	else
		put_map_to_window(sos, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_sos	sos;
	int		length;

	length = ft_strlen(argv[1]);
	if (argc != 2)
	{
		printf("%s", "Oops, wrong number of arguments\n"),
		exit(1);
	}
	init_sos(&sos);
	ft_parsing(argv, &sos);
	ft_check_overall(&sos);
	sos.mlx = mlx_init();
	ft_match_images(&sos);
	sos.mlx_win = mlx_new_window(sos.mlx, sos.length * 32,
			sos.row * 32, "so_long");
	printf("Moves: %d\n", sos.moves);
	mlx_hook(sos.mlx_win, 2, 0, keyboard, &sos);
	mlx_hook(sos.mlx_win, 17, 0, close_game, &sos);
	mlx_loop_hook(sos.mlx, put_to_window, &sos);
	mlx_loop(sos.mlx);
	return (0);
}
