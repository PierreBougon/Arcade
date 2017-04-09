##
## Makefile for Makefile in /home/bougon_p/rendu/TEK2/cpp_arcade/lib/ndk
##
## Made by bougon_p
## Login   <bougon_p@epitech.net>
##
## Started on  Sun Apr  2 00:43:58 2017 bougon_p
## Last update Fri Apr  7 21:29:32 2017 bougon_p
##

## Include colors and basic commands

PROJECT_NAME	=	NDK Graphic arcade library

include ../../mk/colors.mk ../../mk/commands.mk ../../mk/definitions.mk

## Lib variables

SRC	=	src/Ndk.cpp

OBJ 	=   	$(SRC:.cpp=.o)

NAME    =      	../lib_arcade_ndk.so

INC     =       -Iinclude -I../../interfaces -I../../games/common/include

LDFLAGS	+=	-lncurses

## Lib rules

include ../../mk/rules.mk
