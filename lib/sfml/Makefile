##
## Makefile for Makefile in /home/bougon_p/rendu/TEK2/cpp_arcade/lib/sfml
## 
## Made by bougon_p
## Login   <bougon_p@epitech.net>
## 
## Started on  Sun Apr  2 00:32:42 2017 bougon_p
## Last update Sun Apr  9 20:40:13 2017 bougon_p
##

## Include colors and basic commands

include ../../mk/colors.mk ../../mk/commands.mk ../../mk/definitions.mk

PROJECT_NAME	=	SFML Graphic arcade library

## Lib variab

SRC	=	src/SFMLCore.cpp		\
		src/GfxSprite.cpp		\
		../../interfaces/Sound.cpp	\
		../../interfaces/Color.cpp

OBJ 	=   	$(SRC:.cpp=.o)

NAME    =      	../lib_arcade_sfml.so

INC     =       -Iinclude \
		-I../../interfaces \
		-I../../soundManager/include \
		-I../lapin/dep/SFML-2.3/include

LDFLAGS	+=	-L../lapin/dep/SFML-2.3/lib/	\
		-lsfml-graphics			\
		-lsfml-window			\
		-lsfml-system			\
		-lsfml-audio			\
		-L../../soundManager		\
		-l_sound_manager

## Lib rules

include ../../mk/rules.mk
