## Some basic C++ definitions for arcade Makefiles

# MODE

DEBUG	=	NO

RELEASE	=	NO

DLL	=	NO

# NAME

PROJECT_NAME	=

# Compilation definitions

CXXFLAGS	=	-std=c++14 -W -Wall -Wextra
ifeq ($(RELEASE), YES)
CXXFLAGS	+=	-Werror
else
ifeq ($(DEBUG), YES)
CXXFLAGS	+=	-D DEBUG
endif
endif
ifeq ($(DLL), YES)
CXXFLAGS	+=	-fPic
endif


CXX	=	g++

LDFLAGS	=

ifeq ($(DLL), YES)
LDFLAGS	+=	-shared
endif
