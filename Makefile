OBJS := src/main.o
OBJS += src/Codeblock.o
OBJS += src/main.o
OBJS += src/Seg7.o
OBJS += external/tinyxml2/tinyxml2.o

all: aproject.exe

aproject.exe: $(OBJS)
	g++ -o $@ $^

%.o:%.cpp
	g++ -std=c++11 -I./include -c -o $@ $^
