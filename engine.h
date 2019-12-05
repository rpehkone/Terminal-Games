/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 15:55:33 by rpehkone          #+#    #+#             */
/*   Updated: 2019/12/05 14:05:45 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H

# define ENGINE_H
# define CTRL_Z 26
# define ESC 27
# define BLANK 1
# define RED 124
# define GREEN 28
# define BLUE 27
# define GREY 59
# define YELLOW 94
# define WHITE 102
# define LIGHT_BLUE 39
# define YELLOW_DOT 106
# define BLUE_LINE_H 107
# define BLUE_LINE_V 108
# define PACMAN_L 109
# define PACMAN_U 110
# define PACMAN_D 111
# define PACMAN_R 112
# define PACMAN_O 113
# define BLACK 114
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

int		game(char c, char ***arena, int size_w, int size_h);
void	engine(int size_w, int size_h, int speed, int edge_color);

#endif
