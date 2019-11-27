/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 15:55:33 by rpehkone          #+#    #+#             */
/*   Updated: 2019/11/27 13:55:45 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H

# define ENGINE_H
# define CTRL_Z 26
# define ESC 27
# define BLANK 1
# define RED 50
# define GREEN 100
# define BLUE 101
# define GREY 102
# define YELLOW 103
# define WHITE 104
# define LIGHT_BLUE 105
# define YELLOW_DOT 106
# define BLUE_LINE_V 107
# define PACMAN_R 108
# define PACMAN_L 109
# define PACMAN_U 110
# define PACMAN_D 111
# define PACMAN_O 112
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

int		game(char c, char **arena, int size_w, int size_h);
void	engine(int size_w, int size_h, int speed, int edge_color);

#endif
