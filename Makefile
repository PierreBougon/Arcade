##
## Makefile for  in /home/brout_m/rendu/cpp/cpp_arcade
##
## Made by brout_m
## Login   <marc.brout@epitech.eu>
##
## Started on  Tue Mar 14 18:44:56 2017 brout_m
## Last update Tue Mar 14 18:47:35 2017 brout_m
##

ARCADE=		arcade

SRC=

OBJ=		$(SRC:.cpp=.o)

INC=		-I./include/ -I./interfaces/

ifeq ($(DEBUG), yes)
CXXFLAGS=	 -std=c++14 -g -W -Wall -Wextra -Werror $(INC)
else
CXXFLAGS=	 -std=c++14 -W -Wall -Wextra -Werror $(INC)
endif

$(ARCADE): $(OBJ)
	$(CXX) -o $(NANOTEKSPICE) $(OBJMAIN) $(INC) -L./

##
##$(ARCADE): $(OBJ)
##	ar rc $(NANOLIBRARY) $(OBJ)
##	ranlib $(NANOLIBRARY)

all: $(ARCADE)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(ARCADE)

re: fclean all

.PHONY: make clean fclean re
