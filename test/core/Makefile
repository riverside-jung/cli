CC = $(CROSS_COMPILE)gcc
CPP = $(CROSS_COMPILE)g++
AR = $(CROSS_COMPILE)ar rc
LD = $(CROSS_COMPILE)ld
RANLIB = $(CROSS_COMPILE)ranlib
OBJ_DIR = $(CROSS_COMPILE)obj

# locate a main project directory
PROJ_DIR = /home/jay/projects/cli/master

# locate a tool directory
TOOL_DIR = /home/jay/Tools

# locate google test and mock framework  
GMOCK_DIR = $(TOOL_DIR)/gmock/build
GTEST_DIR = $(GMOCK_DIR)/gtest

COPT = -Wall
DEBUG = -g
DEFINE = 
LIB_DIRS = -L$(GMOCK_DIR)/lib
LIBS = -lgmock -lgtest -lpthread

LIBS += -lclicore
LIB_DIRS += -L$(PROJ_DIR)/src/core/obj/lib

INCLUDEDIRS = -I./ -I$(PROJ_DIR)/src/core
INCLUDEDIRS += -I$(GTEST_DIR)/include -I$(GMOCK_DIR)/include

CFLAGS = $(COPT) $(DEBUG) $(INCLUDEDIRS) $(DEFINE)
CPPFLAGS = $(CFLAGS) -std=c++11

OBJS = $(OBJ_DIR)/test_main.o \
       $(OBJ_DIR)/string_utils_test.o \
       $(OBJ_DIR)/json_value_test.o \
       $(OBJ_DIR)/json_number_value_test.o \
       $(OBJ_DIR)/json_string_value_test.o \
       $(OBJ_DIR)/json_object_test.o \
       $(OBJ_DIR)/json_tokenizer_test.o

APP = test

all: $(OBJ_DIR) $(APP)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c -o $@ $<

$(APP): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(APP) $(LIB_DIRS) $(LIBS)

clean:
	rm -f *.o $(APP) $(OBJS) $(LIB_APP)

