# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/24 16:00:30 by rpehkone          #+#    #+#              #
#    Updated: 2019/11/26 21:00:10 by rpehkone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	make clean
	gcc -c engine.c engine.h
	ar rc engine.a engine.o
	rm engine.h.gch engine.o
	make snake pacman pong
	/bin/stty raw
	tput civis

snake:
	gcc engine.a snake.c -o snake

pacman:
	gcc engine.a pacman.c -o pacman

pong:
	gcc engine.a pong.c -o pong

clean:
	rm -f engine.a
	rm -f snake
	rm -f pacman
	rm -f pong
