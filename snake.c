/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 15:01:22 by rpehkone          #+#    #+#             */
/*   Updated: 2019/11/24 16:49:42 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

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
	arena[p1_y][p1_x] = RED;
	arena[p2_y][p2_x] = GREEN;
}

int		main(void)
{
	int	size;

	size = 40;
	engine(size);
	printf("GAME OVER");
	return (0);
}
