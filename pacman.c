/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pacman.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:50:31 by rpehkone          #+#    #+#             */
/*   Updated: 2019/11/24 17:11:09 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	game(char c, char **arena, int size)
{
	static char p1_c = 'd';
	static char p1_x = 2;
	static char p1_y = 19;
	static char ghost1_c = '1';
	static char ghost1_x = 38;
	static char ghost1_y = 19;

	arena[p1_y][p1_x] = GREY;
	arena[ghost1_y][ghost1_x] = GREY;
	if (c == 'w' || c == 'a' || c == 's' || c == 'd')
	{
		if (c == 'w')
			p1_c = c;
		else if (c == 's')
			p1_c = c;
		else if (c == 'a')
			p1_c = c;
		else if (c == 'd')
			p1_c = c;
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
	if (ghost1_x > p1_x)
		ghost1_x--;
	if (ghost1_y > p1_y)
		ghost1_y--;
	if (ghost1_x < p1_x)
		ghost1_x++;
	if (ghost1_y < p1_y)
		ghost1_y++;

	arena[p1_y][p1_x] = YELLOW;
	arena[ghost1_y][ghost1_x] = RED;
}

int		main(void)
{
	int	size;

	size = 40;
	engine(size);
	printf("GAME OVER");
	return (0);
}
