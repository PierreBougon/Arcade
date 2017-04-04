##
## Makefile for  in /home/brout_m/rendu/cpp/cpp_arcade
##
## Made by brout_m
## Login   <marc.brout@epitech.eu>
##
## Started on  Tue Mar 14 18:44:56 2017 brout_m
## Last update Tue Apr  4 20:52:32 2017 bougon_p
##

include mk/colors.mk mk/commands.mk mk/definitions.mk

BINARY		=	core/

GRAPHIC_LIB	=	lib/sfml	\
			lib/lapin	\
			lib/ndk

GAMES=
# GAMES		=	games/pacman	\
# 			games/snake

all:
ifeq ($(RELEASE), YES)
	@make -s -C $(BINARY)
	@make -s -C $(GRAPHIC_LIB) DLL=YES
	@make -s -C $(GAMES) DLL=YES
else
	@make -s -C $(BINARY) RELEASE=YES
	@make -s -C $(GRAPHIC_LIB) DLL=YES RELEASE=YES
	@make -s -C $(GAMES) DLL=YES RELEASE=YES
endif

clean:
	@make -s -C core/ clean

fclean:
	@make -s -C core/ fclean

re:	fclean all

.PHONY: make clean fclean re
