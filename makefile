CC=gcc

CFLAGS=-I.

OUT_DIR=/bin

SERVER_SRC = src/server/%.c
SERVER_OBJ=$(CLIENT_SRC:.c=.o)
SERVER_EXE=$(OUT_DIR)/server.out


all: server.out

server.out: $(SERVER_OBJ)
	$(CC) $? -o $(SERVER_EXE)

%.o: %.c
        $(CC) -c -o $@ $< $(CFLAGS)

clean:
        rm $(SERVER_OBJ) $(SERVER_EXE)
    
