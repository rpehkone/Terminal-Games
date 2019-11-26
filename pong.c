/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:01:22 by rpehkone          #+#    #+#             */
/*   Updated: 2019/11/26 19:11:19 by rpehkone         ###   ########.fr       */
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

void	game(char c, char **arena, int size)
{
	static char first = 1;
	static char p1_y;
	static char p2_y;
	static char ball_x_pos; 
	static char ball_y_pos;
	static char ball_x_dir; 
	static char ball_y_dir;

	if (first == 1)
	{
		p1_y = size / 2;
		p2_y = size / 2;
		srand(time(0));
		ball_x_dir = rand() % 2;
		ball_y_dir = rand() % 3;
		//ball_y_dir++;
		ball_y_dir = 1;
		ball_x_pos = size / 2;
		ball_y_pos = size / 2;
		first = 0;
	}
	arena[p1_y - 2][0] = BLANK;
	arena[p1_y - 1][0] = BLANK;
	arena[p1_y][0] = BLANK;
	arena[p1_y + 1][0] = BLANK;
	arena[p1_y + 2][0] = BLANK;
	arena[p2_y - 2][size - 1] = BLANK;
	arena[p2_y - 1][size - 1] = BLANK;
	arena[p2_y][size - 1] = BLANK;
	arena[p2_y + 1][size - 1] = BLANK;
	arena[p2_y + 2][size - 1] = BLANK;
	arena[ball_y_pos][ball_x_pos] = BLANK;
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
	else if (p1_y > size - 3)
		p1_y = size - 3;
	if (p2_y < 2)
		p2_y = 2;
	else if (p2_y > size - 3)
		p2_y = size - 3;

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
	else if (ball_x_pos == size - 2)
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
	else if (ball_y_pos > size - 2)
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
	arena[p1_y - 2][0] = WHITE;
	arena[p1_y - 1][0] = WHITE;
	arena[p1_y][0] = WHITE;
	arena[p1_y + 1][0] = WHITE;
	arena[p1_y + 2][0] = WHITE;
	arena[p2_y - 2][size - 1] = WHITE;
	arena[p2_y - 1][size - 1] = WHITE;
	arena[p2_y][size - 1] = WHITE;
	arena[p2_y + 1][size - 1] = WHITE;
	arena[p2_y + 2][size - 1] = WHITE;
	arena[ball_y_pos][ball_x_pos] = WHITE; 

	if (ball_x_pos == -1 || ball_x_pos == size)
	{
		sleep(1);
		arena[p1_y - 2][0] = BLANK;
		arena[p1_y - 1][0] = BLANK;
		arena[p1_y][0] = BLANK;
		arena[p1_y + 1][0] = BLANK;
		arena[p1_y + 2][0] = BLANK;
		arena[p2_y - 2][size - 1] = BLANK;
		arena[p2_y - 1][size - 1] = BLANK;
		arena[p2_y][size - 1] = BLANK;
		arena[p2_y + 1][size - 1] = BLANK;
		arena[p2_y + 2][size - 1] = BLANK;
		arena[ball_y_pos][ball_x_pos] = BLANK;
		first = 1;
	}
}

int		main(void)
{
	engine(50, 70, 30000, WHITE);
	return (0);
}
