# Release Settings
# ==============================
NAME = app
MAJOR = X
MINOR = X
FIX = X
LABEL = dev
BUILD = X
VERSION = $(MAJOR).$(MINOR).$(FIX)
RELEASE = $(NAME)-$(VERSION)-$(LABEL)$(BUILD)

# Output Files
# ==============================

CPPCHECK_RESULTS = cppcheck-results.xml
CPPUNIT_RESULTS = cppunit-results.xml
CPPCHECK_RESULTS_TXT = cppcheck-results.txt
CPPUNIT_RESULTS_TXT = cppunit-results.txt

# Compiler Settings
# ==============================

CC = g++
CC_INCLUDES = -Isrc/common/ -Isrc/test/common -I/usr/local/include/ -I/usr/include/
CC_FLAGS = -g -Wall

# Libraries
# ==============================

LIBS = -l xmlrpc_server_abyss++

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

.PHONY : new fresh clean vars cppunit-xml cppunit-txt cppunit cppcheck-xml cppcheck-txt cppcheck ci ci-xml ci-txt install uninstall dist releasefile

new: $(BIN_DIR)app

fresh: clean new

clean:
	@echo "Cleaning $(OBJ_DIR), $(DST_DIR) $(BIN_DIR) and C.I. result files."
	@rm -rf $(OBJ_DIR)
	@rm -rf $(BIN_DIR)
	@rm -rf $(DST_DIR)
	@rm -f $(CPPUNIT_RESULTS)
	@rm -f $(CPPCHECK_RESULTS)
	@rm -f $(CPPUNIT_RESULTS_TXT)
	@rm -f $(CPPCHECK_RESULTS_TXT)

cppunit-xml: $(BIN_DIR)unittest
	@$(BIN_DIR)unittest --xml

cppunit-txt: $(BIN_DIR)unittest
	@$(BIN_DIR)unittest > $(CPPUNIT_RESULTS_TXT)

cppunit: cppunit-txt
	@echo
	@echo "CPP Unit:"
	@cat $(CPPUNIT_RESULTS_TXT)
	@echo

cppcheck-xml:
	@cppcheck --quiet --enable=all --xml --suppress=missingInclude -Isrc/common/ $(SRCS) $(HEADERS) 2> $(CPPCHECK_RESULTS)

cppcheck-txt:
	@cppcheck --quiet --enable=all --suppress=missingInclude -Isrc/common/ $(SRCS) $(HEADERS) 2> $(CPPCHECK_RESULTS_TXT)

cppcheck: cppcheck-txt
	@echo
	@echo "CPP Check:"
	@cat $(CPPCHECK_RESULTS_TXT)
	@echo

ci-txt: fresh cppunit-txt cppcheck-txt

ci-xml: fresh cppunit-xml cppcheck-xml

ci: fresh cppunit cppcheck

install:
	@echo "Installing to $(DESTDIR)"
	mkdir -p $(DESTDIR)/usr/local/bin/
	cp bin/app $(DESTDIR)/usr/local/bin/
	mkdir -p $(DESTDIR)/etc/app
	cp system/etc/app/* /etc/app/

uninstall:
	@echo "Uninstalling from $(DESTDIR)"
	rm -rf $(DESTDIR)/usr/local/bin/app
	rm -rf $(DESTDIR)/etc/app

dist:
	@echo "Making distribution"
	@mkdir -p $(DST_DIR)
	@mkdir -p $(RELEASE)/
	@cp -r $(SRC_DIR)/ $(RELEASE)/
	@cp -r Makefile $(RELEASE)/
	@tar cvzf $(DST_DIR)/$(RELEASE)-dist.tar.gz $(RELEASE)/*
	@rm -rf $(RELEASE)/

# Making release header file
# ==============================
releasefile:
	@echo '#ifndef Release_H' > $(SRC_DIR)/common/Release.h
	@echo '#define Release_H' >> $(SRC_DIR)/common/Release.h
	@echo '' >> $(SRC_DIR)/common/Release.h
	@echo '#include <string>' >> $(SRC_DIR)/common/Release.h
	@echo '' >> $(SRC_DIR)/common/Release.h
	@echo 'const std::string NAME = "$(NAME)";' >> $(SRC_DIR)/common/Release.h
	@echo 'const std::string MAJOR = "$(MAJOR)";' >> $(SRC_DIR)/common/Release.h
	@echo 'const std::string MINOR = "$(MINOR)";' >> $(SRC_DIR)/common/Release.h
	@echo 'const std::string FIX = "$(FIX)";' >> $(SRC_DIR)/common/Release.h
	@echo 'const std::string LABEL = "$(LABEL)";' >> $(SRC_DIR)/common/Release.h
	@echo 'const std::string BUILD = "$(BUILD)";' >> $(SRC_DIR)/common/Release.h
	@echo 'const std::string VERSION = "$(VERSION)";' >> $(SRC_DIR)/common/Release.h
	@echo 'const std::string RELEASE = "$(RELEASE)";' >> $(SRC_DIR)/common/Release.h
	@echo '' >> $(SRC_DIR)/common/Release.h
	@echo '#endif' >> $(SRC_DIR)/common/Release.h


# Linking
# ==============================

$(BIN_DIR)app: $(APP_OBJS) $(OBJ_DIR)mains/app-main.o
	@echo "Linking APP_OBJS into $@"
	@mkdir -p $(BIN_DIR)
	@$(CC) $(APP_OBJS) $(LIBS) -o $@

$(BIN_DIR)unittest: $(UNITTEST_OBJS) $(OBJ_DIR)mains/unittest-main.o
	@echo "Linking UNITTEST_OBJS into $@"
	@mkdir -p $(BIN_DIR)
	@$(CC) $(UNITTEST_OBJS) $(LIBS) -lcppunit -o $@

# Compiling Mains
# ==============================
# Compiling mains separately as there is no header file for main files.

$(OBJ_DIR)mains/app-main.o: $(SRC_DIR)mains/app-main.cpp releasefile
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





