CC=g++

GL_INC_DIR=/usr/include
GL_LIB_DIR=/usr/lib

GL_LIBS=-L$(GL_LIB_DIR) -lglut -lGLU -lGL -lm -lpthread

CFLAGS = -Wall 
# -dNDEBUG

.PHONY:clean

OBJ = main.o GridStag.o Renderer.o FluidSim.o Printer.o Particles.o helper.o
LIBS = $(GL_LIBS)

all: $(OBJ) liquid2D

$(OBJ): %.o : %.cpp
	$(CC) -c $(CFLAGS)  $< -o $@ -fopenmp

#-Wno-write-strings : to ignore warning related to deprecated conversion from const char* to char*
liquid2D: $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $@ -fopenmp

clean:
	rm -f  ./*~ ./core $(OBJ) liquid2D

#DEPENDENCIES- DO NOT DELETE
GridStag.o : GridStag.h ParameterFLAGS.hpp
Renderer.o : Renderer.h
FluidSim.o : FluidSim.h ./pcgsolver/*.h ParameterFLAGS.hpp helper.h
main.o : main.h commonData.h ParameterFLAGS.hpp
Printer.o : Printer.h
Particles.o : Particles.h

