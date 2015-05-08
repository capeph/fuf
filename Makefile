# Makefile

CC:=g++
CFLAGS:=-std=c++11

ODIR=obj
TARGET=fuf
TEST_TARGET=fuf_test
allmatching = $(shell find $(1) -name '$(2)')
APP_ALL_S:=$(call allmatching,src,*.cpp) 
APP_MAIN_S:=src/main.cpp
APP_LOGIC_S:=$(filter-out $(APP_MAIN_S),$(APP_ALL_S))
APP_MAIN_O:=$(APP_MAIN_S:.cpp=.o)
APP_LOGIC_O:=$(APP_LOGIC_S:.cpp=.o)
TEST_ALL_S:=$(call allmatching,test,*.cpp)
TEST_ALL_O:=$(TEST_ALL_S:.cpp=.o)

silly:
	@echo "Choose target among clean|app|tests|test|all"

.cpp.o:
	$(CC) $(CFLAGS) -c $< -o $@ -Isrc

clean:
	@rm -fv $(APP_MAIN_O) $(APP_LOGIC_O) $(TEST_ALL_O) $(TARGET) $(TEST_TARGET)

app: $(APP_LOGIC_O) $(APP_MAIN_O)  
	$(CC) $(CFLAGS) $^ -o $(TARGET)

tests: $(APP_LOGIC_O) $(TEST_ALL_O)
	$(CC) $(CFLAGS) $^ -o $(TEST_TARGET)

test: tests
	./$(TEST_TARGET)

all: app test

