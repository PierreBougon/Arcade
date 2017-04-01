## Some basic C++ definitions for arcade Makefiles

# MODE

RELEASE	=	NO

# Compilation definitions

CXXFLAGS=	-std=c++14 -W -Wall -Wextra
ifeq ($(RELEASE), YES)
CXXFLAGS+=	-Werror
endif

CXX	=	g++
