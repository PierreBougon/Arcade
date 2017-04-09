##
## Makefile for  in /home/brout_m/rendu/cpp/cpp_arcade
##
## Made by brout_m
## Login   <marc.brout@epitech.eu>
##
## Started on  Tue Mar 14 18:44:56 2017 brout_m
## Last update Sun Apr  9 02:39:09 2017 bougon_p
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

arcade: re lib

sound:
ifeq ($(RELEASE), NO)
	make -s -C $(SOUND) DLL=YES
else
	make -s -C $(SOUND) DLL=YES RELEASE=YES
endif

sfml:
ifeq ($(RELEASE), NO)
	make -s -C $(SFML) DLL=YES
else
	make -s -C $(SFML) DLL=YES RELEASE=YES
endif

lapin:
ifeq ($(RELEASE), NO)
	make -s -C $(LAPIN) DLL=YES
else
	make -s -C $(LAPIN) DLL=YES RELEASE=YES
endif

ndk:
ifeq ($(RELEASE), NO)
	make -s -C $(NDK) DLL=YES
else
	make -s -C $(NDK) DLL=YES RELEASE=YES
endif

centipede:
ifeq ($(RELEASE), NO)
	make -s -C $(CENTIPEDE) DLL=YES
else
	make -s -C $(CENTIPEDE) DLL=YES RELEASE=YES
endif

snake:
ifeq ($(RELEASE), NO)
	make -s -C $(SNAKE) DLL=YES
else
	make -s -C $(SNAKE) DLL=YES RELEASE=YES
endif

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
