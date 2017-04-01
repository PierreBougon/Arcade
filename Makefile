##
## Makefile for  in /home/brout_m/rendu/cpp/cpp_arcade
##
## Made by brout_m
## Login   <marc.brout@epitech.eu>
##
## Started on  Tue Mar 14 18:44:56 2017 brout_m
## Last update Sat Apr  1 17:32:35 2017 bougon_p
##

include mk/colors.mk mk/commands.mk mk/definitions.mk

all:
	@make -s -C core/

clean:
	@make -s -C core/ clean

fclean: clean
	@make -s -C core/ fclean

re:	fclean all

.PHONY: make clean fclean re
