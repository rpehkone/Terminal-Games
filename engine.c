/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:00:15 by rpehkone          #+#    #+#             */
/*   Updated: 2019/11/26 19:14:20 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

char	**make_arena(char size)
{
	char **arena;
	char i;
	char j;

	i = 0;
	arena = (char**)malloc(sizeof(char*) * size);
	while (i < size)
	{
		arena[i] = (char*)malloc(sizeof(char) * (size * 1));
		arena[i][size] = '\0';
		j = 0;
		while (j < size)
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

void	make_frame(char size, char **arena, int fd, int edge_color)
{
	int y;
	int x;

			if (edge_color == GREY)
				edge_color = 237;
			else if (edge_color == RED)
				edge_color = 160;
			else if (edge_color == GREEN)
				edge_color = 28;
			else if (edge_color == BLUE)
				edge_color = 20;
			else if (edge_color == YELLOW)
				edge_color = 226;
			else if (edge_color == WHITE)
				edge_color = 231;
	x = 0;
	while (x <= size)
	{
		write(fd, "\e[48;5;", 7);
		ft_putnbr_fd(edge_color, fd);
		write(fd, "m\03  \e[0m", 8);
		x++;
	}
	y = 0;
	while (y < size)
	{
		x = 0;
		write(fd, "\e[48;5;", 7);
		ft_putnbr_fd(edge_color, fd);
		write(fd, "m\03  \e[0m", 8);
		while (arena[y][x])
		{
			if (arena[y][x] == BLANK)
				write(fd, "  ", 2);
			else if (arena[y][x] == GREY)
				write(fd, "\e[48;5;237m\03  \e[0m", 18);
			else if (arena[y][x] == RED)
				write(fd, "\e[48;5;160m\03  \e[0m", 18);
			else if (arena[y][x] == GREEN)
				write(fd, "\e[48;5;28m\03  \e[0m", 18);
			else if (arena[y][x] == BLUE)
				write(fd, "\e[48;5;20m\03  \e[0m", 18);
			else if (arena[y][x] == YELLOW)
				write(fd, "\e[48;5;226m\03  \e[0m", 18);
			else if (arena[y][x] == WHITE)
				write(fd, "\e[48;5;231m\03  \e[0m", 18);
			x++;
		}
		y++;
		write(fd, "\e[48;5;", 7);
		ft_putnbr_fd(edge_color, fd);
		write(fd, "m\03  \e[0m", 8);
		write(fd, "\n\r", 2);
	}
	x = 0;
	while (x <= size + 1)
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
	char			c[50];

	c [0] = 0;
	read_bytes = 0;
	ready_for_reading = 0;
	gettimeofday(&start, NULL);
	FD_SET(0, &input_set);
	timeout.tv_sec = 0;
	timeout.tv_usec = frame_time;
	ready_for_reading = select(1, &input_set, NULL, NULL, &timeout);
	if (ready_for_reading)
		read_bytes = read(0, c, 50);
	gettimeofday(&stop, NULL);
	ms = (((stop.tv_sec) * 1000 + (stop.tv_usec) / 1000) - ((start.tv_sec) * 1000 + (start.tv_usec) / 1000));
	ms *= 1000;
	usleep(6000 + frame_time - ms);
	return (c[0]);
}

void	engine(int size_w, int size_h, int speed, int edge_color)
{
	char	**arena;
	char	*tmp;
	char	c;
	int		fbuff;
	int		len;

	c = 0;
	(void)size_w;
	arena = make_arena(size_h);
	tmp = malloc(size_h * size_w * 22);
	fclose(fopen(".buff", "w"));
	system("/bin/stty raw");
	while (c != ESC && c != CTRL_Z)
	{
		c = timer(speed);
		game(c, arena, size_h);
		fbuff = open(".buff", O_WRONLY);
		make_frame(size_h, arena, fbuff, edge_color);
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
