##
## Makefile for Makefile in /home/bougon_p/rendu/TEK2/cpp_arcade
## 
## Made by bougon_p
## Login   <bougon_p@epitech.net>
## 
## Started on  Sun Apr  9 05:18:28 2017 bougon_p
## Last update Sun Apr  9 05:18:42 2017 bougon_p
##

include ../../mk/colors.mk ../../mk/commands.mk ../../mk/definitions.mk

PROJECT_NAME	=	Snake Game

## Core variables

SRC	=	src/Snake.cpp	\
		src/PlayerControlSnake.cpp \

INTERFACE_DIR = ../../interfaces/

INTERFACE_FIL = Color.cpp \

SRC += $(addprefix $(INTERFACE_DIR), $(INTERFACE_FIL))

SRC += $(addprefix $(CORE_DIR), $(CORE_FIL))

COMMON_DIR = ../common/src/

COMMON_FIL = AIControlled.cpp \
             ALivingEntity.cpp \
             DestroyableObject.cpp \
             Entity.cpp \
             LifelessEntity.cpp \
             Map.cpp \
	         Gui.cpp \
	         Score.cpp \
             MapLoader.cpp \
             Sprite.cpp \
             SpriteGenerator.cpp \
             Tile.cpp

SRC += $(addprefix $(COMMON_DIR), $(COMMON_FIL))

OBJ 	=   	$(SRC:.cpp=.o)

NAME    =      	../lib_arcade_snake.so

INC     =       -Iinclude -I../../interfaces -I../include -I../common/include -I../../core/include

## Core rules

include ../../mk/rules.mk
