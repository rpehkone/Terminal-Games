/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 12:00:15 by rpehkone          #+#    #+#             */
/*   Updated: 2019/11/24 20:21:01 by rpehkone         ###   ########.fr       */
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
			arena[i][j] = GREY;
			j++;
		}
		i++;
	}
	return (arena);
}

void	make_frame(char size, char **arena, int fd)
{
	int y;
	int x;

	y = 0;
	while (y < size)
	{
		x = 0;
		while (arena[y][x])
		{
			if (arena[y][x] == GREY)
				write(fd, "\e[48;5;237m\03  \e[0m", 18);
			else if (arena[y][x] == RED)
				write(fd, "\e[48;5;160m\03  \e[0m", 18);
			else if (arena[y][x] == GREEN)
				write(fd, "\e[48;5;028m\03  \e[0m", 18);
			else if (arena[y][x] == BLUE)
				write(fd, "\e[48;5;020m\03  \e[0m", 18);
			else if (arena[y][x] == YELLOW)
				write(fd, "\e[48;5;226m\03  \e[0m", 18);
			else if (arena[y][x] == WHITE)
				write(fd, "\e[48;5;231m\03  \e[0m", 18);
			x++;
		}
		y++;
		write(fd, "\n\r", 2);
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
	//printf ("%d\n", ms);
	usleep(6000 + frame_time - ms);
	return (c[0]);
}

void	engine(int size)
{
	char	**arena;
	char	*tmp;
	char	c;
	int		fbuff;
	int		len;

	c = 0;
	arena = make_arena(size);
	tmp = malloc(size * size * 6);
	fclose(fopen(".buff", "w"));
	system("/bin/stty raw");
	while (c != ESC && c != CTRL_Z)
	{
		game(c, arena, size);
		fbuff = open(".buff", O_WRONLY);
		make_frame(size, arena, fbuff);
		close(fbuff);
		fbuff = open(".buff", O_RDONLY);
		write(1, "\e[1;1H\e[2J", 10);
		while ((len = read(fbuff, tmp, (size * size * 6))) > 0)
			write(1, tmp, len);
		close(fbuff);
		c = timer(300000);
	}
	remove(".buff");
	system("/bin/stty cooked");
}
