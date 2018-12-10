CC=gcc
SRC=src

# Includes
INCLUDE_LOCAL=/home/chuck/.local/include
INCLUDE_SDL=/usr/include/SDL2
INCLUDES=-I$(INCLUDE_SDL) -I$(INCLUDE_LOCAL)

# Libs
LOCAL_LIBS=/home/chuck/.local/lib
LIB_LIST=list
LIB_SDL2=SDL2
LIB_SDL_IMAGE=SDL2_image
LIBS=-l$(LIB_SDL2) -l$(LIB_SDL_IMAGE) -l$(LIB_LIST)
LIB_DIRS=-L$(LOCAL_LIBS)

TARGET=bin/spacegame
SOURCES=$(wildcard $(SRC)/**/*.c $(SRC)/*.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

all: build $(TARGET)

CFLAGS=$(INCLUDES) $(LIBS) $(LIB_DIRS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(CFLAGS) -o $@

build:
	@mkdir -p bin

compile_commands:
	bear make

memcheck:
	make && valgrind --leak-check=full --show-reachable=yes --error-limit=no --suppressions=.suppressions/spacegame.supp ./bin/spacegame

gen-suppressions:
	valgrind --leak-check=full --show-reachable=yes --error-limit=no --gen-suppressions=all --log-file=.suppressions/suppresions.log ./bin/spacegame && /home/chuck/.local/scripts/parse_valgrind_suppresions.sh /home/chuck/Projects/spacegame2/.suppressions/suppressions.log > /home/chuck/Projects/spacegame2/.suppressions/spacegame.supp

clean:
	find . -type f -name '*.o' -exec rm {}
	rm -rf bin
