CC=gcc 
CFLAGS=-Wall -ansi
OBJ=obj
SRC=src
BIN=bin

all: directories bin/p2p_viewer

directories: ${OBJ} ${BIN} ${LIB}

${OBJ}:
	mkdir ${OBJ}
${BIN}:
	mkdir ${BIN}
${LIB}:
	mkdir ${LIB}
	
bin/p2p_viewer: obj/p2p_viewer.o
	$(CC) -o $@ $^ $(LDFLAGS)

obj/p2p_viewer.o: p2p_viewer.c
	$(CC)  -o $@ -c $^ $(CFLAGS)

clean: 
	rm -rf obj/p2p_viewer.o bin/p2p_viewer
