/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:01:22 by rpehkone          #+#    #+#             */
/*   Updated: 2020/01/18 12:01:14 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	ft_over(char *str, int color)
{
	char c;

	if (color == GREY)
		write(1, "\e[48;5;237m\03", 12);
	else if (color == RED)
		write(1, "\e[48;5;160m\03", 12);
	else if (color == GREEN)
		write(1, "\e[48;5;028m\03", 12);
	else if (color == BLUE)
		write(1, "\e[48;5;020m\03", 12);
	else if (color == YELLOW)
		write(1, "\e[48;5;226m\03", 12);
	else if (color == WHITE)
		write(1, "\e[48;5;231m\03", 12);
	else if (color == LIGHT_BLUE)
		write(1, "\e[48;5;033m\03", 12);
	while (*str)
	{
		c = *str;
		write(1, &c, 1);
		usleep(10000);
		str++;
	}
	remove(".buff");
	system("/bin/stty cooked");
	exit(0);
}

void	put_tetromino(int x, int y, int tet_num, char ***arena, int clear, int rotation)
{
	int i = 0;
	int color;
	char tetromino[7][17] =
				   {".....XX..XX.....",
					"....XXXX........",
					".....XX...XX....",
					"......XX.XX.....",
					"....XXX..X......",
					"....XXX.X.......",
					"....XXX...X....."};

	if (clear == 1)
		color = BLANK;
	else
	{
		if (tet_num == 0)
			color = RED;
		if (tet_num == 1)
			color = GREEN;
		if (tet_num == 2)
			color = BLUE;
		if (tet_num == 3)
			color = YELLOW;
		if (tet_num == 4)
			color = WHITE;
		if (tet_num == 5)
			color = GREY;
		if (tet_num == 6)
			color = BLACK;
	}
	if (rotation == 0)
	{
		while (tetromino[tet_num][i])
		{
			if (tetromino[tet_num][i] == 'X')
				arena[0][y + (i / 4)][x + (i % 4)] = color;
				//arena[0][y + (i / 4)][x + i - (i / 4 * 4)] = color;
			i++;
		}
	}
	if (rotation == 1)
	{
		while (tetromino[tet_num][i])
		{
			if (tetromino[tet_num][i] == 'X')
				arena[0][y + (i % 4)][x + (i / 4)] = color;
			i++;
		}
	}
	if (rotation == 2)
	{
		while (tetromino[tet_num][i])
		{
			if (tetromino[tet_num][i] == 'X')
				arena[0][y - (i / 4)][x + (i % 4)] = color;
				//arena[0][y + (i / 4)][x + i - (i / 4 * 4)] = color;
			i++;
		}
	}
	if (rotation == 3)
	{
		while (tetromino[tet_num][i])
		{
			if (tetromino[tet_num][i] == 'X')
				arena[0][y - (i % 4)][x - (i / 4)] = color;
				//arena[0][y + (i / 4)][x + (i % 4)] = color;
			i++;
		}
	}
}

int		tetris(char c, char ***arena, int size_w, int size_h)
{
	(void)size_h;
	static char x = -1;
	static char y = 3;
	static int	tet_num = 0;
	static int	timer = 0;
	static int	rotation = 0;

	if (x < 0)
		x = size_w / 2;
	put_tetromino(x, y, tet_num, arena, 1, rotation);

	timer++;
	if (timer == 10)
	{
		y++;
		timer = 0;
	}
	if (c == '5')
		tet_num++;
	else if (c == '2')
		tet_num--;
	else if (c == 'w')
	{
		rotation--;
		if (rotation == -1)
			rotation = 3;
	}
	else if (c == 's')
	{
		rotation++;
		if (rotation == 4)
			rotation = 0;
	}
	else if (c == 'a' && x > 0)
		x--;
	else if (c == 'd' && x < size_w - 4)
		x++;

	put_tetromino(x, y, tet_num, arena, 0, rotation);
	return (1);
}

int		main(void)
{
	engine(25, 40, 50, BLUE, tetris);
	return (0);
}
