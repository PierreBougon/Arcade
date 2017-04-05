include ../../mk/colors.mk ../../mk/commands.mk ../../mk/definitions.mk

## Core variables

SRC	=	src/Snake.cpp	\
		src/PlayerControlSnake.cpp \

INTERFACE_DIR = ../../interfaces/

INTERFACE_FIL = Color.cpp \

SRC += $(addprefix $(INTERFACE_DIR), $(INTERFACE_FIL))

CORE_DIR = ../../core/src/

CORE_FIL = Gui.cpp \

SRC += $(addprefix $(CORE_DIR), $(CORE_FIL))

COMMON_DIR = ../common/src/

COMMON_FIL = AIControlled.cpp \
             ALivingEntity.cpp \
             DestroyableObject.cpp \
             Entity.cpp \
             LifelessEntity.cpp \
             Map.cpp \
             MapLoader.cpp \
             Sprite.cpp \
             SpriteGenerator.cpp \
             Tile.cpp

SRC += $(addprefix $(COMMON_DIR), $(COMMON_FIL))

OBJ 	=   	$(SRC:.cpp=.o)

NAME    =      	../../libarcade_snake.so

INC     =       -Iinclude -I../../interfaces -I../include -I../common/include -I../../core/include

## Core rules

include ../../mk/rules.mk
