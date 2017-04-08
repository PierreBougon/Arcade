##
## Makefile for Makefile in /home/bougon_p/rendu/TEK2/cpp_arcade/lib/lapin
##
## Made by bougon_p
## Login   <bougon_p@epitech.net>
##
## Started on  Sun Apr  2 00:44:40 2017 bougon_p
## Last update Sat Apr  8 18:23:05 2017 brout_m
##

## Include colors and basic commands

include ../../mk/colors.mk ../../mk/commands.mk ../../mk/definitions.mk

PROJECT_NAME	=	Lapin Graphic arcade library

## Lib variables

SRC		=	src/Lapin.cpp \
			../../interfaces/Color.cpp \
			../../interfaces/Sound.cpp \
			../../exceptions/src/LoadingExceptions.cpp

OBJ 		=   	$(SRC:.cpp=.o)

NAME    	=      	../lib_arcade_lapin.so

INC     	=       -Iinclude \
			-I../../interfaces \
			-I../../soundManager/include \
			-I../../exceptions/include \
			-I./dep/ \
			-I./dep/deps \
			-I./dep/SFML-2.3/include

LDFLAGS		+=	-L./dep/lib -llapin -l_sound_manager \
			-L./dep/SFML-2.3/lib \
			-lsfml-audio -lsfml-graphics -lsfml-system -lsfml-window \
			-lm

## Lib rules

include ../../mk/rules.mk
