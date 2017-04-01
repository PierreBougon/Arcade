## Some basic C++ definitions for arcade Makefiles

# MODE

RELEASE	=	NO

DLL	=	NO

# Compilation definitions

CXXFLAGS	=	-std=c++14 -W -Wall -Wextra
ifeq ($(RELEASE), YES)
CXXFLAGS	+=	-Werror
endif
ifeq ($(DLL), YES)
CXXFLAGS	+=	-fPic
endif

CXX	=	g++

ifeq ($(DLL), YES)
CXX	+=	-shared
endif
