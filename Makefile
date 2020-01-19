# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/24 16:00:30 by rpehkone          #+#    #+#              #
#    Updated: 2020/01/19 19:47:08 by rpehkone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	make clean
	@gcc -shared engine.c -o engine.dylib
	@make snake pacman pong tetris
	@/bin/stty raw
	@tput civis

snake:
	gcc engine.dylib snake.c -o snake

pacman:
	gcc engine.dylib pacman.c -o pacman

pong:
	gcc engine.dylib pong.c -o pong

tetris:
	gcc engine.dylib tetris.c -o tetris

clean:
	rm -f engine.dylib
	rm -f snake
	rm -f pacman
	rm -f tetris
	rm -f pong
