##
## Makefile for  in /home/brout_m/rendu/cpp/cpp_arcade
##
## Made by brout_m
## Login   <marc.brout@epitech.eu>
##
## Started on  Tue Mar 14 18:44:56 2017 brout_m
## Last update Sat Apr  8 18:47:11 2017 brout_m
##

include mk/colors.mk mk/commands.mk mk/definitions.mk

BINARY		=	core/

SFML		=	lib/sfml

LAPIN		=	lib/lapin

NDK		=	lib/ndk

SOUND		=	soundManager

CENTIPEDE	=	games/centipede	\

SNAKE		=	games/snake	\

all:
ifeq ($(RELEASE), NO)
	make -s -C $(BINARY)
else
	make -s -C $(BINARY) RELEASE=YES
endif

lib:	fcleanlib
ifeq ($(RELEASE), NO)
	make -s -C $(SOUND) DLL=YES
	make -s -C $(SFML) DLL=YES
	make -s -C $(LAPIN) DLL=YES
	make -s -C $(NDK) DLL=YES
	make -s -C $(CENTIPEDE) DLL=YES
	make -s -C $(SNAKE) DLL=YES
else
	make -s -C $(SOUND) DLL=YES RELEASE=YES
	make -s -C $(SFML) DLL=YES RELEASE=YES
	make -s -C $(LAPIN) DLL=YES RELEASE=YES
	make -s -C $(NDK) DLL=YES RELEASE=YES
	make -s -C $(CENTIPEDE) DLL=YES RELEASE=YES
	make -s -C $(SNAKE) DLL=YES RELEASE=YES
endif

arcade: all lib

clean:
	make -s -C core/ clean

fclean:
	make -s -C core/ fclean

fcleanlib:
	make -s -C $(CENTIPEDE) fclean
	make -s -C $(SFML) fclean
	make -s -C $(LAPIN) fclean
	make -s -C $(NDK) fclean
	make -s -C $(SOUND) fclean
	make -s -C $(SNAKE) fclean

re:	fclean all

.PHONY: make clean fclean re
