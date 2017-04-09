##
## Makefile for Makefile in /home/bougon_p/rendu/TEK2/cpp_arcade/soundManager
## 
## Made by bougon_p
## Login   <bougon_p@epitech.net>
## 
## Started on  Wed Apr  5 21:11:25 2017 bougon_p
## Last update Sun Apr  9 23:17:38 2017 bougon_p
##

## Include colors and basic commands

include ../mk/colors.mk ../mk/commands.mk ../mk/definitions.mk


PROJECT_NAME	=	Sound Manager

## Lib variab


SRC	=	src/SoundManager.cpp	\
		src/SoundRender.cpp	\
		../interfaces/Sound.cpp	\
		../core/src/Logger.cpp

OBJ 	=   	$(SRC:.cpp=.o)

NAME    =      	lib_sound_manager.a

INC     =       -Iinclude -I../interfaces -I../core/include

LDFLAGS	+=	-L../lib/sfml/dep/SFML/    \
                -lsfml-graphics \
		-lsfml-window   \
                -lsfml-system	\
		-lsfml-audio

## Lib rules

include ../mk/rules.mk
