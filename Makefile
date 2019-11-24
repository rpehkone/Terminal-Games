# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpehkone <rpehkone@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/24 16:00:30 by rpehkone          #+#    #+#              #
#    Updated: 2019/11/24 17:01:22 by rpehkone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -c engine.c engine.h
	ar rc engine.a engine.o
	rm engine.h.gch engine.o
	make snake pacman

snake:
	gcc engine.a snake.c -o snake

pacman:
	gcc engine.a pacman.c -o pacman

clean:
	rm engine.a
	rm snake
	rm pacman
