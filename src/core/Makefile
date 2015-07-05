CC = $(CROSS_COMPILE)gcc
CPP = $(CROSS_COMPILE)g++
AR = $(CROSS_COMPILE)ar rc
LD = $(CROSS_COMPILE)ld
RANLIB = $(CROSS_COMPILE)ranlib
OBJ_DIR = $(CROSS_COMPILE)obj

COPT = -Wall
DEBUG = -g
DEFINE = 
LIB_DIRS = -L.
LIBS = -lm -ldl -lrt -lpthread

INCLUDEDIRS = -I./ -I../

CFLAGS = $(COPT) $(DEBUG) $(INCLUDEDIRS) $(DEFINE)
#CPPFLAGS = $(CFLAGS) -std=c++0x
CPPFLAGS = $(CFLAGS) -std=c++11

OBJS = 
APP_LIB =

OBJS_LIB = $(OBJ_DIR)/json_object.o
APP_LIB = $(OBJ_DIR)/lib/libclicore.a

all: $(OBJ_DIR) $(APP_LIB)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c -o $@ $<

$(APP): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(APP) $(LIB_DIRS) $(LIBS)

$(APP_LIB): $(OBJS_LIB)
	$(AR) $(APP_LIB) $(OBJS_LIB)
	$(RANLIB) $(APP_LIB)

clean:
	rm -f *.o $(APP) $(OBJS) $(OBJS_LIB) $(APP_LIB)

