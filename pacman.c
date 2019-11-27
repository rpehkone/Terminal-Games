/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pacman.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:50:31 by rpehkone          #+#    #+#             */
/*   Updated: 2019/11/27 13:54:47 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void	edit_arena(char **arena, int size_w, int size_h)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (x < size_w)
	{
		arena[1][x] = BLUE;
		arena[3][x] = BLUE;
		arena[5][x] = BLUE;
		arena[6][x] = BLUE;
		arena[8][x] = BLUE;
		arena[11][x] = BLUE;

		arena[15][x] = BLUE;
		arena[18][x] = BLUE;
		arena[20][x] = BLUE;
		arena[22][x] = BLUE;
		arena[24][x] = BLUE;
		x++;
	}
	while (y < size_h)
	{
		arena[y][4] = BLUE;
		arena[y][6] = BLUE;
		arena[y][7] = BLUE;
		arena[y][12] = BLUE;
		arena[y][13] = BLUE;
		arena[y][18] = BLUE;
		arena[y][19] = BLUE;
		arena[y][21] = BLUE;
		y++;
	}
	x = 0;
	while (x < size_w)
	{
		arena[0][x] = BLANK;
		arena[4][x] = BLANK;
		arena[13][x] = BLANK;
		arena[20][x] = BLANK;
		arena[24][x] = BLANK;
		x++;
	}
	y = 0;
	while (y < size_h)
	{
		arena[y][0] = BLANK;
		arena[y][5] = BLANK;
		arena[y][20] = BLANK;
		arena[y][25] = BLANK;
		y++;
	}
	arena[0][12] = BLUE;
	arena[0][13] = BLUE;
	arena[1][11] = BLANK;
	arena[1][14] = BLANK;
	arena[3][11] = BLANK;
	arena[3][14] = BLANK;
	arena[2][1] = BLUE;
	arena[2][24] = BLUE;
	arena[2][10] = BLUE;
	arena[2][15] = BLUE;
	arena[2][7] = BLANK;
	arena[2][18] = BLANK;

	arena[11][1] = BLANK;
	arena[11][2] = BLANK;
	arena[11][3] = BLANK;
	arena[11][8] = BLANK;
	arena[11][17] = BLANK;
	arena[11][22] = BLANK;
	arena[11][23] = BLANK;
	arena[11][24] = BLANK;

	arena[12][0] = BLUE;
	arena[12][1] = BLUE;
	arena[12][2] = BLUE;
	arena[12][3] = BLUE;
	arena[12][22] = BLUE;
	arena[12][23] = BLUE;
	arena[12][24] = BLUE;
	arena[12][25] = BLUE;

	arena[14][0] = BLUE;
	arena[14][1] = BLUE;
	arena[14][2] = BLUE;
	arena[14][3] = BLUE;
	arena[14][22] = BLUE;
	arena[14][23] = BLUE;
	arena[14][24] = BLUE;
	arena[14][25] = BLUE;

	arena[15][1] = BLANK;
	arena[15][2] = BLANK;
	arena[15][3] = BLANK;
	arena[15][22] = BLANK;
	arena[15][23] = BLANK;
	arena[15][24] = BLANK;

	arena[8][0] = BLUE;
	arena[8][25] = BLUE;
	arena[6][1] = BLUE;
	arena[6][24] = BLUE;
	arena[7][4] = BLANK;
	arena[7][21] = BLANK;
	arena[5][8] = BLANK;
	arena[6][8] = BLANK;
	arena[5][17] = BLANK;
	arena[6][17] = BLANK;
	arena[8][14] = BLANK;
	arena[8][11] = BLANK;

	arena[18][1] = BLUE;
	arena[18][24] = BLUE;
	arena[22][1] = BLUE;
	arena[22][24] = BLUE;
	arena[9][8] = BLUE;
	arena[9][9] = BLUE;
	arena[9][10] = BLUE;
	arena[9][15] = BLUE;
	arena[9][16] = BLUE;
	arena[9][17] = BLUE;
	y = 0;
	while (y < size_h)
	{
		x = 0;
		while (x < size_w)
		{
			if (arena[y][x] == BLANK)
				arena[y][x] = YELLOW_DOT;
			if (arena[y][x] == BLUE)
				arena[y][x] = BLUE_LINE_V;
			x++;
		}
		y++;

	}

}

int		game(char c, char **arena, int size_w, int size_h)
{
	static int	first = 1;
	static int	mouth = 0;
	static char p1_c = 'a';
	static char p1_x = 14;
	static char p1_y = 20;
//	static char ghost1_c = '1';
//	static char ghost1_x = 38;
//	static char ghost1_y = 19;

	if (first == 1)
	{
		first = 0;
		edit_arena(arena, size_w, size_h);
	}
	arena[p1_y][p1_x] = BLANK;
//	arena[ghost1_y][ghost1_x] = BLANK;
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
		p1_x = size_w - 1;
	else if (p1_x > size_w - 1)
		p1_x = 0;
	if (p1_y < 0)
		p1_y = size_w - 1;
	else if (p1_y > size_w - 1)
		p1_y = 0;
/*	if (ghost1_x > p1_x)
		ghost1_x--;
	if (ghost1_y > p1_y)
		ghost1_y--;
	if (ghost1_x < p1_x)
		ghost1_x++;
	if (ghost1_y < p1_y)
		ghost1_y++;
*/
	if (mouth == 2)
	{
		if (p1_c == 'w')
			arena[p1_y][p1_x] = PACMAN_U;
		else if (p1_c == 'a')
			arena[p1_y][p1_x] = PACMAN_L;
		else if (p1_c == 's')
			arena[p1_y][p1_x] = PACMAN_D;
		else if (p1_c == 'd')
			arena[p1_y][p1_x] = PACMAN_R;
		mouth = 0;
	}
	else
		arena[p1_y][p1_x] = PACMAN_O;
	mouth++;
//	arena[ghost1_y][ghost1_x] = RED;
	return (0);
}

int		main(void)
{
	engine(26, 30, 200000, BLANK);
	printf("GAME OVER");
	return (0);
}
