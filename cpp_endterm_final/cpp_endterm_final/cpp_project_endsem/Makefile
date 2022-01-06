#OBJS specifies which files to compile as part of the project
# OBJS =  main.cpp game_1.cpp TexHandler.cpp movablemap.cpp Element.cpp Game.cpp GameObject.cpp Player_left.cpp Player_right.cpp TextureManager.cpp Background.cpp
OBJS =  main.cpp  Game.cpp GameObject.cpp Player_left.cpp Player_right.cpp TextureManager.cpp Background.cpp game_1.cpp TexHandler.cpp movablemap.cpp Element.cpp Scoreboard.cpp
#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = main

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
