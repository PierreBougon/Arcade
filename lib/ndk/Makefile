##
## Makefile for Makefile in /home/bougon_p/rendu/TEK2/cpp_arcade/lib/ndk
##
## Made by bougon_p
## Login   <bougon_p@epitech.net>
##
## Started on  Sun Apr  2 00:43:58 2017 bougon_p
## Last update Sun Apr  9 05:20:03 2017 bougon_p
##

## Include colors and basic commands

PROJECT_NAME	=	ndk

include ../../mk/colors.mk ../../mk/commands.mk ../../mk/definitions.mk

## Lib variables

SRC	=	src/Ndk.cpp			\
		../../interfaces/Sound.cpp

OBJ 	=   	$(SRC:.cpp=.o)

NAME    =      	../lib_arcade_ndk.so

INC     =       -Iinclude -I../../interfaces -I../../games/common/include

LDFLAGS	+=	-lncurses

## Lib rules

include ../../mk/rules.mk
