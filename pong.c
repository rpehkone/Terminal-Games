/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:01:22 by rpehkone          #+#    #+#             */
/*   Updated: 2019/11/24 21:36:04 by rpehkone         ###   ########.fr       */
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
	static char p1_y = 9;
	static char p2_y = 9;

	arena[p1_y - 1][0] = GREY;
	arena[p1_y][0] = GREY;
	arena[p1_y + 1][0] = GREY;
	arena[p2_y - 1][size - 1] = GREY;
	arena[p2_y][size - 1] = GREY;
	arena[p2_y + 1][size - 1] = GREY;
	if (c == 'w')
		p1_y--;
	else if (c == 's')
		p1_y++;
	else if (c == '5')
		p2_y--;
	else if (c == '2')
		p2_y++;
	
	if (p1_y < 1)
		p1_y = 1;
	else if (p1_y > size - 2)
		p1_y = size - 2;
	if (p2_y < 1)
		p2_y = 1;
	else if (p2_y > size - 2)
		p2_y = size - 2;

	/*if (arena[p1_y][p1_x] == GREEN || arena[p1_y][p1_x] == RED)
		ft_over("\t\tPLAYER 2 WINS\t\t", GREEN);
	else if (arena[p2_y][p2_x] == RED || arena[p2_y][p2_x] == GREEN)
		ft_over("\t\tPLAYER 1 WINS\t\t", GREEN);*/
	arena[p1_y - 1][0] = WHITE;
	arena[p1_y][0] = WHITE;
	arena[p1_y + 1][0] = WHITE;
	arena[p2_y - 1][size - 1] = WHITE;
	arena[p2_y][size - 1] = WHITE;
	arena[p2_y + 1][size - 1] = WHITE;
}

int		main(void)
{
	engine(20, 105000);
	return (0);
}
