TARGET	=	main
SOURCES =	$(wildcard src/*.c test/*.c)
OBJS	:=	$(patsubst src/%.c test/*.c, %.o, $(SOURCES))

CFLAGS	+=	-std=c99 -Isrc -Itest
CFLAGS 	+= 	-DPROJ_LUA_DC -D__LINUX__
CFLAGS	+=  -ggdb3 -O2
#CFLAGS	+=	-Wall -Wextra
CC		=	gcc

$(TARGET):
	$(CC) $(CFLAGS)  $(SOURCES) -o $@	

.PHONY : clean	 
.PHONY : r

r:
	make clean
	make

clean:
	rm  $(TARGET)	-f
	