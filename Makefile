# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/24 16:00:30 by rpehkone          #+#    #+#              #
#    Updated: 2019/12/13 00:34:16 by rpehkone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	make clean
	gcc -shared engine.c -o engine.dylib
	make snake pacman pong
	/bin/stty raw
	tput civis

snake:
	gcc engine.dylib snake.c -o snake

pacman:
	gcc engine.dylib pacman.c -o pacman

pong:
	gcc engine.dylib pong.c -o pong

clean:
	rm -f engine.dylib
	rm -f snake
	rm -f pacman
	rm -f pong
