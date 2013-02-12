# Full paths to executables.
# ==============================

CPPCHECK = /usr/local/bin/cppcheck

# Compiler Settings
# ==============================

CC = g++
CC_INCLUDES = -Isrc/common/ -I/usr/local/include/ -Isrc/test/common
CC_FLAGS = -g -Wall

# Directories
# ==============================

SRC_DIR = src/
OBJ_DIR = obj/
BIN_DIR = bin/

VPATH = $(SRC_DIR)

# All sources and objects
# ==============================

HEADERS = $(shell for file in `find src -name *.h`; do echo $$file; done)
SRCS = $(shell for file in `find src -name *.cpp`; do echo $$file; done)
OBJS = $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SRCS:.cpp=.o))

# Objects per directory
# ==============================

COMMON_SRCS = $(shell for file in `find src/common -name *.cpp`; do echo $$file; done)
COMMON_OBJS = $(patsubst src/common%,obj/common%,$(COMMON_SRCS:.cpp=.o))

TEST_SRCS = $(shell for file in `find src/test -name *.cpp`; do echo $$file; done)
TEST_OBJS = $(patsubst src/test%,obj/test%,$(TEST_SRCS:.cpp=.o))

# Bin specific Objects
# ==============================

PRIMARY_OBJS = $(COMMON_OBJS) obj/mains/primary-main.o
UNITTEST_OBJS = $(COMMON_OBJS) $(TEST_OBJS) obj/mains/unittest-main.o

# Targets
# ==============================

.PHONY : new fresh clean vars test cppcheck

new: $(BIN_DIR)primary

fresh: clean new

clean:
	@echo "Cleaning $(OBJ_DIR), $(BIN_DIR) and C.I. result files."
	@rm -rf $(OBJ_DIR)
	@rm -rf $(BIN_DIR)
	@rm -f cppunit-test-results.xml
	@rm -f cppcheck-result.xml

vars:
	@echo "SRCS:"
	@echo "  $(SRCS)"
	@echo "OBJS:"
	@echo "  $(OBJS)"
	@echo "COMMON_OBJS:"
	@echo "  $(COMMON_OBJS)"
	@echo "TEST_OBJS:"
	@echo "  $(TEST_OBJS)"
	@echo "PRIMARY_OBJS:"
	@echo "  $(PRIMARY_OBJS)"
	@echo "UNITTEST_OBJS:"
	@echo "  $(UNITTEST_OBJS)"

test: $(BIN_DIR)unittest

cppcheck:
	@rm -f cppcheck-result.xml
	@$(CPPCHECK) --quiet --enable=all --xml --suppress=missingInclude -Isrc/common/ $(SRCS) $(HEADERS) 2> cppcheck-result.xml

# Linking
# ==============================

$(BIN_DIR)primary: $(PRIMARY_OBJS)
	@echo "Linking PRIMARY_OBJS into $@"
	@mkdir -p $(BIN_DIR)
	@$(CC) $(PRIMARY_OBJS) -o $@

$(BIN_DIR)unittest: $(UNITTEST_OBJS)
	@echo "Linking UNITTEST_OBJS into $@"
	@mkdir -p $(BIN_DIR)
	@$(CC) $(UNITTEST_OBJS) -lcppunit -o $@

# Compiling Mains
# ==============================
# Compiling mains separately as there is no header file for main files.

$(OBJ_DIR)mains/primary-main.o: $(SRC_DIR)mains/primary-main.cpp
	@echo "Compling $< into $@"
	@mkdir -p $(dir $@)
	@$(CC) $(CC_FLAGS) $(CC_INCLUDES) -c $< -o $@

$(OBJ_DIR)mains/unittest-main.o: $(SRC_DIR)mains/unittest-main.cpp
	@echo "Compling $< into $@"
	@mkdir -p $(dir $@)
	@$(CC) $(CC_FLAGS) $(CC_INCLUDES) -c $< -o $@

# Compiling Standard Classes
# ==============================
# Compiling section, using VPATH = $(SRC_DIR) to allow different obj and src dirs.

$(OBJ_DIR)%.o: %.cpp %.h
	@echo "Compling $< into $@"
	@mkdir -p $(dir $@)
	@$(CC) $(CC_FLAGS) $(CC_INCLUDES) -c $< -o $@





