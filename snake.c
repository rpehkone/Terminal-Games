/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:01:22 by rpehkone          #+#    #+#             */
/*   Updated: 2019/11/26 19:12:45 by rpehkone         ###   ########.fr       */
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
	static char p1_c = 'd';
	static char p1_x = 2;
	static char p1_y = 19;
	static char p2_c = '1';
	static char p2_x = 38;
	static char p2_y = 19;

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
		p1_x = size - 1;
	else if (p1_x > size - 1)
		p1_x = 0;
	if (p1_y < 0)
		p1_y = size - 1;
	else if (p1_y > size - 1)
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
		p2_x = size - 1;
	else if (p2_x > size - 1)
		p2_x = 0;
	if (p2_y < 0)
		p2_y = size - 1;
	else if (p2_y > size - 1)
		p2_y = 0;

	if (p1_y == p2_y && p1_x == p2_x)
		ft_over("\t\tTIE\t\t", LIGHT_BLUE);
	if (arena[p1_y][p1_x] == GREEN || arena[p1_y][p1_x] == RED)
		ft_over("\t\tPLAYER 2 WINS\t\t", GREEN);
	else if (arena[p2_y][p2_x] == RED || arena[p2_y][p2_x] == GREEN)
		ft_over("\t\tPLAYER 1 WINS\t\t", GREEN);
	arena[p1_y][p1_x] = RED;
	arena[p2_y][p2_x] = GREEN;
}

int		main(void)
{
	engine(40, 40, 200000, BLUE);
	return (0);
}
