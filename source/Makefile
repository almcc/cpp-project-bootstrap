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
CC_INCLUDES = -Isrc/common/ \
							-Isrc/test/common \
							-I/usr/include/ \
							-I/usr/local/include/
CC_FLAGS = -g -Wall -fPIC
LK_FLAGS =

coverage: CC_FLAGS = -g -Wall -fPIC --coverage
coverage: LK_FLAGS = --coverage

# (Required) Libraries
# ==============================

LIB_INC = -L/usr/lib -L/usr/lib64
SHARED_LIBS =  -lxmlrpc_server_abyss++
STATIC_LIBS =

# Directories
# ==============================

SRC_DIR = src/
SYS_DIR = sys/
OBJ_DIR = obj/
BIN_DIR = bin/
LIB_DIR = lib/
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

APP_OBJS = $(COMMON_OBJS) obj/mains/$(NAME)-main.o
UNITTEST_OBJS = $(COMMON_OBJS) $(TEST_OBJS) obj/mains/unittest-main.o

# Lib
# ==============================

LIB_NAME = Bob
LIB_SO = lib$(LIB_NAME).so
LIB_A = lib$(LIB_NAME).a
LIB_OBJS = $(COMMON_OBJS)

# Targets
# ==============================

.PHONY : new bins libs fresh clean vars cppunit-xml cppunit-txt cppunit cppcheck-xml cppcheck-html cppcheck-txt cppcheck install uninstall dist releasefile coverage

new: bins libs

bins: $(BIN_DIR)$(NAME)

libs: $(LIB_DIR)$(LIB_SO) $(LIB_DIR)$(LIB_A)

fresh: clean new

clean:
	@echo "Cleaning $(OBJ_DIR), $(DST_DIR) $(BIN_DIR) and C.I. result files."
	@rm -rf $(OBJ_DIR)
	@rm -rf $(BIN_DIR)
	@rm -rf $(DST_DIR)
	@rm -rf $(LIB_DIR)
	@rm -f $(CPPUNIT_RESULTS)
	@rm -f $(CPPCHECK_RESULTS)
	@rm -f $(CPPUNIT_RESULTS_TXT)
	@rm -f $(CPPCHECK_RESULTS_TXT)
	@rm -rf cppcheck-results-html/
	@rm -f xunit-results.xml
	@rm -f cppunit-coverage.info
	@rm -rf cppunit-coverage-html


cppunit-xml: $(BIN_DIR)unittest
	@$(BIN_DIR)unittest --xml
	@xsltproc  -o xunit-results.xml ../scripts/cpp2junit.xslt $(CPPUNIT_RESULTS)

cppunit-txt: $(BIN_DIR)unittest
	@$(BIN_DIR)unittest > $(CPPUNIT_RESULTS_TXT)

cppunit: cppunit-txt
	@echo
	@echo "CPP Unit:"
	@cat $(CPPUNIT_RESULTS_TXT)
	@echo

cppcheck-xml:
	@cppcheck --quiet --enable=all --xml --suppress=missingInclude -Isrc/common/ $(SRCS) $(HEADERS) 2> $(CPPCHECK_RESULTS)

cppcheck-html: cppcheck-xml
	../scripts/cppcheck-htmlreport --file=$(CPPCHECK_RESULTS) --report-dir=cppcheck-results-html --source-dir=.

cppcheck-txt:
	@cppcheck --quiet --enable=all --suppress=missingInclude -Isrc/common/ $(SRCS) $(HEADERS) 2> $(CPPCHECK_RESULTS_TXT)

cppcheck: cppcheck-txt
	@echo
	@echo "CPP Check:"
	@cat $(CPPCHECK_RESULTS_TXT)
	@echo

coverage: clean cppunit-xml
	lcov -b . --no-external --capture --directory . --output-file cppunit-coverage.info
	genhtml cppunit-coverage.info --output-directory cppunit-coverage-html

install: bins
	@echo "Installing to $(DESTDIR)"
	mkdir -p $(DESTDIR)/opt/$(NAME)/
	cp -p bin/$(NAME) $(DESTDIR)/opt/$(NAME)/
	mkdir -p $(DESTDIR)/etc/$(NAME)
	cp -p $(SYS_DIR)etc/$(NAME)/* $(DESTDIR)/etc/$(NAME)/
	mkdir -p $(DESTDIR)/etc/init.d/
	cp -p $(SYS_DIR)etc/init.d/$(NAME) $(DESTDIR)/etc/init.d/$(NAME)

uninstall:
	@echo "Uninstalling from $(DESTDIR)"
	rm -rf $(DESTDIR)/opt/$(NAME)/$(NAME)
	rm -rf $(DESTDIR)/etc/$(NAME)
	rm -rf $(DESTDIR)/etc/init.d/$(NAME)

dist:
	@echo "Making distribution"
	@mkdir -p $(DST_DIR)
	@mkdir -p $(RELEASE)/
	@cp -r $(SRC_DIR)/ $(RELEASE)/
	@cp -r $(SYS_DIR)/ $(RELEASE)/
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

# Wrapping Libraries
# ==============================

$(LIB_DIR)$(LIB_SO): $(LIB_OBJS)
	@echo "Wrapping LIB_OBJS into $@"
	@mkdir -p $(LIB_DIR)
	@$(CC) -shared $(LIB_OBJS) -o $@

$(LIB_DIR)$(LIB_A): $(LIB_OBJS)
	@echo "Wrapping LIB_OBJS into $@"
	@mkdir -p $(LIB_DIR)
	@ar rvs $@ $(LIB_OBJS)

# Linking
# ==============================

$(BIN_DIR)$(NAME): $(APP_OBJS) $(OBJ_DIR)mains/$(NAME)-main.o
	@echo "Linking APP_OBJS into $@"
	@mkdir -p $(BIN_DIR)
	@$(CC) $(LK_FLAGS) $(APP_OBJS) $(LIB_INC) -Wl,-Bstatic $(STATIC_LIBS) -Wl,-Bdynamic $(SHARED_LIBS) -Wl,--as-needed -o $@

$(BIN_DIR)unittest: $(UNITTEST_OBJS) $(OBJ_DIR)mains/unittest-main.o
	@echo "Linking UNITTEST_OBJS into $@"
	@mkdir -p $(BIN_DIR)
	@$(CC) $(LK_FLAGS) $(UNITTEST_OBJS) $(LIB_INC) -Wl,-Bstatic $(STATIC_LIBS) -Wl,-Bdynamic $(SHARED_LIBS) -lcppunit -Wl,--as-needed -o $@

# Compiling Mains
# ==============================
# Compiling mains separately as there is no header file for main files.

$(OBJ_DIR)mains/$(NAME)-main.o: $(SRC_DIR)mains/$(NAME)-main.cpp releasefile
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
