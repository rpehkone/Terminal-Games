/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:01:22 by rpehkone          #+#    #+#             */
/*   Updated: 2020/01/03 15:42:04 by rpehkone         ###   ########.fr       */
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

void	draw_number(char **arena, char x, char y, char num)
{
	switch (num)
	{
		case 0:	arena[x][y] =		GREY;
				 arena[x][y + 1] =	GREY;
				 arena[x][y + 2] =	GREY;
				 arena[x + 1][y] =	GREY;
				 arena[x + 1][y + 1] = BLANK;
				 arena[x + 1][y + 2] = GREY;
				 arena[x + 2][y] =	GREY;
				 arena[x + 2][y + 1] = GREY;
				 arena[x + 2][y + 2] = GREY;
				 break;
		case 1:	arena[x][y] =		BLANK;
				 arena[x][y + 1] =	BLANK;
				 arena[x][y + 2] =	GREY;
				 arena[x + 1][y] =	BLANK;
				 arena[x + 1][y + 1] = BLANK;
				 arena[x + 1][y + 2] = GREY;
				 arena[x + 2][y] =	BLANK;
				 arena[x + 2][y + 1] = BLANK;
				 arena[x + 2][y + 2] = GREY;
				 break;
		case 2:	arena[x][y] =		GREY;
				 arena[x][y + 1] =	GREY;
				 arena[x][y + 2] =	BLANK;
				 arena[x + 1][y] =	BLANK;
				 arena[x + 1][y + 1] = GREY;
				 arena[x + 1][y + 2] = BLANK;
				 arena[x + 2][y] =	BLANK;
				 arena[x + 2][y + 1] = GREY;
				 arena[x + 2][y + 2] = GREY;
				 break;
		case 3:	arena[x][y] =		GREY;
				 arena[x][y + 1] =	GREY;
				 arena[x][y + 2] =	GREY;
				 arena[x + 1][y] =	BLANK;
				 arena[x + 1][y + 1] = BLANK;
				 arena[x + 1][y + 2] = GREY;
				 arena[x + 2][y] =	GREY;
				 arena[x + 2][y + 1] = GREY;
				 arena[x + 2][y + 2] = GREY;
				 break;
		case 4:	arena[x][y] =		GREY;
				 arena[x][y + 1] =	BLANK;
				 arena[x][y + 2] =	GREY;
				 arena[x + 1][y] =	GREY;
				 arena[x + 1][y + 1] = GREY;
				 arena[x + 1][y + 2] = GREY;
				 arena[x + 2][y] =	BLANK;
				 arena[x + 2][y + 1] = BLANK;
				 arena[x + 2][y + 2] = GREY;
				 break;
		case 5:	arena[x][y] =		BLANK;
				 arena[x][y + 1] =	BLANK;
				 arena[x][y + 2] =	BLANK;
				 arena[x + 1][y] =	BLANK;
				 arena[x + 1][y + 1] = BLANK;
				 arena[x + 1][y + 2] = BLANK;
				 arena[x + 2][y] =	BLANK;
				 arena[x + 2][y + 1] = BLANK;
				 arena[x + 2][y + 2] = BLANK;
				 break;
		default: arena[x][y] =		BLANK;
				 arena[x][y + 1] =	BLANK;
				 arena[x][y + 2] =	BLANK;
				 arena[x + 1][y] =	BLANK;
				 arena[x + 1][y + 1] = BLANK;
				 arena[x + 1][y + 2] = BLANK;
				 arena[x + 2][y] =	BLANK;
				 arena[x + 2][y + 1] = BLANK;
				 arena[x + 2][y + 2] = BLANK;
				 break;
	}
}

void	draw_score(char **arena, int size_w, char p1s, char p2s)
{
	draw_number(arena, 2, size_w / 2 - 4, -1);
	draw_number(arena, 2, size_w / 2 + 3, -1);

	draw_number(arena, 2, size_w / 2 - 4, p1s);

	arena[3][size_w / 2] = GREY;
	arena[3][size_w / 2 + 1] = GREY;

	draw_number(arena, 2, size_w / 2 + 3, p2s);
}

int		pong(char c, char ***arena, int size_w, int size_h)
{
	static char first = 1;
	static char p1_y;
	static char p1s = 0;
	static char p2_y;
	static char p2s = 0;
	static char ball_x_pos; 
	static char ball_y_pos;
	static char ball_x_dir; 
	static char ball_y_dir;

	(void)size_h;
	if (first == 1)
	{
		p1_y = size_h / 2;
		p2_y = size_h / 2;
		srand(time(0));
		ball_x_dir = rand() % 2;
		ball_y_dir = rand() % 2;
		if (ball_y_dir == 1)
			ball_y_dir = 2;
		ball_x_pos = size_w / 2;
		ball_y_pos = size_h / 2;
		first = 0;
	}
	arena[0][p1_y - 2][0] = BLANK;
	arena[0][p1_y - 1][0] = BLANK;
	arena[0][p1_y][0] = BLANK;
	arena[0][p1_y + 1][0] = BLANK;
	arena[0][p1_y + 2][0] = BLANK;
	arena[0][p2_y - 2][size_w - 1] = BLANK;
	arena[0][p2_y - 1][size_w - 1] = BLANK;
	arena[0][p2_y][size_w - 1] = BLANK;
	arena[0][p2_y + 1][size_w - 1] = BLANK;
	arena[0][p2_y + 2][size_w - 1] = BLANK;
	arena[0][ball_y_pos][ball_x_pos] = BLANK;
	if (c == 'w')
		p1_y--;
	else if (c == 's')
		p1_y++;
	else if (c == '5')
		p2_y--;
	else if (c == '2')
		p2_y++;
	
	if (p1_y < 2)
		p1_y = 2;
	else if (p1_y > size_h - 3)
		p1_y = size_h - 3;
	if (p2_y < 2)
		p2_y = 2;
	else if (p2_y > size_h - 3)
		p2_y = size_h - 3;

	if (ball_x_pos == 1)
	{
		if (p1_y - 3 == ball_y_pos)
		{
			ball_x_dir = 1;
			if (ball_y_dir < 2)
				ball_y_dir += 1;
		}
		else if (p1_y - 2 == ball_y_pos)
			ball_x_dir = 1;
		else if (p1_y - 1 == ball_y_pos)
			ball_x_dir = 1;
		else if (p1_y == ball_y_pos)
			ball_x_dir = 1;
		else if (p1_y + 1 == ball_y_pos)
			ball_x_dir = 1;
		else if (p1_y + 2 == ball_y_pos)
			ball_x_dir = 1;
		else if (p1_y + 3 == ball_y_pos)
		{
			ball_x_dir = 1;
			if (ball_y_dir > 0)
				ball_y_dir -= 1;
		}
	}
	else if (ball_x_pos == size_w - 2)
	{
		if (p2_y - 3 == ball_y_pos)
		{
			ball_x_dir = 0;
			if (ball_y_dir < 2)
				ball_y_dir += 1;
		}
		else if (p2_y - 2 == ball_y_pos)
			ball_x_dir = 0;
		else if (p2_y - 1 == ball_y_pos)
			ball_x_dir = 0;
		else if (p2_y == ball_y_pos)
			ball_x_dir = 0;
		else if (p2_y + 1 == ball_y_pos)
			ball_x_dir = 0;
		else if (p2_y + 2  == ball_y_pos)
			ball_x_dir = 0;
		else if (p2_y + 3 == ball_y_pos)
		{
			ball_x_dir = 0;
			if (ball_y_dir > 0)
				ball_y_dir -= 1;
		}
	}
	if (ball_y_pos < 2)
		ball_y_dir = 0;
	else if (ball_y_pos > size_h - 2)
		ball_y_dir = 2;
	if (ball_x_dir == 1)
		ball_x_pos++;
	else if (ball_x_dir == 0)
		ball_x_pos--;
	ball_y_pos -= ball_y_dir - 1;
	/*if (arena[p1_y][p1_x] == GREEN || arena[p1_y][p1_x] == RED)
		ft_over("\t\tPLAYER 2 WINS\t\t", GREEN);
	else if (arena[p2_y][p2_x] == RED || arena[p2_y][p2_x] == GREEN)
		ft_over("\t\tPLAYER 1 WINS\t\t", GREEN);*/
	arena[0][p1_y - 2][0] = WHITE;
	arena[0][p1_y - 1][0] = WHITE;
	arena[0][p1_y][0] = WHITE;
	arena[0][p1_y + 1][0] = WHITE;
	arena[0][p1_y + 2][0] = WHITE;
	arena[0][p2_y - 2][size_w - 1] = WHITE;
	arena[0][p2_y - 1][size_w - 1] = WHITE;
	arena[0][p2_y][size_w - 1] = WHITE;
	arena[0][p2_y + 1][size_w - 1] = WHITE;
	arena[0][p2_y + 2][size_w - 1] = WHITE;

	draw_score(arena[0], size_w, p1s, p2s);
	if (ball_x_pos == -1)
		p2s++;
	if (ball_x_pos == size_w)
		p1s++;
	if (ball_x_pos == -1 || ball_x_pos == size_w)
	{
		sleep(1);
		arena[0][p1_y - 2][0] = BLANK;
		arena[0][p1_y - 1][0] = BLANK;
		arena[0][p1_y][0] = BLANK;
		arena[0][p1_y + 1][0] = BLANK;
		arena[0][p1_y + 2][0] = BLANK;
		arena[0][p2_y - 2][size_w - 1] = BLANK;
		arena[0][p2_y - 1][size_w - 1] = BLANK;
		arena[0][p2_y][size_w - 1] = BLANK;
		arena[0][p2_y + 1][size_w - 1] = BLANK;
		arena[0][p2_y + 2][size_w - 1] = BLANK;
		if (ball_x_pos == size_w)
			ball_x_pos--;
		arena[0][ball_y_pos][ball_x_pos] = BLANK;
		first = 1;
	}
	else
		arena[0][ball_y_pos][ball_x_pos] = WHITE; 
	return (1);
}

int		main(void)
{
	// 37, 22 is infinite
	engine(35, 22, 50, GREY, pong);
	return (0);
}
