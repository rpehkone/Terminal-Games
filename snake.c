/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:01:22 by rpehkone          #+#    #+#             */
/*   Updated: 2019/12/13 01:45:30 by rpehkone         ###   ########.fr       */
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
	write(1, "\n\r", 2);
	while (*str)
	{
		c = *str;
		write(1, &c, 1);
		usleep(10000);
		str++;
	}
}

int		snake(char c, char ***arena, int size_w, int size_h)
{
	static char p1_c = 'd';
	static char p1_x = 2;
	static char p1_y = 19;
	static char p1_len = 8;
	static char p2_c = '1';
	static char p2_x = 38;
	static char p2_y = 19;
	static char p2_len = 8;
	static char cherry_x;
	static char cherry_y;
	static char make_cherry = 1;

	if (make_cherry == 1)
	{
		srand(time(0));
		//while (arena[1][cherry_x][cherry_y] > p1_len)
		{
			cherry_x = rand() % size_w;
			cherry_y = rand() % size_w;
		}
		make_cherry = 0;
	}
	if (c == 'w' || c == 'a' || c == 's' || c == 'd')
	{
		if (c == 'w' && p1_c != 's')
			p1_c = c;
		else if (c == 's' && p1_c != 'w')
			p1_c = c;
		else if (c == 'a' && p1_c != 'd')
			p1_c = c;
		else if (c == 'd' && p1_c != 'a')
			p1_c = c;
	}
	else if (c == '5' || c == '1' || c == '2' || c == '3')
	{
		if (c == '5' && p2_c != '2')
			p2_c = c;
		else if (c == '2' && p2_c != '5')
			p2_c = c;
		else if (c == '1' && p2_c != '3')
			p2_c = c;
		else if (c == '3' && p2_c != '1')
			p2_c = c;
	}
	
	if (p1_c == 'w')
		p1_y--;
	else if (p1_c == 'a')
		p1_x--;
	else if (p1_c == 's')
		p1_y++;
	else if (p1_c == 'd')
		p1_x++;
	if (p1_x < 0)
		p1_x = size_w - 1;
	else if (p1_x > size_w - 1)
		p1_x = 0;
	if (p1_y < 0)
		p1_y = size_h - 1;
	else if (p1_y > size_h - 1)
		p1_y = 0;

	if (p2_c == '5')
		p2_y--;
	else if (p2_c == '1')
		p2_x--;
	else if (p2_c == '2')
		p2_y++;
	else if (p2_c == '3')
		p2_x++;
	if (p2_x < 0)
		p2_x = size_w - 1;
	else if (p2_x > size_w - 1)
		p2_x = 0;
	if (p2_y < 0)
		p2_y = size_h - 1;
	else if (p2_y > size_h - 1)
		p2_y = 0;

	if (arena[0][p1_y][p1_x] == RED)
	{
		p1_len += 5;
		make_cherry = 1;
	}
	if (arena[0][p2_y][p2_x] == RED)
	{
		p2_len += 5;
		make_cherry = 1;
	}
	if ((arena[0][p1_y][p1_x] == GREEN || arena[0][p1_y][p1_x] == BLUE) &&
	(arena[0][p2_y][p2_x] == BLUE || arena[0][p2_y][p2_x] == GREEN))
	{
		ft_over("\t\tTIE\t\t", RED);
		p1_c = 'd';
		p1_x = 2;
		p1_y = 19;
		p1_len = 8;
		p2_c = '1';
		p2_x = 38;
		p2_y = 19;
		p2_len = 8;
		return (0);
	}
	if (arena[0][p1_y][p1_x] == GREEN || arena[0][p1_y][p1_x] == BLUE)
	{
		ft_over("\t\tPLAYER 2 WINS\t\t", GREEN);
		p1_c = 'd';
		p1_x = 2;
		p1_y = 19;
		p1_len = 8;
		p2_c = '1';
		p2_x = 38;
		p2_y = 19;
		p2_len = 8;
		return (0);
	}
	else if (arena[0][p2_y][p2_x] == BLUE || arena[0][p2_y][p2_x] == GREEN)
	{
		ft_over("\t\tPLAYER 1 WINS\t\t", BLUE);
		p1_c = 'd';
		p1_x = 2;
		p1_y = 19;
		p1_len = 8;
		p2_c = '1';
		p2_x = 38;
		p2_y = 19;
		p2_len = 8;
		return (0);
	}
	for (int a = 0; a < size_h; a++)
		for (int b = 0; b < size_w; b++)
		{
			if (arena[1][a][b] == 0)
				arena[0][a][b] = BLANK;
			else
				arena[1][a][b]--;
		}
	arena[0][cherry_y][cherry_x] = RED;
	arena[0][p1_y][p1_x] = BLUE;
	arena[1][p1_y][p1_x] = p1_len;
	arena[0][p2_y][p2_x] = GREEN;
	arena[1][p2_y][p2_x] = p2_len;
	return (1);
}

int		main(void)
{
	for (int i = 0; i < 5; i++)
	{
		engine(45, 45, 100000, WHITE, snake);
		sleep(2);
	}
	return (0);
}
