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

# Functions
# ==============================

define build
@ln -s $(WD)/sphinx/variants/$1.rst sphinx/index.rst
@cd doxygen; doxygen Doxyfile-XML
@mkdir -p sphinx/content/unit-tests
@python parse-unit-tests.py > sphinx/content/unit-tests/index.rst
@ln -s $(WD)/../robot/tests/ sphinx/content/system-tests
@export SPHINX_PROJECT_NAME="$(NAME)"; $(MAKE) -C sphinx/ clean html dirhtml latexpdf VERSION=$(VERSION) RELEASE=$(RELEASE)
@rm -f sphinx/content/system-tests
@rm sphinx/index.rst
@mv sphinx/_build sphinx/_build_$1
endef

# Targets
# ==============================
.PHONY: docs doxygen sphinx sphinx-api sphinx-manual sphinx-master sphinx-support sphinx-test-report sphinx-about clean clean-sphinx clean-doxygen

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
	$(call build,api)

sphinx-manual:
	$(call build,manual)

sphinx-master:
	$(call build,master)

sphinx-support:
	$(call build,support)

sphinx-test-report:
	$(call build,test-report)

clean: clean-sphinx clean-doxygen

clean-sphinx:
	@rm -f sphinx/index.rst
	@rm -f sphinx/content/system-tests
	@rm -rf sphinx/_build*
	@rm -rf sphinx/content/unit-tests
	@rm -rf doxygen/xml

clean-doxygen:
	@rm -rf doxygen/build
