/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 15:55:33 by rpehkone          #+#    #+#             */
/*   Updated: 2019/11/24 16:57:34 by rpehkone         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H

# define ENGINE_H
# define CTRL_Z 26
# define ESC 27
# define RED 50
# define GREEN 100
# define BLUE 101
# define GREY 102
# define YELLOW 103
# define WHITE 104
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>

void	game(char c, char **arena, int size);
void	engine(int size);

#endif
