include ../../mk/colors.mk ../../mk/commands.mk ../../mk/definitions.mk

## Core variables

PROJECT_NAME = Centipede

SRC	=	src/Bullet.cpp	\
		src/Centipede.cpp \
		src/CentipedeGame.cpp \
		src/CentipedeKiller.cpp \
		src/Mushroom.cpp \

INTERFACE_DIR = 	../../interfaces/

INTERFACE_FIL = 	Color.cpp \

SRC += 				$(addprefix $(INTERFACE_DIR), $(INTERFACE_FIL))

COMMON_DIR = 		../common/src/

COMMON_FIL = 		AIControlled.cpp \
		            ALivingEntity.cpp \
		            DestroyableObject.cpp \
		            Entity.cpp \
		            LifelessEntity.cpp \
		            Map.cpp \
		            MapLoader.cpp \
		            Sprite.cpp \
		            SpriteGenerator.cpp \
		            Tile.cpp \
					Gui.cpp

SRC += 				$(addprefix $(COMMON_DIR), $(COMMON_FIL))

OBJ 	=   		$(SRC:.cpp=.o)

NAME    =      		../lib_arcade_centipede.so

INC     =       	-Iinclude \
			-I../../interfaces \
			-I../include \
			-I../common/include \
			-I../../core/include

## Core rules

include ../../mk/rules.mk
