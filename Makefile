##
## Makefile for  in /home/brout_m/rendu/cpp/cpp_arcade
##
## Made by brout_m
## Login   <marc.brout@epitech.eu>
##
## Started on  Tue Mar 14 18:44:56 2017 brout_m
## Last update Sun Apr  9 20:06:09 2017 bougon_p
##

include mk/colors.mk mk/commands.mk mk/definitions.mk

BINARY		=	core/

SFML		=	lib/sfml

LAPIN		=	lib/lapin

NDK		=	lib/ndk

SOUND		=	soundManager

CENTIPEDE	=	games/centipede

SNAKE		=	games/snake

all:
	@$(ECHO) "$(BLUE)/=================================\\"
	@$(ECHO) "===========###$(BOLD_WHITE) CORE $(BLUE)###============"
	@$(ECHO) "\=================================/ $(WHITE)"
	@$(ECHO)
	@make -s -C $(BINARY)

lib:	fcleanlib dependencies game libs

dependencies:
	@$(ECHO) "$(BLUE)/=================================\\"
	@$(ECHO) "=======### $(BOLD_WHITE)DEPENDENCIES$(BLUE) ###========"
	@$(ECHO) "\=================================/ $(WHITE)"
	@$(ECHO)
	@make -s -C $(SOUND) STATIC=YES

game:
	@$(ECHO) "$(BLUE)/=================================\\"
	@$(ECHO) "===========### $(WHITE)GAMES$(BLUE) ###==========="
	@$(ECHO) "\=================================/ $(WHITE)"
	@$(ECHO)
	@make -s -C $(SNAKE) DLL=YES
	@make -s -C $(CENTIPEDE) DLL=YES

libs:
	@$(ECHO) "$(BLUE)/=================================\\"
	@$(ECHO) "===========### $(BOLD_WHITE)LIBS $(BLUE)###============"
	@$(ECHO) "\=================================/ $(WHITE)"
	@$(ECHO)
	@make -s -C $(SFML) DLL=YES
	@make -s -C $(LAPIN) DLL=YES
	@make -s -C $(NDK) DLL=YES

arcade: lib

sound:
	@make -s -C $(SOUND) STATIC=YES

sfml:
	@make -s -C $(SFML) DLL=YES

lapin:
	@make -s -C $(LAPIN) DLL=YES

ndk:
	@make -s -C $(NDK) DLL=YES

centipede:
	@make -s -C $(CENTIPEDE) DLL=YES

snake:
	@make -s -C $(SNAKE) DLL=YES

clean:
	@make -s -C core/ clean

fclean:
	@make -s -C core/ fclean

fcleanlib:
	@make -s -C $(CENTIPEDE) fclean
	@make -s -C $(SFML) fclean
	@make -s -C $(LAPIN) fclean
	@make -s -C $(NDK) fclean
	@make -s -C $(SOUND) fclean
	@make -s -C $(SNAKE) fclean

re:	fclean all

.PHONY: make clean fclean re
