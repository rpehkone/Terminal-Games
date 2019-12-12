/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:00:15 by rpehkone          #+#    #+#             */
/*   Updated: 2019/12/13 01:24:31 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

char	**make_arena(char size_w, char size_h)
{
	char **arena;
	char i;
	char j;

	i = 0;
	arena = (char**)malloc(sizeof(char*) * size_w);
	while (i < size_w)
	{
		arena[i] = (char*)malloc(sizeof(char) * (size_h * 1));
		arena[i][size_h] = '\0';
		j = 0;
		while (j < size_h)
		{
			arena[i][j] = BLANK;
			j++;
		}
		i++;
	}
	return (arena);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	str[11];
	int		tmp;
	int		size;

	size = 0;
	if (n == 0)
		write(fd, "0", 1);
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
		if (n *= -1)
			write(fd, "-", 1);
	tmp = n;
	while (tmp > 0 && ++size)
		tmp /= 10;
	str[size] = '\0';
	while (size--)
	{
		str[size] = n % 10 + '0';
		n /= 10;
	}
	size++;
	while (str[size])
		write(fd, &str[size++], 1);
}

void	make_frame(char size_w, char size_h, char ***arena, int fd, int edge_color)
{
	int y;
	int x;
	x = 0;
	if (edge_color != BLANK)
	{
		while (x <= size_w + 1)
		{
			write(fd, "\e[48;5;", 7);
			ft_putnbr_fd(edge_color, fd);
			write(fd, "m\03  \e[0m", 8);
			x++;
		}
		write(fd, "\n\r", 2);
	}
	y = 0;
	while (y < size_h)
	{
		x = 0;
		if (edge_color != BLANK)
		{
			write(fd, "\e[48;5;", 7);
			ft_putnbr_fd(edge_color, fd);
			write(fd, "m\03  \e[0m", 8);
		}
		while (arena[0][y][x])
		{
			if (arena[0][y][x] == BLANK)
				write(fd, "  ", 2);
			else
			{
				write(fd, "\e[48;5;", 7);
				ft_putnbr_fd(arena[0][y][x], fd);
				write(fd, "m\03", 2);
				if (arena[2][y][x] == BLANK)
					write(fd, "  ", 2);
				else
				{
					write(fd, " ", 1);
					//if (arena[1][y][x] == BLANK)
						write(fd, &arena[2][y][x], 1);
					/*else
					{
						write(fd, "\033[0;33m", 7);
						write(fd, &arena[2][y][x], 1);
						write(fd, "\033[0m", 4);
					}*/
				}
				write(fd, "\e[0m", 4);
			}
			/*
			}
			else if (arena[0][y][x] == PACMAN_U)
			{
				write(fd, "\e[48;5;232m\03", 12);
				write(fd, "\033[1;33m ᗢ\033[0m", 14);
				write(fd, "\e[0m", 4);
			}
			else if (arena[0][y][x] == PACMAN_D)
			{
				write(fd, "\e[48;5;232m\03", 12);
				write(fd, "\033[1;33m ᗣ\033[0m", 14);
				write(fd, "\e[0m", 4);
			}*/
			// ⬤\
			// ᗧ
			// ᗤ
			//━━
			// ┃
			//┗
			//┛
			//┓
			//┏
			//	ᗣ
			//write(fd, "\033[0;33m ᗧ\033[0m", 14);
			x++;
		}
		y++;
		if (edge_color != BLANK)
		{
			write(fd, "\e[48;5;", 7);
			ft_putnbr_fd(edge_color, fd);
			write(fd, "m\03  \e[0m", 8);
		}
		write(fd, "\n\r", 2);
	}
	x = 0;
	if (edge_color != BLANK)
		while (x <= size_w + 1)
		{
			write(fd, "\e[48;5;", 7);
			ft_putnbr_fd(edge_color, fd);
			write(fd, "m\03  \e[0m", 8);
			x++;
		}
}

char	timer(frame_time)
{
	struct timeval	timeout;
	struct timeval	stop;
	struct timeval	start;
	int				ready_for_reading;
	int				read_bytes;
	int				ms;
	fd_set			input_set;
	char			input[50];

	input[0] = 0;
	read_bytes = 0;
	ready_for_reading = 0;
	gettimeofday(&start, NULL);
	FD_SET(0, &input_set);
	timeout.tv_sec = 0;
	timeout.tv_usec = frame_time;
	ready_for_reading = select(1, &input_set, NULL, NULL, &timeout);
	if (ready_for_reading)
		read_bytes = read(0, input, 50);
	gettimeofday(&stop, NULL);
	ms = (((stop.tv_sec) * 1000 + (stop.tv_usec) / 1000) - ((start.tv_sec) * 1000 + (start.tv_usec) / 1000));
	ms *= 1000;
	usleep(6000 + frame_time - ms);
	return (input[0]);
}

void	engine(int size_w, int size_h, int speed, int edge_color,
		int (*game)(char key, char ***arena, int size_w, int size_h))
{
	char	***arena;
	char	*tmp;
	char	key;
	int		fbuff;
	int		len;

	key = 0;
	arena = (char***)malloc(sizeof(char**) * (3));
	arena[0] = make_arena(size_h, size_w);
	arena[1] = make_arena(size_h, size_w);
	arena[2] = make_arena(size_h, size_w);
	tmp = malloc(size_h * size_w * 22);
	fclose(fopen(".buff", "w"));
	system("/bin/stty raw");
	while (key != 26 && key != 27)
	{
		key = timer(speed);
		if (!(game(key, arena, size_w, size_h)))
			break ;
		fbuff = open(".buff", O_WRONLY);
		make_frame(size_w, size_h, arena, fbuff, edge_color);
		close(fbuff);
		fbuff = open(".buff", O_RDONLY);
		write(1, "\e[1;1H\e[2J", 10);
		while ((len = read(fbuff, tmp, (size_h * size_w * 22))) > 0)
			write(1, tmp, len);
		close(fbuff);
	}
	remove(".buff");
	system("/bin/stty cooked");
}
