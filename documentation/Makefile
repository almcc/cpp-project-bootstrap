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

# Helpers
# ==============================
WD=$(shell pwd)

# Targets
# ==============================
.PHONY: docs doxygen sphinx clean

docs: clean doxygen sphinx

doxygen:
	@cp doxygen/Doxyfile doxygen/Doxyfile.filled
	@echo "PROJECT_NAME = $(shell echo $(NAME) | tr a-z A-Z)" >> doxygen/Doxyfile.filled
	@echo "PROJECT_NUMBER = $(RELEASE)" >> doxygen/Doxyfile.filled
	@cd doxygen; doxygen Doxyfile.filled
	@$(MAKE) -C doxygen/build/latex all
	@rm -f doxygen/Doxyfile.filled

sphinx:
	@export SPHINX_PROJECT_NAME="$(NAME)"; $(MAKE) -C sphinx/ clean html dirhtml latexpdf VERSION=$(VERSION) RELEASE=$(RELEASE)

clean:
	@rm -rf doxygen/build
	@rm -rf sphinx/_build
