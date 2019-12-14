/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pacman.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 16:50:31 by rpehkone          #+#    #+#             */
/*   Updated: 2019/12/14 15:31:12 by rpehkone         ###   ########.fr       */
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
		arena[1][x] = BLUE_LINE_H;
		arena[3][x] = BLUE_LINE_H;
		arena[5][x] = BLUE_LINE_H;
		arena[6][x] = BLUE_LINE_H;
		arena[8][x] = BLUE_LINE_H;
		arena[11][x] = BLUE_LINE_H;

		arena[15][x] = BLUE_LINE_H;
		arena[18][x] = BLUE_LINE_H;
		arena[20][x] = BLUE_LINE_H;
		arena[21][x] = BLUE_LINE_H;
		arena[23][x] = BLUE_LINE_H;
		arena[24][x] = BLUE_LINE_H;
		arena[26][x] = BLUE_LINE_H;
		arena[27][x] = BLUE_LINE_H;
		x++;
	}
	while (y < size_h)
	{
		arena[y][4] = BLUE_LINE_V;
		arena[y][6] = BLUE_LINE_V;
		arena[y][7] = BLUE_LINE_V;
		arena[y][12] = BLUE_LINE_V;
		arena[y][13] = BLUE_LINE_V;
		arena[y][18] = BLUE_LINE_V;
		arena[y][19] = BLUE_LINE_V;
		arena[y][21] = BLUE_LINE_V;
		y++;
	}
	x = 0;
	while (x < size_w)
	{
		arena[0][x] = BLANK;
		arena[4][x] = BLANK;
		arena[13][x] = BLANK;
		arena[20][x] = BLANK;
		arena[25][x] = BLANK;
		arena[28][x] = BLANK;
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
	arena[0][12] = BLUE_LINE_V;
	arena[0][13] = BLUE_LINE_V;
	arena[1][11] = BLANK;
	arena[1][14] = BLANK;
	arena[3][11] = BLANK;
	arena[3][14] = BLANK;
	arena[2][1] = BLUE_LINE_V;
	arena[2][24] = BLUE_LINE_V;
	arena[2][10] = BLUE_LINE_V;
	arena[2][15] = BLUE_LINE_V;
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

	arena[12][13] = BLANK;
	arena[12][12] = BLANK;

	arena[12][16] = BLUE;
	arena[12][9] = BLUE;
	arena[13][16] = BLUE;
	arena[13][9] = BLUE;
	arena[14][16] = BLUE;
	arena[14][9] = BLUE;

	arena[15][17] = BLANK;
	arena[15][8] = BLANK;

	arena[14][12] = BLANK;
	arena[14][13] = BLANK;

	arena[10][12] = BLANK;
	arena[10][13] = BLANK;

	arena[16][12] = BLANK;
	arena[16][13] = BLANK;

	arena[18][8] = BLANK;
	arena[18][17] = BLANK;

	arena[19][4] = BLANK;
	arena[19][6] = BLANK;
	arena[19][7] = BLANK;
	arena[19][18] = BLANK;
	arena[19][19] = BLANK;
	arena[19][21] = BLANK;

	arena[20][4] = BLUE;
	arena[20][6] = BLUE;
	arena[20][7] = BLUE;
	arena[20][18] = BLUE;
	arena[20][19] = BLUE;
	arena[20][21] = BLUE;

	arena[17][9] = BLUE;
	arena[17][10] = BLUE;
	arena[17][11] = BLUE;
	arena[17][14] = BLUE;
	arena[17][15] = BLUE;
	arena[17][16] = BLUE;

	arena[20][15] = BLUE;
	arena[20][16] = BLUE;
	arena[20][17] = BLUE;

	arena[20][8] = BLUE;
	arena[20][9] = BLUE;
	arena[20][10] = BLUE;

	arena[20][12] = BLUE;
	arena[20][13] = BLUE;

	arena[18][0] = BLUE;
	arena[18][25] = BLUE;

	arena[21][11] = BLANK;
	arena[22][12] = BLANK;
	arena[22][13] = BLANK;
	arena[21][14] = BLANK;

	arena[22][6] = BLANK;
	arena[22][7] = BLANK;
	arena[22][18] = BLANK;
	arena[22][19] = BLANK;

	arena[20][1] = BLUE;
	arena[20][2] = BLUE;
	arena[20][3] = BLUE;

	arena[20][22] = BLUE;
	arena[20][23] = BLUE;
	arena[20][24] = BLUE;

	arena[26][5] = BLUE;
	arena[27][5] = BLUE;

	arena[26][20] = BLUE;
	arena[27][20] = BLUE;

	arena[26][14] = BLANK;
	arena[27][14] = BLANK;

	arena[26][11] = BLANK;
	arena[27][11] = BLANK;

	arena[25][12] = BLUE;
	arena[25][13] = BLUE;

	arena[25][19] = BLUE;
	arena[25][18] = BLUE;
	arena[25][6] = BLUE;
	arena[25][7] = BLUE;

	arena[24][17] = BLANK;
	arena[23][17] = BLANK;
	arena[24][8] = BLANK;
	arena[23][8] = BLANK;

	arena[24][0] = BLUE;
	arena[23][0] = BLUE;
	arena[24][25] = BLUE;
	arena[23][25] = BLUE;

	arena[24][2] = BLANK;
	arena[23][2] = BLANK;
	arena[24][23] = BLANK;
	arena[23][23] = BLANK;

	arena[22][1] = BLANK;
	arena[22][3] = BLUE;
	arena[22][22] = BLUE;
	arena[22][24] = BLANK;

	y = 0;
	while (y < size_h)
	{
		x = 0;
		while (x < size_w)
		{
			if (arena[y][x] == BLANK)
				arena[y][x] = BLACK;
			//if (arena[y][x] == BLUE)
			//	arena[y][x] = BLUE_LINE_V;
			//if (arena[y][x] == BLUE_LINE_V)
			//	arena[y][x] = BLUE;
			//if (arena[y][x] == BLUE_LINE_H)
			//	arena[y][x] = BLUE;
			x++;
		}
		y++;
	}
}

void	edit_arena2(char **arena, int size_w, int size_h)
{
	int x;
	int y;

	y = 0;
	while (y < size_h)
	{
		x = 0;
		while (x < size_w)
		{
			arena[y][x] = YELLOW;
			x++;
		}
		y++;
	}
}
int		game(char c, char ***arena, int size_w, int size_h)
{
	static int	first = 1;
	static int	mouth = 0;
	static int	frame = 0;
	static char p1_c = 'a';
	static char p1_c_old  = 'a';
	static char p1_x = 14;
	static char p1_y = 16;
//	static char ghost1_c = '1';
//	static char ghost1_x = 38;
//	static char ghost1_y = 19;

	if (first == 1)
	{
		first = 0;
		edit_arena(arena[0], size_w, size_h);
		edit_arena2(arena[1], size_w, size_h);
	}
	arena[2][p1_y][p1_x] = BLANK;
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

	if (frame == 2)
	{
		if (p1_c == 'w' && arena[0][p1_y - 1][p1_x] != BLUE_LINE_V &&
				arena[0][p1_y - 1][p1_x] != BLUE_LINE_H)
		{
			p1_c_old = p1_c;
			p1_y--;
		}
		else if (p1_c == 'a' && arena[0][p1_y][p1_x - 1] != BLUE_LINE_V &&
				arena[0][p1_y][p1_x - 1] != BLUE_LINE_H)
		{
			p1_c_old = p1_c;
			p1_x--;
		}
		else if (p1_c == 's' && arena[0][p1_y + 1][p1_x] != BLUE_LINE_V &&
				arena[0][p1_y + 1][p1_x] != BLUE_LINE_H)
		{
			p1_c_old = p1_c;
			p1_y++;
		}
		else if (p1_c == 'd' && arena[0][p1_y][p1_x + 1] != BLUE_LINE_V &&
				arena[0][p1_y][p1_x + 1] != BLUE_LINE_H)
		{
			p1_c_old = p1_c;
			p1_x++;
		}
		else if (p1_c_old == 'w' && arena[0][p1_y - 1][p1_x] != BLUE_LINE_V &&
				arena[0][p1_y - 1][p1_x] != BLUE_LINE_H)
			p1_y--;
		else if (p1_c_old == 'a' && arena[0][p1_y][p1_x - 1] != BLUE_LINE_V &&
				arena[0][p1_y][p1_x - 1] != BLUE_LINE_H)
			p1_x--;
		else if (p1_c_old == 's' && arena[0][p1_y + 1][p1_x] != BLUE_LINE_V &&
				arena[0][p1_y + 1][p1_x] != BLUE_LINE_H)
			p1_y++;
		else if (p1_c_old == 'd' && arena[0][p1_y][p1_x + 1] != BLUE_LINE_V &&
				arena[0][p1_y][p1_x + 1] != BLUE_LINE_H)
			p1_x++;
		if (p1_x < 0)
			p1_x = size_w - 1;
		else if (p1_x > size_w - 1)
			p1_x = 0;
		if (p1_y < 0)
			p1_y = size_h - 1;
		else if (p1_y > size_h - 1)
			p1_y = 0;
		frame = 0;
	}
	frame++;
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
		if (p1_c_old == 'w')
			arena[2][p1_y][p1_x] = 'v';
		else if (p1_c_old == 'a')
			arena[2][p1_y][p1_x] = '>';
		else if (p1_c_old == 's')
			arena[2][p1_y][p1_x] = '^';
		else if (p1_c_old == 'd')
			arena[2][p1_y][p1_x] = '<';
		mouth = 0;
	}
	else
	{
		//arena[0][p1_y][p1_x] = RED;
		arena[2][p1_y][p1_x] = 'o';
	}
	mouth++;
//	arena[ghost1_y][ghost1_x] = RED;
	return (1);
}

/*
	// ⬤\
	// ᗢ
	// ᗣ
	// ᗧ
	// ᗤ
	//━━
	// ┃
	//┗
	//┛
	//┓
	//┏
	//ᗣ
*/
int		main(void)
{
	engine(26, 29, 200, BLANK, game);
	printf("GAME OVER");
	return (0);
}
