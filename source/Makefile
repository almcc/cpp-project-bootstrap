# Release Settings
# ==============================
NAME = app
MAJOR = 0
MINOR = 1
FIX = 0

VERSION = $(MAJOR).$(MINOR).$(FIX)


# Output Files
# ==============================

CPPCHECK_RESULTS = cppcheck-results.xml
CPPUNIT_RESULTS = cppunit-results.xml

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
DST_DIR = dist/

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

APP_OBJS = $(COMMON_OBJS) obj/mains/app-main.o
UNITTEST_OBJS = $(COMMON_OBJS) $(TEST_OBJS) obj/mains/unittest-main.o

# Targets
# ==============================

.PHONY : new fresh clean vars cppunit-xml cppunit cppcheck-xml cppcheck ci-xml install uninstall dist

new: $(BIN_DIR)app

fresh: clean new

clean:
	@echo "Cleaning $(OBJ_DIR), $(DST_DIR) $(BIN_DIR) and C.I. result files."
	@rm -rf $(OBJ_DIR)
	@rm -rf $(BIN_DIR)
	@rm -rf $(DST_DIR)
	@rm -f $(CPPUNIT_RESULTS)
	@rm -f $(CPPCHECK_RESULTS)

cppunit-xml: $(BIN_DIR)unittest
	@$(BIN_DIR)unittest --xml

cppunit: $(BIN_DIR)unittest
	@$(BIN_DIR)unittest

cppcheck-xml:
	@rm -f $(CPPCHECK_RESULTS)
	@cppcheck --quiet --enable=all --xml --suppress=missingInclude -Isrc/common/ $(SRCS) $(HEADERS) 2> $(CPPCHECK_RESULTS)

cppcheck:
	@rm -f $(CPPCHECK_RESULTS)
	@cppcheck --quiet --enable=all --suppress=missingInclude -Isrc/common/ $(SRCS) $(HEADERS)

ci-xml: fresh cppunit-xml cppcheck-xml

ci: fresh cppunit cppcheck

install:
	@echo "Installing to $(DESTDIR)"
	mkdir -p $(DESTDIR)/usr/local/bin/
	cp bin/app $(DESTDIR)/usr/local/bin/

uninstall:
	@echo "Uninstalling from $(DESTDIR)"
	rm -rf $(DESTDIR)/usr/local/bin/app

dist:
	@echo "Making distribution"
	@mkdir -p $(DST_DIR)
	@mkdir -p $(NAME)-$(VERSION)/
	@cp -r src/ $(NAME)-$(VERSION)/
	@cp -r Makefile $(NAME)-$(VERSION)/
	@tar cvzf $(DST_DIR)/$(NAME)-$(VERSION).tar.gz $(NAME)-$(VERSION)/*
	@rm -rf $(NAME)-$(VERSION)/


# Linking
# ==============================

$(BIN_DIR)app: $(APP_OBJS) $(OBJ_DIR)mains/app-main.o
	@echo "Linking APP_OBJS into $@"
	@mkdir -p $(BIN_DIR)
	@$(CC) $(APP_OBJS) -o $@

$(BIN_DIR)unittest: $(UNITTEST_OBJS) $(OBJ_DIR)mains/unittest-main.o
	@echo "Linking UNITTEST_OBJS into $@"
	@mkdir -p $(BIN_DIR)
	@$(CC) $(UNITTEST_OBJS) -lcppunit -o $@

# Compiling Mains
# ==============================
# Compiling mains separately as there is no header file for main files.

$(OBJ_DIR)mains/app-main.o: $(SRC_DIR)mains/app-main.cpp
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





