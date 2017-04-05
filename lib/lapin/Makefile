##
## Makefile for Makefile in /home/bougon_p/rendu/TEK2/cpp_arcade/lib/lapin
## 
## Made by bougon_p
## Login   <bougon_p@epitech.net>
## 
## Started on  Sun Apr  2 00:44:40 2017 bougon_p
## Last update Sun Apr  2 00:47:13 2017 bougon_p
##

## Include colors and basic commands

include ../../mk/colors.mk ../../mk/commands.mk ../../mk/definitions.mk

## Lib variables

SRC			=		src/Lapin.cpp \
					../../interfaces/Color.cpp \
					../../interfaces/Sound.cpp

OBJ 		=   	$(SRC:.cpp=.o)

NAME    	=      	../lib_arcade_lapin.so

INC     	=       -Iinclude \
					-I../../interfaces \
					-I./dep/ -I./dep/deps \
					-L./dep/lib \
					-llapin -lusb-1.0 \
					-L../sfml/SFML-2.4.2/dep/lib \
					-lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window \
					-Wl,--allow-shlib-undefined
## Lib rules

include ../../mk/rules.mk