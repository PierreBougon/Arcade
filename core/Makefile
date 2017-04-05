##
## Makefile for Makefile in /home/bougon_p/rendu/TEK2/cpp_arcade/core
## 
## Made by bougon_p
## Login   <bougon_p@epitech.net>
## 
## Started on  Sat Apr  1 13:38:06 2017 bougon_p
## Last update Tue Apr  4 23:01:10 2017 bougon_p
##

## Include colors and basic commands

include ../mk/colors.mk ../mk/commands.mk ../mk/definitions.mk

## Core variables

PROJECT_NAME	=	Core

SRC		=	src/main.cpp	\
			src/Core.cpp	\
			src/Pars.cpp	\
			src/Logger.cpp

LDFLAGS 	+=	-ldl

OBJ 		=   	$(SRC:.cpp=.o)

NAME   		=      	../arcade

INC     	=       -Iinclude -I../ArcadeInterfaces -I../include -I../games/common/include

## Core rules

include ../mk/rules.mk
