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
.PHONY: docs doxygen sphinx sphinx-api sphinx-manual sphinx-master sphinx-support sphinx-test-report sphinx-about clean

docs: clean doxygen sphinx

doxygen:
	@cp doxygen/Doxyfile doxygen/Doxyfile.filled
	@echo "PROJECT_NAME = $(shell echo $(NAME) | tr a-z A-Z)" >> doxygen/Doxyfile.filled
	@echo "PROJECT_NUMBER = $(RELEASE)" >> doxygen/Doxyfile.filled
	@cd doxygen; doxygen Doxyfile.filled
	@$(MAKE) -C doxygen/build/latex all
	@rm -f doxygen/Doxyfile.filled

sphinx: sphinx-api sphinx-manual sphinx-master sphinx-support sphinx-test-report sphinx-about

sphinx-api:
	@ln -s $(WD)/sphinx/variants/api.rst sphinx/index.rst
	@ln -s $(WD)/../robot/tests/ sphinx/content/tests
	@export SPHINX_PROJECT_NAME="$(NAME)"; $(MAKE) -C sphinx/ clean html dirhtml latexpdf VERSION=$(VERSION) RELEASE=$(RELEASE)
	@rm -f sphinx/content/tests
	@rm sphinx/index.rst
	@mv sphinx/_build sphinx/_build_api

sphinx-manual:
	@ln -s $(WD)/sphinx/variants/manual.rst sphinx/index.rst
	@ln -s $(WD)/../robot/tests/ sphinx/content/tests
	@export SPHINX_PROJECT_NAME="$(NAME)"; $(MAKE) -C sphinx/ clean html dirhtml latexpdf VERSION=$(VERSION) RELEASE=$(RELEASE)
	@rm -f sphinx/content/tests
	@rm sphinx/index.rst
	@mv sphinx/_build sphinx/_build_manual

sphinx-master:
	@ln -s $(WD)/sphinx/variants/master.rst sphinx/index.rst
	@ln -s $(WD)/../robot/tests/ sphinx/content/tests
	@export SPHINX_PROJECT_NAME="$(NAME)"; $(MAKE) -C sphinx/ clean html dirhtml latexpdf VERSION=$(VERSION) RELEASE=$(RELEASE)
	@rm -f sphinx/content/tests
	@rm sphinx/index.rst
	@mv sphinx/_build sphinx/_build_master

sphinx-support:
	@ln -s $(WD)/sphinx/variants/support.rst sphinx/index.rst
	@ln -s $(WD)/../robot/tests/ sphinx/content/tests
	@export SPHINX_PROJECT_NAME="$(NAME)"; $(MAKE) -C sphinx/ clean html dirhtml latexpdf VERSION=$(VERSION) RELEASE=$(RELEASE)
	@rm -f sphinx/content/tests
	@rm sphinx/index.rst
	@mv sphinx/_build sphinx/_build_support

sphinx-test-report:
	@ln -s $(WD)/sphinx/variants/test-report.rst sphinx/index.rst
	@ln -s $(WD)/../robot/tests/ sphinx/content/tests
	@export SPHINX_PROJECT_NAME="$(NAME)"; $(MAKE) -C sphinx/ clean html dirhtml latexpdf VERSION=$(VERSION) RELEASE=$(RELEASE)
	@rm -f sphinx/content/tests
	@rm sphinx/index.rst
	@mv sphinx/_build sphinx/_build_test-report


clean:
	@rm -rf doxygen/build
	@rm -rf sphinx/_build*
