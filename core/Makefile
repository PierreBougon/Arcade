##
## Makefile for Makefile in /home/bougon_p/rendu/TEK2/cpp_arcade/core
##
## Made by bougon_p
## Login   <bougon_p@epitech.net>
##
## Started on  Sat Apr  1 13:38:06 2017 bougon_p
## Last update Fri Apr  7 20:39:46 2017 bougon_p
##

## Include colors and basic commands

include ../mk/colors.mk ../mk/commands.mk ../mk/definitions.mk

## Core variables

PROJECT_NAME	=	Core

SRC		=	src/main.cpp				\
			src/Core.cpp				\
			src/Pars.cpp				\
			src/Logger.cpp				\
			../exceptions/src/LoadingExceptions.cpp	\

LDFLAGS 	+=	-ldl

OBJ 		=   	$(SRC:.cpp=.o)

NAME   		=      	../arcade

INC     	=       -Iinclude -I../interfaces -I../include -I../games/common/include -I../exceptions/include

## Core rules

include ../mk/rules.mk
