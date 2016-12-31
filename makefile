#
# Makefile for xmas_tree.c
#
CC=gcc
CFLAGS=
SRC_FILES=xmas_tree.c
BIN_FILE=xmastree

xmastree:
	$(CC) $(CFLAGS) $(SRC_FILES) -o $(BIN_FILE)

debug:
	$(CC) -D _DEBUG_ $(CFLAGS) $(SRC_FILES) -o $(BIN_FILE)

all: xmastree

clean:
	rm $(BIN_FILE)

